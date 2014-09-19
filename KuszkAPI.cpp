/*! \file
    \brief Główny plik dołączający do projektu całe środowisko.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe KuszkAPI. Kod źródłowy całego projektu znajdziesz <a target="_blank" href="https://github.com/Kuszki/KuszkAPI">tutaj</a>
*/

#ifndef _KUSZKAPI_CPP
#define _KUSZKAPI_CPP

// ---- NAMESPACE DEFINITION ----
namespace KuszkAPI {};
// ------------------------------

// ------ NAMESPACE MACROS ------
#define KUSZKAPI_NAMESPACE(name) namespace KuszkAPI { namespace name {
#define KUSZKAPI_NAMESPACE_END };};
// ------------------------------

// ----- WINAPI DEFINITIONS -----
#define WINVER           0x0502
#define _WIN32_WINNT     0x0502
#define _WIN32_IE        0x0603
// ------------------------------

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ---- KUSZKAPI DEFINITIONS ----
#include "Containers.hpp"
#include "Time.hpp"
#include "Core.hpp"
#include "Forms.hpp"
#include "Sockets.hpp"
#include "App.hpp"
// ------------------------------

// ---- SCROUTS DEFINITIONS -----
#ifndef KUSZKAPI_NOSCROUTS
#include "Scrouts.hpp"
#endif
// ------------------------------

// ------- TEMPLATE SPECS -------
#ifdef KUSZKAPI_TEMPLATE_SPEC
#include KUSZKAPI_TEMPLATE_SPEC
#endif
// ------------------------------

#endif
