/*! \file
    \brief Dołącza składnik obsługi listy łańcuchów znakowych z modułu Containers.hpp.
    \warning Należy dołączyć brakujące zależności ręcznie.

Po dołączeniu dyrektywą "include" do projektu zostani dodany wyłącznie moduł obsługi listy łańcuchów znakowych.
*/

#ifndef _KUSZKAPI_CONTANIERS_STRINGS_H
#define _KUSZKAPI_CONTANIERS_STRINGS_H

// ------ MODES DEFINITIONS -----
#define MODE_ASCII       0	//!< Ustala tryb kodowania na ASCII. Używane jako parametr metod klasy CStrings, pozwala ustalić jak kodowane mają być znaki w odczytywanym lub zapisywanym pliku.
#define MODE_UNICODE     1	//!< Ustala tryb kodowania na Unicode. Używane jako parametr metod klasy CStrings, pozwala ustalić jak kodowane mają być znaki w odczytywanym lub zapisywanym pliku.
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Strings\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "Strings\Strings.cpp"
#endif
// ------------------------------

#endif
