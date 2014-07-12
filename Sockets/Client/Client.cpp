using namespace KuszkAPI;

KuszkAPI::Sockets::Client::Client(SOCKET sSock, sockaddr_in sAdr)
{
      sSocket = sSock;
      sAdres = sAdr;
      uSize = 1024;
}

KuszkAPI::Sockets::Client::Client(void)
{
      uSize = 1024;
}

bool KuszkAPI::Sockets::Client::Connect(const Containers::String& sServer, unsigned short uPort, HWND hWnd)
{
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

Containers::String KuszkAPI::Sockets::Client::GetAdress(void) const
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
      send(sSocket, sMessage.Str(), sMessage.Capacity() + 1, 0);
      return *this;
}

Sockets::Client& KuszkAPI::Sockets::Client::operator>> (Containers::String& sMessage)
{
      char* pcBufor = new char[uSize];
      unsigned uTmp = recv(sSocket, pcBufor, uSize, 0);
      pcBufor[uTmp] = 0;
      sMessage = pcBufor;
      delete [] pcBufor;
      return *this;
}
