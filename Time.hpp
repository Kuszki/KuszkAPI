/*! \file
    \brief Dołącza do projektu moduł przechwoywania czasu i daty.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.hpp

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu czasu takie jak wygodny model daty i godziny.
*/

/*! \namespace KuszkAPI::DateTime
    \brief Przestrzeń nazw modułu czasu i daty.

Zawiera wszystkie deklaracje i definicje składowych modułu czasu i daty.
*/

#ifndef _KUSZKAPI_TIME_H
#define _KUSZKAPI_TIME_H

// -------- USED HEADERS --------
#include <Time.h>
// ------------------------------

// ----- FORMAT DEFINITIONS -----
#define ZERO   1
// ------------------------------

// ------ OWN USED HEADERS ------
#include "Time\Time.hpp"
#include "Time\Date.hpp"
// ------------------------------

#endif
