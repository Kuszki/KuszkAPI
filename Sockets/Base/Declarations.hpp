using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Sockets)

// --- ABSTRACT DECLARATIONS ----
class Socket;
// ------------------------------

// ---- SOCKET DECLARATIONS -----
class Socket
{
     protected:

          static unsigned uIlosc;

          SOCKET sSocket;
          sockaddr_in sAdres;

          HWND hHandler;
          HWND hCurrent;

     public:

          Socket(void);
          virtual ~Socket(void);

          SOCKET GetSocket(void) const;

          operator SOCKET (void) const;

          static void Start(unsigned short uMain = 2,
                            unsigned short uSub = 0);
          static void Stop(void);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
