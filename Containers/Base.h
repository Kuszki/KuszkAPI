/*! \file
    \brief Dołącza bazowe składniki modułu Containers.h.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wyłącznie bazowe składowe modułu kontenerów takie jak abstrakcyjna klasa kontenera.
*/

#ifndef _KUSZKAPI_CONTANIERS_BASE_H
#define _KUSZKAPI_CONTANIERS_BASE_H

// ----- MODES DEFINITIONS ------
/// Odpowiada modelowi kolejki.
/// Pierwszy element na wejściu jest pierwszym elementem na wyjściu.
#define MODE_QUEUE 0
/// Odpowiada modelowi stosu.
/// Pierwszy element na wejściu jest ostatnim elementem na wyjściu.
#define MODE_HEEP 1
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Base\Declarations.h"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#include "Base\Container.cpp"
// ------------------------------

#endif