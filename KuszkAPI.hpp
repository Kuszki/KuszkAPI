/*! \file
    \brief Główny plik dołączający do projektu całe środowisko.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe KuszkAPI.
*/

/*! \namespace KuszkAPI
    \brief Główna przestrzeń nazw projektu.

Zawiera jedynie kolejne przestrzenie nazw odpowiadające za poszczególne moduły. Nie zawiera definicji ani deklaracji żadnych klas, struktur i funkcji.
*/

#ifndef _KUSZKAPI_H
#define _KUSZKAPI_H

// ---- NAMESPACE DEFINITION ----
namespace KuszkAPI {};
// ------------------------------

#define KUSZKAPI_NAMESPACE(name) namespace KuszkAPI { namespace name {
#define KUSZKAPI_NAMESPACE_END };};

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

#endif
