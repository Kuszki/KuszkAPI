/*! \file
    \brief Deklaracje dla plików DllApp.cpp i WinApp.cpp.

Plik zawiera jedynie deklaracje z protoypami klas włącznie z ich polami i metodami.
*/

using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Application)

// --- ABSTRACT DECLARATIONS ----
class WinApp;
class DllApp;
// ------------------------------

// ------ APP DECLARATIONS ------
class WinApp : public App
{
      protected:
              HANDLE hMutex;
      public:
              Forms::Font<unsigned> Fonts;
              Forms::Form Window;
              Forms::Dialog Interface;
              Core::Tray Notification;
              Core::Console Terminal;
              WinApp(bool bSingle = false);
              WinApp(const Containers::String& sClass,
                     const Containers::String& sWnd);
              ~WinApp(void);
              Containers::String Debug(const Containers::String& sTekst,
                                       const Containers::String& sDate,
                                       const Containers::String& sTime,
                                       const Containers::String& sFile,
                                       const Containers::String& sFunction,
                                       const Containers::String& sLine);
};
// ------------------------------

// ------ APP DECLARATIONS ------
class DllApp : public App
{
      public:
              DllApp(void);
              ~DllApp(void);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
