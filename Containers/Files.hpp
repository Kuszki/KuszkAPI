/*! \file
    \brief Dołącza składnik obsługi plików z modułu Containers.hpp.
    \warning Należy dołączyć brakujące zależności ręcznie.

Po dołączeniu dyrektywą "include" do projektu zostanie dodany wyłącznie moduł obsługi plików.
*/

#ifndef _KUSZKAPI_CONTANIERS_FILES_H
#define _KUSZKAPI_CONTANIERS_FILES_H

// ---- HEADERS DECLARATIONS ----
#include "Files\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "Files\File.cpp"
#endif
// ------------------------------

#endif
