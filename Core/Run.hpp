#ifndef _KUSZKAPI_CORE_RUN_H
#define _KUSZKAPI_CORE_RUN_H

// ----- SCRIPT DEFINITIONS -----
#define SCRIPT_ERROR	((unsigned) -1)	//!< Wartość zwracana przez klasę Core::Script w przypadku błędu.
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Run\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifdef _KUSZKAPI_CPP
#include "Run\Script.cpp"
#include "Run\Dll.cpp"
#include "Run\Hook.cpp"
#endif
// ------------------------------

#endif
