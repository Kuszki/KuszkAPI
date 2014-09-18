/*! \mainpage KuszkAPI

    \section basic_sec Wstęp

    Amatorski silnik pozwalający w łatwy sposób projektować programy zgodne z WinAPI, ShellAPI i WinSock używając obiektowo zorientowanych modeli do zarządzania kodem.

    Zdaję sobie sprawę, że cała idea może wydawać się śmieszna i daremna, a także, że istnieje wiele podobnych silników, wydajniejszych i lepszych.

    Jeśli znalazłeś błąd, masz jakieś propozycje lub uwagi, zgłoś to w <a target="_blank" href="https://github.com/Kuszki/KuszkAPI/issues">bugtrackerze</a> na GitHubie.

    \section license_sec Licencja

    Niniejszy program jest wolnym oprogramowaniem; możesz go rozprowadzać dalej i/lub modyfikować na warunkach Powszechnej Licencji Publicznej GNU, wydanej przez Fundację Wolnego Oprogramowania - według wersji 2-giej tej Licencji lub którejś z późniejszych wersji.

    Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH ZASTOSOWAŃ. W celu uzyskania bliższych informacji - Powszechna Licencja Publiczna GNU.

    Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz Powszechnej Licencji Publicznej GNU (GNU General Public License); jeśli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    \section intro_sec Założenia

    Projekt powstał w celu zapoznania się z działaniem WinAPI oraz WinSock, a także w celu zrozumienia idei programowania obiektowego. Jako, że jest to dość wygodna forma zarządzania kodem stosuje ją w sowich programach.

    Jeśli masz ochotę możesz korzystać z tego projektu na zasadzie licencji <a target="_blank" href="https://github.com/Kuszki/KuszkAPI/blob/master/LICENSE">GNU GENERAL PUBLIC LICENSE v2</a>.

    \section install_sec Instalacja

    Aby używać projektu należy rozpakować go w dowolne miejsce, a następnie dołączyć plik KuszkAPI.hpp dyrektywą "include".

    Należy wziąć pod uwagę, aby pliki nagłówkowe dołączane w windows.h były kompletne i zawierały wszystkie definicje (Common Control w wersji 6 lub nowszej). Domyślnie projekty będą budowane dla Windows XP+ i mogą nie działać poprawnie na poprzednich systemach.

    \section links_sec Przydatne linki

    <ul>
          <li>Projekt w serwisie GitHub: https://github.com/Kuszki/KuszkAPI</li>
          <li>Strona autora: http://kuszki.myftp.org</li>
          <li>Mail autora: l.drozdz@o2.pl</li>
          <li>Treść licencji (angielski): http://www.gnu.org/licenses/gpl-2.0.html</li>
          <li>Treść licencji (polski): http://gnu.org.pl/text/licencja-gnu.html</li>
    </ul>
*/

/*! \file
    \brief Główny plik dołączający do projektu całe środowisko.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe KuszkAPI. Kod źródłowy całego projektu znajdziesz <a target="_blank" href="https://github.com/Kuszki/KuszkAPI">tutaj</a>
*/

/*! \namespace KuszkAPI
    \brief Główna przestrzeń nazw projektu.

Zawiera jedynie kolejne przestrzenie nazw odpowiadające za poszczególne moduły. Nie zawiera definicji ani deklaracji żadnych klas, struktur i funkcji. Kod źródłowy znajdziesz <a target="_blank" href="https://github.com/Kuszki/KuszkAPI">tutaj</a>.
*/

#ifndef _KUSZKAPI_H
#define _KUSZKAPI_H

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

#endif
