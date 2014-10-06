using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Forms)

// ---- CLASES DECLARATIONS -----
class Form;
// ------------------------------

// ----- FORM DECLARATIONS ------
class Form : public Window
{

     private:

          HMENU hMenu;

          Containers::String sWindowName;
          Containers::String sClassName;

     public:

          Controls Widgets;

          WNDCLASSEX Class;

          Form(const HWND& hOwn = HWND_DESKTOP);

          void New(const Containers::String& sNazwaKlasy,
                   const Containers::String& sNazwaOkna,
                   WNDPROC pfProc,
                   unsigned uStyl = CS_DBLCLKS,
                   HBRUSH hKolor = (HBRUSH) COLOR_WINDOW);
          HWND Create(unsigned uExStyl = 0,
                      unsigned uStyl = WS_OVERLAPPEDWINDOW,
                      HMENU hMenuGl = NULL,
                      int iSzerokosc = CW_USEDEFAULT,
                      int iWysokosc = CW_USEDEFAULT,
                      int iXPos = CW_USEDEFAULT,
                      int iYPos = CW_USEDEFAULT);
          bool Register(void);
          void SetTitle(const Containers::String& sNazwa);
          Containers::String GetTitle(void) const;
          HMENU GetMenu(void) const;

          virtual void Clean(void) override;

          static Forms::Form Clone(HWND hWindow);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
