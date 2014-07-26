/*! \file
    \brief Dołącza do projektu moduł pojemników.
    \todo Należy ujednolicić wszystkie kontenery aby obsługiwało się je w jednakowy sposób.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu pojemników takie jak model wektora, listy, obsługa plików i ciągów znakowych.
*/

#ifndef _KUSZKAPI_CONTANIERS_H
#define _KUSZKAPI_CONTANIERS_H

// -------- USED HEADERS --------
#include <Windows.h>
// ------------------------------

// ----- FORMAT DEFINITIONS -----
/// Wskazuje na ostatni element w kontenerze.
/// Użyty jako indeks elementu w kontenerze wskazuje ostatni element w tym kontenerze.
#define LAST 0
/// Ustala tryb kodowania dodawania nowego elementu.
/// Używane jako parametr metody dodającej do kontenera nowy element ustala, że ma on zostać dodany za wybranym elementem.
#define ADD_AFTER 1
/// Ustala tryb kodowania dodawania nowego elementu.
/// Używane jako parametr metody dodającej do kontenera nowy element ustala, że ma on zostać dodany przed wybranym elementem.
#define ADD_BEFORE 0
// ------------------------------

// ------ OWN USED HEADERS ------
#include "Containers\Base.hpp"
#include "Containers\Common.hpp"
#include "Containers\String.hpp"
#include "Containers\Files.hpp"
#include "Containers\Strings.hpp"
// ------------------------------

#endif
