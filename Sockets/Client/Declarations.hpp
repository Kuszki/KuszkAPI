using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Sockets)

// --- FUNCTIONS DECLARATIONS ---
LRESULT CALLBACK ClientHandlerProc(HWND, UINT, WPARAM, LPARAM);
// ------------------------------

// ---- CLASES DECLARATIONS -----
class Client;
// ------------------------------

// ---- CLIENT DECLARATIONS -----
class Client : public Socket
{

     protected:

          typedef LRESULT (*ClientProc)(Client&, UINT);

          static unsigned uSize;
          static bool bClassRegistered;

          static bool Register(void);

     public:

          Client(SOCKET sSock,
                const sockaddr_in& sAdr);
          Client(void);

          bool Connect(const Containers::String& sServer,
                       unsigned short uPort,
                       HWND hWnd);
          bool Connect(const Containers::String& sServer,
                       unsigned short uPort,
                       ClientProc fProc);
          void Disconnect(void);
          bool Connected(void) const;
          Containers::String GetAddress(void) const;

          template<typename tnData> unsigned Send(const Containers::Array<tnData>& aBufor,
                                                  unsigned uHeader = 0);
          template<typename tnData> unsigned Recv(Containers::Array<tnData>& aBufor,
                                                  unsigned& uHeader);
          template<typename tnData> unsigned Recv(Containers::Array<tnData>& aBufor);

          Client& operator<< (const Containers::String& sMessage);
          Client& operator>> (Containers::String& sMessage);

          friend LRESULT CALLBACK ClientHandlerProc(HWND, UINT, WPARAM, LPARAM);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
