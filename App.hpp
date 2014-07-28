/*! \file
    \brief Dołącza do projektu moduł aplikacji.
    \warning Należy dołączyć brakujące zależności ręcznie.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu aplikacji takie jak model aplikacji okienkowej, konsolowej, czy biblioteki DLL.
*/

/*! \namespace KuszkAPI::Application
    \brief Przestrzeń nazw modułu aplikacji.

Zawiera wszystkie deklaracje i definicje składowych modułu aplikacji.
*/

#ifndef _KUSZKAPI_APP_H
#define _KUSZKAPI_APP_H

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ------ OWN USED HEADERS ------
#include "App\Base.hpp"
#include "App\Types.hpp"
// ------------------------------

// ----- MACROS DEFINITIONS -----
/*! \brief Wywołuje funkcję CWinApp::Debug z wybraną wiadomością dla użytkownika i dodatkowymi predefioniwalnymi macrami.
           Używane dla wygody w KuszkAPI::Application::WinApp do wywoływania KuszkAPI::Application::WinApp::Debug.
    \param [in] sStr Wiadomość dla użytkownika.
    \return Odpowiedź użytkownika.
*/
#define Debug(sStr) Debug(sStr, KuszkAPI::Containtes::CString(__DATE__), KuszkAPI::Containtes::CString(__TIME__), KuszkAPI::Containtes::CString(__FILE__), KuszkAPI::Containtes::CString(__FUNCTION__), KuszkAPI::Containtes::CString(__LINE__))
// ------------------------------

#endif
