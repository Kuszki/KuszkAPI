/*! \file
    \brief Główny plik dołączający do projektu całe środowisko.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe KuszkAPI.
*/

#ifndef _KUSZKAPI_H
#define _KUSZKAPI_H

namespace KuszkAPI {};

#define KUSZKAPI_NAMESPACE(name) namespace KuszkAPI { namespace name {
#define KUSZKAPI_NAMESPACE_END };};

// ----- WINAPI DEFINITIONS -----
#define WINVER 0x0502
#define _WIN32_WINNT 0x0502
#define _WIN32_IE 0x0603
// ------------------------------

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ---- KUSZKAPI DEFINITIONS ----
#include "Containers.h"
#include "Time.h"
#include "Core.h"
#include "Forms.h"
#include "Sockets.h"
#include "App.h"
// ------------------------------

#endif
