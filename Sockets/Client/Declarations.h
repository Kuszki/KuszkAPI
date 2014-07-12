using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Sockets)

// ---- CLASES DECLARATIONS -----
class Client;
// ------------------------------

// ---- CLIENT DECLARATIONS -----
class Client : Socket
{
      private:
              unsigned uSize;
      public:
              Client(SOCKET sSock,
                      sockaddr_in sAdr);
              Client(void);
              bool Connect(const Containers::String& sServer,
                           unsigned short uPort,
                           HWND hWnd);
              void Disconnect(void);
              bool Connected(void) const;
              Containers::String GetAdress(void) const;
              template<typename tnData> unsigned Send(const Containers::Array<tnData>& aBufor,
                                                      unsigned uHeader = 0);
              template<typename tnData> unsigned Recv(Containers::Array<tnData>& aBufor,
                                                      unsigned& uHeader);
              template<typename tnData> unsigned Recv(Containers::Array<tnData>& aBufor);
              Client& operator<< (const Containers::String& sMessage);
              Client& operator>> (Containers::String& sMessage);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
