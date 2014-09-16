using namespace KuszkAPI;

unsigned KuszkAPI::Sockets::Client::uSize = 1024;
bool KuszkAPI::Sockets::Client::bClassRegistered = false;

KuszkAPI::Sockets::Client::Client(SOCKET sSock, const sockaddr_in& sAdr)
{
     sSocket = sSock;
     memcpy(&sAdres, &sAdr, sizeof(sockaddr_in));
}

KuszkAPI::Sockets::Client::Client(void) {}

bool KuszkAPI::Sockets::Client::Register(void)
{
     if (bClassRegistered) return true;

     WNDCLASS cClass;

     TCHAR pcName[] = TEXT("SOCKET_CLIENT");

     memset(&cClass, 0, sizeof(cClass));

     cClass.hInstance = GetModuleHandle(NULL);
     cClass.cbWndExtra = 2 * sizeof(int);
     cClass.lpfnWndProc = Sockets::ClientHandlerProc;
     cClass.lpszClassName = pcName;

     bClassRegistered = RegisterClass(&cClass);

     return bClassRegistered;
}

bool KuszkAPI::Sockets::Client::Connect(const Containers::String& sServer, unsigned short uPort, HWND hWnd)
{
     Disconnect();

     sSocket = socket(AF_INET, SOCK_STREAM, 0);
     hostent* hHost = gethostbyname(sServer.Ascii());

     sAdres.sin_family = AF_INET;
     sAdres.sin_addr.s_addr = ((in_addr*) (hHost->h_addr))->s_addr;
     sAdres.sin_port = htons(uPort);

     if (connect(sSocket, (sockaddr*) &sAdres, sizeof(sockaddr_in))){
          closesocket(sSocket);
          sSocket = 0;
          return false;
     }

     WSAAsyncSelect(sSocket, hWnd, WM_SOCKET, FD_READ | FD_WRITE | FD_CLOSE);

     return true;
}

bool KuszkAPI::Sockets::Client::Connect(const Containers::String& sServer, unsigned short uPort, ClientProc fProc)
{
     if (!Register()) return false;

     if (!hHandler) hHandler = CreateWindow(TEXT("SOCKET_CLIENT"), NULL, 0, 0, 0, 0, 0, NULL, NULL, GetModuleHandle(NULL), NULL);

     if (!hHandler) return false;

     SetWindowLong(hHandler, 0, (LONG) this);
     SetWindowLong(hHandler, 4, (LONG) fProc);

     return Connect(sServer, uPort, hHandler);
}

void KuszkAPI::Sockets::Client::Disconnect(void)
{
     if (sSocket){
          memset(&sAdres, 0, sizeof(sockaddr_in));
          closesocket(sSocket);
          sSocket = 0;
     }
}

bool KuszkAPI::Sockets::Client::Connected(void) const
{
     return (bool) sSocket;
}

Containers::String KuszkAPI::Sockets::Client::GetAddress(void) const
{
     return inet_ntoa(sAdres.sin_addr);
}

template<typename tnData>
unsigned KuszkAPI::Sockets::Client::Send(const Containers::Array<tnData>& aBufor, unsigned uHeader)
{
     if (!sSocket) return 0;

     unsigned uTmp = aBufor.Capacity() * sizeof(tnData);

     if (uHeader) uTmp += sizeof(unsigned);

     char* pcBufor = new char[uTmp];

     if (uHeader){
          memcpy(pcBufor, &uHeader, sizeof(unsigned));
          memcpy(pcBufor + sizeof(unsigned), aBufor.GetBegin(), uTmp - sizeof(unsigned));
     } else memcpy(pcBufor, aBufor.GetBegin(), uTmp);

     uTmp = send(sSocket, pcBufor, uTmp, 0);

     delete [] pcBufor;

     return uTmp;
}

template<typename tnData>
unsigned KuszkAPI::Sockets::Client::Recv(Containers::Array<tnData>& aBufor, unsigned& uHeader)
{
     if (!sSocket) return 0;

     aBufor.Clean();

     char* pcBufor = new char[uSize];
     unsigned uTmp = recv(sSocket, pcBufor, uSize, 0);

     aBufor.Add((tnData*) (pcBufor + sizeof(unsigned)), (uTmp - sizeof(unsigned)) / sizeof(tnData));

     uHeader = *(unsigned*) pcBufor;

     delete [] pcBufor;

     return uTmp;
}

template<typename tnData>
unsigned KuszkAPI::Sockets::Client::Recv(Containers::Array<tnData>& aBufor)
{
     if (!sSocket) return 0;

     aBufor.Clean();

     char* pcBufor = new char[uSize];
     unsigned uTmp = recv(sSocket, pcBufor, uSize, 0);

     aBufor.Add((tnData*) pcBufor, uTmp / sizeof(tnData));

     delete [] pcBufor;

     return uTmp;
}

Sockets::Client& KuszkAPI::Sockets::Client::operator<< (const Containers::String& sMessage)
{
     send(sSocket, (char*) sMessage.Str(), (sMessage.Capacity() + 1) * sizeof(TCHAR), 0);

     return *this;
}

Sockets::Client& KuszkAPI::Sockets::Client::operator>> (Containers::String& sMessage)
{
     char* pcBufor = new char[uSize];
     unsigned uTmp = recv(sSocket, pcBufor, uSize, 0);

     pcBufor[uTmp] = 0;

     sMessage.Add(pcBufor);

     delete [] pcBufor;

     return *this;
}

LRESULT CALLBACK KuszkAPI::Sockets::ClientHandlerProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     Sockets::Client* pcClient = (Sockets::Client*) GetWindowLong(hWnd, 0);
     Sockets::Client::ClientProc fProc = (Sockets::Client::ClientProc) GetWindowLong(hWnd, 4);

     LRESULT rCode = 0;

     switch (uMsg){
          case WM_SOCKET:
               switch (WSAGETSELECTEVENT(lParam)){
                    case FD_CONNECT:

                         rCode = fProc(*pcClient, FD_CONNECT);

                    break;
                    case FD_READ:

                         rCode = fProc(*pcClient, FD_READ);

                    break;
                    case FD_CLOSE:

                         rCode = fProc(*pcClient, FD_CLOSE);

                         pcClient->Disconnect();

                    break;
               }
          break;

          default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}
