#ifndef _KUSZKAPI_CORE_THREADS_H
#define _KUSZKAPI_CORE_THREADS_H

// ---- HEADERS DECLARATIONS ----
#include "Threads\Declarations.hpp"
// ------------------------------

// ----- MACROS DEFINITIONS -----
#ifdef UNICODE
#define SETENV(s) _wputenv(s)	//!< Wywołanie funkcji _wputenv gdy zadeklarowano użycie unicode.
#define GETENV(s) _wgetenv(s)	//!< Wywołanie funkcji _wputenv gdy zadeklarowano użycie unicode.
#else
#define SETENV(s) _putenv(s)	//!< Wywołanie funkcji _putenv gdy nie zadeklarowano użycia unicode.
#define GETENV(s) getenv(s)	//!< Wywołanie funkcji getenv gdy nie zadeklarowano użycia unicode.
#endif
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#include "Threads\Thread.cpp"
#include "Threads\Event.cpp"
#include "Threads\Section.cpp"
#include "Threads\Process.cpp"
#include "Threads\Instance.cpp"
// ------------------------------

#endif
