/*! \file
    \brief Dołącza składnik obsługi łańcuchów znakowych z modułu Containers.h.

Po dołączeniu dyrektywą "include" do projektu zostani dodany wyłącznie moduł obsługi łańcuchów znakowych.
*/

#ifndef _KUSZKAPI_CONTANIERS_STRING_H
#define _KUSZKAPI_CONTANIERS_STRING_H

// ---- ACTIONS DEFINITIONS -----
#define T TEXT
#define StrLenW wcslen
#define StrLenA strlen
#ifdef UNICODE
#define TCHAR wchar_t
#define DCHAR char
#define LongToStr _ltow
#define StrToLong _wtol
#define StrLen StrLenW
#else
#define TCHAR char
#define DCHAR wchar_t
#define LongToStr ltoa
#define StrToLong atol
#define StrLen StrLenA
#endif
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "String\Declarations.h"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#include "String\String.cpp"
// ------------------------------

// ----- MACROS DEFINITIONS -----
#define S (CString) //!< Skrócone niejawne wywołanie odpowiedniego konstruktora klasy CString. Wygodne w użyciu do konwersji zwykłych łańcuchów lub innych danych na obiekt CString.
// ------------------------------

#endif