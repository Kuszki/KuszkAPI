using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Core)

// ---- CLASES DECLARATIONS -----
class Console;
// ------------------------------

// ---- CONSOLE DECLARATIONS ----
class Console
{

     protected:

          static HWND hUchwyt;

          static HANDLE hIn;
          static HANDLE hOut;

          static unsigned uIlosc;

          bool bVisible;

     public:

          Console(bool bShow = true);
          ~Console(void);

          void Show(bool bShow = true);
          bool Visible(void) const;
          bool Exists(void) const;
          void Write(const TCHAR pcTekst[],
                     bool bEol = true);
          void Write(const Containers::String& sTekst,
                     bool bEol = true);
          void Read(Containers::String& sTekst);
          void Command(const Containers::String& sCmd);
          void Pause(bool bMessage = true);
          void SetTitle(const Containers::String& sNazwa);
          Containers::Strings GetLines(unsigned uPoczatek = 0,
                                       unsigned uKoniec = 0) const;
          const HWND& GetHandle(void) const;
          void Clean(void);

          Console& operator<< (const Containers::String& sTekst);
          Console& operator<< (const unsigned& uUnsigned);
          Console& operator<< (const int& iInt);
          Console& operator<< (const TCHAR& cChar);
          Console& operator<< (const TCHAR pcChar[]);
          Console& operator>> (Containers::String& sTekst);
          Console& operator>> (unsigned& uUnsigned);
          Console& operator>> (int& iInt);
          Console& operator>> (TCHAR& cChar);

          operator const HWND& (void) const;

};
// ------------------------------

// ----- TRAY DECLARATIONS ------
class Tray
{
     protected:

          const HWND& hOwner;

          NOTIFYICONDATA dData;

     public:

          Tray(const HWND& hWnd);
          ~Tray(void);

          void Add(unsigned uTrayId,
                   unsigned uTrayMsg,
                   const Containers::String& sOpis,
                   const Containers::String& sIkona);

          void Delete(void);
          void Set(const Containers::String& sOpis = Containers::String(),
                   const Containers::String& sIkona = Containers::String());
          void Msg(const Containers::String& sTytul,
                   const Containers::String& sTekst,
                   int iIkona = NIIF_INFO) const;
          unsigned GetId(void) const;
          unsigned GetMsg(void) const;

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
