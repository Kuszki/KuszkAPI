using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Forms)

// --- ABSTRACTS DECLARATIONS ---
class Window;
class Control;
class TextControl;
class CheckBoxControl;
class ListControl;
class DateControl;
// ------------------------------

// ---- WINDOW DECLARATIONS -----
class Window
{
      protected:
              class Timer
              {
              private:
                       const HWND& hOwner;
                       Containers::Map<UINT_PTR, unsigned> mTimer;
              public:
                       Timer(const HWND& hOwn);
                       ~Timer(void);
                       UINT_PTR Add(unsigned uTick,
                                    unsigned uId,
                                    TIMERPROC fProc = NULL);
                       void Delete(unsigned uId);
                       UINT_PTR GetHandle(unsigned uNumer) const;
                       void Clean(void);
                       UINT_PTR operator[] (unsigned uNumer) const;
              };
              const HWND& hOwner;
              HWND hUchwyt;
      public:
              struct TCord
              {
                       unsigned X;
                       unsigned Y;
              };
              Timer Timer;
              Window(const HWND& hOwn);
              virtual ~Window(void);
              void Show(int iStyl = SW_SHOWDEFAULT);
              bool Visible(void) const;
              bool Exists(void) const;
              void Focus(void);
              void Ground(void);
              void Enable(void);
              void Disable(void);
              LRESULT Msg(UINT mMessage,
                          LPARAM lParam = 0,
                          WPARAM wParam = 0);
              const HWND& GetHandle(void) const;
              void SetPos(int iXPos = 0,
                          int iYPos = 0);
              void SetPos(const TCord& tPos);
              Window::TCord GetPos(void) const;
              void SetSize(int iSzerokosc,
                           int iWysokosc);
              Window::TCord GetSize(void) const;
              void SetRegion(HRGN hRegion);
              void SetTopMost(bool bTop);
              void SetWndLong(int iId,
                              unsigned uWartosc);
              unsigned GetWndlong(int iId) const;
              void SetClaLong(int iId,
                              unsigned uWartosc);
              unsigned GetClaLong(int iId) const;
              operator const HWND& (void) const;
              virtual void Destroy(void) = 0;
              virtual void Clean(void) = 0;
              static void SetWndName(HWND hWnd,
                                     const Containers::String& sName);
              static Containers::String GetWndName(HWND hWnd);
};
// ------------------------------

// ---- CONTROL DECLARATIONS ----
class Control : public Window
{
      protected:
              class ToopTip
              {
              private:
                       const HWND& hWindow;
                       const HWND& hOwner;
                       TOOLINFO tToolTipInfo;
                       HWND hUchwyt;
              public:
                       ToopTip(const HWND& hWnd,
                                const HWND& hOwn);
                       ~ToopTip(void);
                       void Add(const Containers::String& sTekst,
                                const Containers::String& sTytul = Containers::String(),
                                unsigned uIkona = 0);
                       void Delete(void);
                       void Set(const Containers::String& sTekst = Containers::String(),
                                const Containers::String& sTytul = Containers::String(),
                                unsigned uIkona = 0);
              };
              static HINSTANCE hInstance;
              static HFONT hDefFont;
              WNDPROC fDefProc;
              unsigned uId;
      public:
              ToopTip Tooltip;
              Control(const HWND& hOwn,
                       unsigned uCtrId);
              virtual ~Control(void);
              void SetFont(HFONT hCzcionka = NULL);
              HWND GetOwner(void) const;
              unsigned GetId(void) const;
              WNDPROC GetDefProc(void) const;
              void Subclass(WNDPROC fProc);
              void Destroy(void);
              void Clean(void);
              operator WNDPROC (void) const;
};
// ------------------------------

// ---- TEXTCTR DECLARATIONS ----
class TextControl : public Control
{
      public:
              TextControl(const HWND& hOwn,
                           unsigned uCtrId);
              void SetText(const Containers::String& sText);
              Containers::String GetText(void) const;
              operator Containers::String (void) const;
};
// ------------------------------

// --- CHECKCTR DECLARATIONS ----
class CheckBoxControl : public TextControl
{
      public:
              CheckBoxControl(const HWND& hOwn,
                            unsigned uCtrId);
              bool GetCheck(void) const;
              operator bool (void) const;
              virtual void SetCheckBox(bool bZaznacz = true) = 0;
};
// ------------------------------

// ---- LISTCTR DECLARATIONS ----
class ListControl : public Control
{
      public:
              ListControl(const HWND& hOwn,
                           unsigned uCtrId);
              bool Empty(void) const;
              operator Containers::Strings (void) const;
              operator bool (void) const;
              virtual void DeleteItem(unsigned uNumer = 0) = 0;
              virtual Containers::String GetItem(unsigned uNumer = 0) const = 0;
              virtual Containers::Strings GetItems(void) const = 0;
              virtual unsigned GetIndex(void) const = 0;
              virtual unsigned Capacity(void) const = 0;
              virtual void CleanItems(void) = 0;
};
// ------------------------------

// ---- DATECTR DECLARATIONS ----
class DateControl : public Control
{
      public:
              DateControl(const HWND& hOwn,
                          unsigned uCtrId);
              virtual void SetDate(const DateTime::Date& dDate) = 0;
              virtual DateTime::Date GetDate(void) const = 0;
              operator DateTime::Date(void) const;
};
// ------------------------------

KUSZKAPI_NAMESPACE_END