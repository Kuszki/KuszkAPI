using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Sockets)

// --- FUNCTIONS DECLARATIONS ---
LRESULT CALLBACK ServerHandlerProc(HWND, UINT, WPARAM, LPARAM);
// ------------------------------

// ---- CLASES DECLARATIONS -----
class Server;
// ------------------------------

// ---- SERVER DECLARATIONS -----
class Server : public Socket
{

     protected:

          typedef LRESULT (*ServerProc)(Server&, UINT, SOCKET);

          static bool bClassRegistered;

          static bool Register(void);

          Containers::Map<Client, SOCKET> mClients;

     public:

          Server(void);

          bool Listen(unsigned short uPort,
                      HWND hWnd);
          bool Listen(unsigned short uPort,
                      ServerProc fProc);
          void Shutdown(void);
          SOCKET Accept(void);
          void Disconnect(SOCKET sClient);
          unsigned Capacity(void) const;

          Client& GetClient(unsigned uClient);

		Client& operator[] (SOCKET sClient);

          template<typename tnData> void Announce(const Containers::Array<tnData>& aBufor,
                                                  unsigned uHeader = 0);

          friend LRESULT CALLBACK ServerHandlerProc(HWND, UINT, WPARAM, LPARAM);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
