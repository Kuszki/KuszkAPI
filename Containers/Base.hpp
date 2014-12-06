/*! \file
    \brief Dołącza bazowe składniki modułu Containers.hpp.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wyłącznie bazowe składowe modułu kontenerów takie jak abstrakcyjna klasa kontenera.
*/

#ifndef _KUSZKAPI_CONTANIERS_BASE_H
#define _KUSZKAPI_CONTANIERS_BASE_H

// ---- HEADERS DECLARATIONS ----
#include "Base\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "Base\Container.cpp"
#endif
// ------------------------------

// ----- MACROS DEFINITIONS -----
#define foreach(container)	for (int i = 1; i <= container.Capacity(); i++)	//!< Skrócona konstrukcja pętli for dla wykonania operacji na wszystkich elementach kontenera.
// ------------------------------

#endif
