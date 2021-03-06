/*! \file
    \brief Dołącza składnik obsługi łańcuchów znakowych z modułu Containers.hpp.

Po dołączeniu dyrektywą "include" do projektu zostani dodany wyłącznie moduł obsługi łańcuchów znakowych.
*/

#ifndef _KUSZKAPI_CONTANIERS_STRING_H
#define _KUSZKAPI_CONTANIERS_STRING_H

// ---- ACTIONS DEFINITIONS -----
#define T           TEXT      //!< Robocze macro dla TEXT.
#define StrLenW     wcslen    //!< Robocze macro dla wcslen.
#define StrLenA     strlen    //!< Robocze macro dla strlen.

#ifdef UNICODE

#define TCHAR       wchar_t   //!< Robocze macro dla wchar_t gdy używamy unicode w projekcie.
#define DCHAR       char      //!< Robocze macro dla char gdy używamy unicode w projekcie.
#define LongToStr   _ltow     //!< Robocze macro dla _ltow gdy używamy unicode w projekcie.
#define FloToStr	swprintf	//!< Robocze macro dla swprintf gdy używamy unicode w projekcie.
#define UnsToStr	_ultow	//!< Robocze macro dla _ultow gdy używamy unicode w projekcie.
#define StrToLong   _wtol     //!< Robocze macro dla _wtol gdy używamy unicode w projekcie.
#define StrToFlo	_wtof	//!< Robocze macro dla _wtof gdy używamy unicode w projekcie.
#define StrLen      StrLenW   //!< Robocze macro dla StrLenW gdy używamy unicode w projekcie.

#else

#define TCHAR       char      //!< Robocze macro dla char gdy nie używamy unicode w projekcie.
#define DCHAR       wchar_t   //!< Robocze macro dla wchar_t gdy nie używamy unicode w projekcie.
#define LongToStr   ltoa      //!< Robocze macro dla ltoa gdy nie używamy unicode w projekcie.
#define FloToStr	sprintf	//!< Robocze macro dla sprintf gdy nie używamy unicode w projekcie.
#define UnsToStr	_ultoa	//!< Robocze macro dla _ultoa gdy używamy unicode w projekcie.
#define StrToLong   atol      //!< Robocze macro dla atol gdy nie używamy unicode w projekcie.
#define StrToFlo	atof		//!< Robocze macro dla atof gdy nie używamy unicode w projekcie.
#define StrLen      StrLenA   //!< Robocze macro dla StrLenA gdy nie używamy unicode w projekcie.

#endif
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "String\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "String\String.cpp"
#endif
// ------------------------------

// ----- MACROS DEFINITIONS -----
#define S	(KuszkAPI::Containers::String)	//!< Skrócone niejawne wywołanie odpowiedniego konstruktora klasy KuszkAPI::Containers::String. Wygodne w użyciu do konwersji zwykłych łańcuchów lub innych danych na obiekt KuszkAPI::Containers::String.
// ------------------------------

#endif
