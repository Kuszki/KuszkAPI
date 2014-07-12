/*! \file
    \brief Dołącza składnik obsługi listy łańcuchów znakowych z modułu Containers.h.
    \warning Należy dołączyć brakujące zależności ręcznie.

Po dołączeniu dyrektywą "include" do projektu zostani dodany wyłącznie moduł obsługi listy łańcuchów znakowych.
*/

#ifndef _KUSZKAPI_CONTANIERS_STRINGS_H
#define _KUSZKAPI_CONTANIERS_STRINGS_H

// ------ MODES DEFINITIONS -----
/// Ustala tryb kodowania na ASCII.
/// Używane jako parametr metod klasy CStrings, pozwala ustalić jak kodowane mają być znaki w odczytywanym lub zapisywanym pliku.
#define MODE_ASCII 0
/// Ustala tryb kodowania na Unicode.
/// Używane jako parametr metod klasy CStrings, pozwala ustalić jak kodowane mają być znaki w odczytywanym lub zapisywanym pliku.
#define MODE_UNICODE 1
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Strings\Declarations.h"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#include "Strings\Strings.cpp"
// ------------------------------

#endif