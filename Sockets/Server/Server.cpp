using namespace KuszkAPI;

bool KuszkAPI::Sockets::Server::bClassRegistered = false;

KuszkAPI::Sockets::Server::Server(void)
{
	Register();

	hHandler = CreateWindow(TEXT("SOCKET_SERVER"), NULL, 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);
}

bool KuszkAPI::Sockets::Server::Register(void)
{
     if (bClassRegistered) return true;

     WNDCLASS cClass;

     TCHAR pcName[] = TEXT("SOCKET_SERVER");

     memset(&cClass, 0, sizeof(cClass));

     cClass.hInstance = GetModuleHandle(NULL);
     cClass.cbWndExtra = 2 * sizeof(int);
     cClass.lpfnWndProc = Sockets::ServerHandlerProc;
     cClass.lpszClassName = pcName;

     bClassRegistered = RegisterClass(&cClass);

     return bClassRegistered;
}

bool KuszkAPI::Sockets::Server::Listen(unsigned short uPort, HWND hWnd)
{
     Shutdown();

     sSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     sAdres.sin_family = AF_INET;
     sAdres.sin_addr.s_addr = INADDR_ANY;
     sAdres.sin_port = htons(uPort);

     if (bind(sSocket, (sockaddr*) &sAdres, sizeof(sockaddr_in))) return false;
     if (listen(sSocket, SOMAXCONN)) return false;

     if (WSAAsyncSelect(sSocket, hWnd, WM_SOCKET, FD_READ | FD_WRITE | FD_ACCEPT | FD_CLOSE)) return false;

     return true;
}

bool KuszkAPI::Sockets::Server::Listen(unsigned short uPort, ServerProc fProc)
{
     if (!bClassRegistered || !hHandler) return false;

     SetWindowLong(hHandler, 0, (LONG) this);
     SetWindowLong(hHandler, 4, (LONG) fProc);

     return Listen(uPort, hHandler);
}

void KuszkAPI::Sockets::Server::Shutdown(void)
{
     if (sSocket){
          Clients.Clean();
          memset(&sAdres, 0, sizeof(sockaddr_in));
          closesocket(sSocket);
          sSocket = 0;
     }
}

SOCKET KuszkAPI::Sockets::Server::Accept(void)
{
     if (!sSocket) return false;

     sockaddr_in sTmpAdr;

     int iTmp = sizeof(sockaddr_in);
     memset(&sTmpAdr, 0, iTmp);

     SOCKET sTmpSock = accept(sSocket, (sockaddr*) &sTmpAdr, &iTmp);

     if (sTmpSock != INVALID_SOCKET) Clients.Add(new Client(sTmpSock, sTmpAdr), sTmpSock); else return false;

     return sTmpSock;
}

void KuszkAPI::Sockets::Server::Disconnect(SOCKET sClient)
{
     Clients.Delete(sClient);
}

unsigned KuszkAPI::Sockets::Server::Capacity(void) const
{
     return Clients.Capacity();
}

template<typename tnData>
void KuszkAPI::Sockets::Server::Announce(const Containers::Array<tnData>& aBufor, unsigned uHeader)
{
     for (int i = 1; i <= Clients.Capacity(); i++) Clients.GetDataByInt(i).Send(aBufor, uHeader);
}

LRESULT CALLBACK KuszkAPI::Sockets::ServerHandlerProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     Sockets::Server* psServer = (Sockets::Server*) GetWindowLong(hWnd, 0);
     Sockets::Server::ServerProc fProc = (Sockets::Server::ServerProc) GetWindowLong(hWnd, 4);

     switch (uMsg){
          case WM_SOCKET:
               switch (WSAGETSELECTEVENT(lParam)){
                    case FD_ACCEPT:

                         wParam = psServer->Accept();

                         return fProc(psServer, FD_ACCEPT, wParam);

                    break;
                    case FD_READ:

                         return fProc(psServer, FD_READ, wParam);

                    break;
                    case FD_CLOSE:

                         psServer->Disconnect(wParam);

                         return fProc(psServer, FD_CLOSE, wParam);

                    break;
               }
          break;

          default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}
