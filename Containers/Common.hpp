/*! \file
    \brief Dołącza powszechne składniki modułu Containers.hpp.
    \warning Należy dołączyć brakujące zależności ręcznie.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wyłącznie powszechne składowe modułu kontenerów takie jak szablony modelów listy, wektora, tablicy, pudełka i mapy.
*/

#ifndef _KUSZKAPI_CONTANIERS_COMMON_H
#define _KUSZKAPI_CONTANIERS_COMMON_H

// ---- HEADERS DECLARATIONS ----
#include "Common\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "Common\List.cpp"
#include "Common\Vector.cpp"
#include "Common\Array.cpp"
#include "Common\Box.cpp"
#include "Common\Map.cpp"
#endif
// ------------------------------

#endif
