/*! \file
    \brief Deklaracje dla pliku App.cpp.

Plik zawiera jedynie deklaracje z protoypami klasy App włącznie z jej polami i metodami.
*/

using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Application)

// --- ABSTRACT DECLARATIONS ----
class App;
// ------------------------------

// ------ APP DECLARATIONS ------
class App
{
      protected:
              const DateTime::Time tRunTime;
              const DateTime::Date dRunDate;
      public:
              Core::Process<unsigned> Thread;
              Core::Hook<unsigned> Hook;
              Core::Dll<unsigned> Lib;
              Core::Instance Program;
              Core::Ini Config;
              Core::Reg Registry;
              App(void);
              virtual ~App(void);
              DateTime::Time GetRunTime(void) const;
              DateTime::Date GetRunDate(void) const;
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
