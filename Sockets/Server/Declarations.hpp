using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Sockets)

// ---- CLASES DECLARATIONS -----
class Server;
// ------------------------------

// ---- SERVER DECLARATIONS -----
class Server : public Socket
{

     protected:

          static bool bClassRegistered;

          static bool Register(void);

     public:

          typedef LRESULT (*ServerProc)(Server*, UINT, SOCKET);

          Containers::Map<Client, SOCKET> Clients;

          Server(void);

          bool Listen(unsigned short uPort,
                      HWND hWnd);
          bool Listen(unsigned short uPort,
                      ServerProc fProc);
          void Shutdown(void);
          SOCKET Accept(void);
          void Disconnect(SOCKET sClient);
          unsigned Capacity(void) const;

          template<typename tnData> void Announce(const Containers::Array<tnData>& aBufor,
                                                  unsigned uHeader = 0);

};
// ------------------------------

// --- FUNCTIONS DECLARATIONS ---
LRESULT CALLBACK ServerHandlerProc(HWND, UINT, WPARAM, LPARAM);
// ------------------------------

KUSZKAPI_NAMESPACE_END
