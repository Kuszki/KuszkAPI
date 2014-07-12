using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Sockets)

// ---- CLASES DECLARATIONS -----
class Server;
// ------------------------------

// ---- SERVER DECLARATIONS -----
class Server : Socket
{
      public:
              Containers::Map<Client, SOCKET> Clients;
              Server(void);
              bool Listen(unsigned short uPort,
                          HWND hWnd);
              void Shutdown(void);
              SOCKET Accept(void);
              void Disconnect(SOCKET sClient);
              unsigned Capacity(void) const;
              template<typename tnData> void Announce(const Containers::Array<tnData>& aBufor,
                                                      unsigned uHeader = 0);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
