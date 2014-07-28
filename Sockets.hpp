/*! \file
    \brief Dołącza do projektu moduł obsługi Socketów.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.hpp

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu Socketów takie jak model klienta i serwera aplikacji sieciowej.
*/

/*! \namespace KuszkAPI::Sockets
    \brief Przestrzeń nazw modułu gniazd.

Zawiera wszystkie deklaracje i definicje składowych modułu gniazd.
*/

#ifndef _KUSZKAPI_SOCKETS_H
#define _KUSZKAPI_SOCKETS_H

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ------ OWN USED HEADERS ------
#include "Sockets\Base.hpp"
#include "Sockets\Client.hpp"
#include "Sockets\Server.hpp"
// ------------------------------

#endif
