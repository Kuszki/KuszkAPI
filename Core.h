/*! \file
    \brief Dołącza do projektu moduł jądra.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.h

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu jądra takie jak obsługa konsoli, bibliotek DLL, wątków i innych obiektów związanych z kontrolą działania aplikacji.
*/

#ifndef _KUSZKAPI_CORE_H
#define _KUSZKAPI_CORE_H

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ------ OWN USED HEADERS ------
#include "Core\Parts.h"
#include "Core\Data.h"
#include "Core\Run.h"
#include "Core\Threads.h"
// ------------------------------

#endif