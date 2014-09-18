/*! \file
    \brief Dołącza składnik obsługi plików z modułu Containers.hpp.
    \warning Należy dołączyć brakujące zależności ręcznie.

Po dołączeniu dyrektywą "include" do projektu zostanie dodany wyłącznie moduł obsługi plików.
*/

#ifndef _KUSZKAPI_CONTANIERS_FILES_H
#define _KUSZKAPI_CONTANIERS_FILES_H

// ------ MODES DEFINITIONS -----
#define MODE_STREAM      0	//!< Odpowiada modelowi pliku strumieniowego. Należy używać w połączeniu z plikami w których dane zapisywane są za pomocą ciągu bitów.
#define MODE_STRUCT      1	//!< Odpowiada modelowi pliku strukturalnego. Należy używać w połączeniu z plikami w których dane zapisywane są jako uporządkowane wpisy o jednakowej wielkości.
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Files\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#include "Files\File.cpp"
// ------------------------------

#endif
