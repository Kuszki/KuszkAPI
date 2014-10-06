using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Forms)

// ---- CLASES DECLARATIONS -----
class UserDialog;
class CommonDialog;
// ------------------------------

// --- USRDIALOG DECLARATIONS ---
class UserDialog : public Window
{
      protected:
              bool bModal;
              void* pvResult;
      public:
              Controls Control;
              UserDialog(const HWND& hOwn = NULL);
              ~UserDialog(void);
              HWND Create(const Containers::String& cRes,
                          DLGPROC pfDlgProc,
                          bool bModalDial = false);
              void Close(void* pvReturn = NULL);
              void* GetResult(void) const;
              void SetModal(bool bNewModal);
              bool GetModal(void) const;
              void SetTitle(const Containers::String& sNazwa);
              Containers::String GetTitle(void) const;
              void Destroy(void);
              void Clean(void);
};
// ------------------------------

// --- CMNDIALOG DECLARATIONS ---
class CommonDialog
{
      private:
              struct FilePath
              {
                       Containers::String Name;
                       Containers::String Path;
                       Containers::String Full;
              };
              struct FontInfo
              {
                       LOGFONT Data;
                       COLORREF Color;
              };
              const HWND& hOwner;
              mutable COLORREF ptColors[16];
              mutable FilePath tLastFile;
              mutable FontInfo tLastFont;
              mutable COLORREF tLastColor;
      public:
              CommonDialog(const HWND& hOwn = NULL);
              ~CommonDialog(void);
              bool GetFileOpen(const TCHAR pcDefExt[] = NULL,
                               const TCHAR pcMask[] = TEXT("Wszystkie pliki\0*.*\0"),
                               unsigned uFlags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY) const;
              bool GetFileSave(const TCHAR pcDefExt[] = NULL,
                               const TCHAR pcMask[] = TEXT("Wszystkie pliki\0*.*\0"),
                               unsigned uFlags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST) const;
              bool GetFont(unsigned uMin = 0,
                           unsigned uMax = 0) const;
              bool GetFont(LOGFONT tPrev,
                           COLORREF tColor = 0,
                           unsigned uMin = 0,
                           unsigned uMax = 0) const;
              bool GetColor(COLORREF tPrev = 0) const;
              const FilePath& GetLastFile(void) const;
              const FontInfo& GetLastFont(void) const;
              const COLORREF& GetLastColor(void) const;
              void SetOwner(HWND hOwner);
};
// ------------------------------

// ---- DIALOG DECLARATIONS -----
class Dialog
{
      private:
              const HWND& hOwner;
      public:
              UserDialog User;
              CommonDialog Common;
              Dialog(const HWND& hOwn);
              ~Dialog(void);
              void Clean(void);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
