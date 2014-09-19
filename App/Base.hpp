/*! \file
    \brief Dołącza bazowe składniki modułu App.hpp.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.hpp
    \see Core.hpp
    \see Forms.hpp
    \see Sockets.hpp
    \see Time.hpp

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wyłącznie bazowe składowe modułu aplikacji takie jak abstrakcyjna klasa aplikacji.
*/

#ifndef _KUSZKAPI_APP_BASE_HPP
#define _KUSZKAPI_APP_BASE_HPP

// ---- HEADERS DECLARATIONS ----
#include "Base\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "Base\App.cpp"
#endif
// ------------------------------

#endif
