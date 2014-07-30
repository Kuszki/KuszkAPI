#ifndef _KUSZKAPI_CORE_RUN_H
#define _KUSZKAPI_CORE_RUN_H

// ----- SCRIPT DEFINITIONS -----
#define SCRIPT_ERROR ((unsigned) -1)	//!< Wartość zwracana przez klasę KuszkAPI::Core::Script w przypadku błędu.
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Run\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifndef KUSZKAPI_HPPONLY
#include "Run\Script.cpp"
#include "Run\Dll.cpp"
#include "Run\Hook.cpp"
#endif
// ------------------------------

#endif
