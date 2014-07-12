/*! \file
    \brief Dołącza do projektu moduł aplikacji.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.h
    \see Core.h
    \see Forms.h
    \see Sockets.h
    \see Time.h

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu aplikacji takie jak model aplikacji okienkowej, konsolowej, czy biblioteki DLL.
*/

#ifndef _KUSZKAPI_APP_H
#define _KUSZKAPI_APP_H

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ------ OWN USED HEADERS ------
#include "App\Base.h"
#include "App\Types.h"
// ------------------------------

// ----- MACROS DEFINITIONS -----
/*! \brief Wywołuje funkcję CWinApp::Debug z wybraną wiadomością dla użytkownika i dodatkowymi predefioniwalnymi macrami.
    \param [in] sStr Wiadomość dla użytkownika.
    \return Odpowiedź użytkownika.
*/
#define Debug(sStr) Debug(sStr, KuszkAPI::Containtes::CString(__DATE__), KuszkAPI::Containtes::CString(__TIME__), KuszkAPI::Containtes::CString(__FILE__), KuszkAPI::Containtes::CString(__FUNCTION__), KuszkAPI::Containtes::CString(__LINE__))
// ------------------------------

#endif
