/*! \file
    \brief Dołącza do projektu moduł jądra.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.hpp

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu jądra takie jak obsługa konsoli, bibliotek DLL, wątków i innych obiektów związanych z kontrolą działania aplikacji.
*/

#ifndef _KUSZKAPI_CORE_H
#define _KUSZKAPI_CORE_H

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ------ OWN USED HEADERS ------
#include "Core\Parts.hpp"
#include "Core\Data.hpp"
#include "Core\Run.hpp"
#include "Core\Threads.hpp"
// ------------------------------

#endif