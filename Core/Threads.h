#ifndef _KUSZKAPI_CORE_THREADS_H
#define _KUSZKAPI_CORE_THREADS_H

// ---- HEADERS DECLARATIONS ----
#include "Threads\Declarations.h"
// ------------------------------

// ----- MACROS DEFINITIONS -----
#ifdef UNICODE
#define SETENV(s) _wputenv(s)
#define GETENV(s) _wgetenv(s)
#else
#define SETENV(s) _putenv(s)
#define GETENV(s) getenv(s)
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
