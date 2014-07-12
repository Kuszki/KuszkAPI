using namespace KuszkAPI;

KuszkAPI::Sockets::Server::Server(void) {}

bool KuszkAPI::Sockets::Server::Listen(unsigned short uPort, HWND hWnd)
{
      sSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      sAdres.sin_family = AF_INET;
      sAdres.sin_addr.s_addr = INADDR_ANY;
      sAdres.sin_port = htons(uPort);
      if (bind(sSocket, (sockaddr*) &sAdres, sizeof(sockaddr_in))) return false;
      if (listen(sSocket, SOMAXCONN)) return false;
      if (WSAAsyncSelect(sSocket, hWnd, WM_SOCKET, FD_READ | FD_WRITE | FD_ACCEPT | FD_CLOSE)) return false;
      return true;
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
      sockaddr_in sTmpAdr;
      int iTmp = sizeof(sockaddr_in);
      SOCKET sTmpSock = accept(sSocket, (sockaddr*) &sTmpAdr, &iTmp);
      Client* pClient = new Client(sTmpSock, sTmpAdr);
      if (sTmpSock != INVALID_SOCKET) Clients.Add(pClient, sTmpSock); else return false;
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
