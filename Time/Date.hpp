#ifndef _KUSZKAPI_TIME_DATE_H
#define _KUSZKAPI_TIME_DATE_H

// ----- FORMAT DEFINITIONS -----
#define DAY 		2	//!< Styl daty. Do wyjścia zostanie dodany dzień miesiąca.
#define MONTH 		4	//!< Styl daty. Do wyjścia zostanie dodany numer miesiąca.
#define YEAR 		8	//!< Styl daty. Do wyjścia zostanie dodany rok.
#define WEEKDAY 	16	//!< Styl daty. Do wyjścia zostanie dodany dzień tygodnia.
#define WORDS 		32	//!< Styl daty. Nazwy w wyjściu zostaną wygenerowane używając słów zamiast cyfr.

#define WDMY 		2	//!< Styl daty. Wyjście będzie zawierało informacje w kolejności: <dzień tygodnia> <dzień miesiąca> <miesiąc> <rok>.
#define WYMD 		4	//!< Styl daty. Wyjście będzie zawierało informacje w kolejności: <dzień tygodnia> <rok> <miesiąc> <dzień miesiąca>.
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Date\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#include "Date\Date.cpp"
// ------------------------------

#endif
