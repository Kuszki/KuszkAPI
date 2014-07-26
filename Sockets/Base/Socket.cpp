using namespace KuszkAPI;

unsigned KuszkAPI::Sockets::Socket::uIlosc = 0;

KuszkAPI::Sockets::Socket::Socket(void)
{
     if (!uIlosc++) Start();

     memset(&sAdres, 0, sizeof(sockaddr_in));

     sSocket = 0;
     hHandler = 0;
}

KuszkAPI::Sockets::Socket::~Socket(void)
{
     if (sSocket) closesocket(sSocket);
     if (hHandler) DestroyWindow(hHandler);

     if (!--uIlosc) Stop();
}

void KuszkAPI::Sockets::Socket::Start(unsigned short uMain, unsigned short uSub)
{
     WSADATA wData;
     WSAStartup(MAKEWORD(uMain, uSub), &wData);
}

void KuszkAPI::Sockets::Socket::Stop(void)
{
     WSACleanup();

     UnregisterClass("SOCKET", GetModuleHandle(NULL));
}
