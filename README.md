KuszkAPI
==========

Wstęp
----------
Amatorski silnik pozwalający w łatwy sposób projektować programy zgodne z WinAPI, ShellAPI i WinSock używając obiektowo zorientowanych modeli do zarządzania kodem.

Zdaję sobie sprawę, że cała idea może wydawać się śmieszna i daremna, a także, że istnieje wiele podobnych silników, wydajniejszych i lepszych.

Jeśli znalazłeś błąd, masz jakieś propozycje lub uwagi, zgłoś to w <a target="_blank" href="https://github.com/Kuszki/KuszkAPI/issues">bugtrackerze</a> na GitHubie.

Licencja
----------

Niniejszy program jest wolnym oprogramowaniem; możesz go rozprowadzać dalej i/lub modyfikować na warunkach Powszechnej Licencji Publicznej GNU, wydanej przez Fundację Wolnego Oprogramowania - według wersji 2-giej tej Licencji lub którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH ZASTOSOWAŃ. W celu uzyskania bliższych informacji - Powszechna Licencja Publiczna GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz Powszechnej Licencji Publicznej GNU (GNU General Public License); jeśli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

Założenia
----------
Projekt powstał w celu zapoznania się z działaniem WinAPI oraz WinSock, a także w celu zrozumienia idei programowania obiektowego. Jako, że jest to dość wygodna forma zarządzania kodem stosuje ją w sowich programach.

Jeśli masz ochotę możesz korzystać z tego projektu na zasadzie licencji GNU GENERAL PUBLIC LICENSE v2.

Instalacja
----------
Aby używać projektu należy rozpakować go w dowolne miejsce, a następnie dołączyć plik nagłówkowy `KuszkAPI.hpp` dyrektywą:

`#include "<path to KuszkAPI root dir>/KuszkAPI.hpp"`.

Następnie do projektu należy dodać plik `KuszkAPI.cpp` i oznaczyć go jako "do budowy".

Gdy zamierzasz urzyć w projekcie szablonów pochodzących z dołączonego środowiska utwórz dowolny plik nagłówkowy, w którym wymienisz wszystkie użyte szablony, a następnie zdefiniuj globalne makro w projekcie:

`KUSZKAPI_TEMPLATE_SPEC=\"<ścieżka do Twojego pliku z deklaracjami szablonów>\"`

Przykładowa deklaracja użycia szablonu Mapy z parametrem klucza `int`, oraz typem danych `bool`:

`template class KuszkAPI::Containers::Map<bool, int>;`

Oraz przykład deklaracji użycia metody Read z klasy Klienta serwera, wraz z zastosowaniem skróconych nazw, gdzie jako parametr danych użyty zostanie typ `char`:

`template unsigned SRV::Read<char>(const ARA<char>&, unsigned);`

Oczywiście możesz także w głównym pliku projektu umieścić poniższą dyrektywę:

`#include "<path to KuszkAPI root dir>/KuszkAPI.cpp"`.

Musisz jednak pamiętać, że zbudowanie kilku plików źródłowych używających projektu może być niemożliwe.


Należy także wziąć pod uwagę, aby pliki nagłówkowe dołączane w windows.h były kompletne i zawierały wszystkie definicje (Common Control w wersji 6 lub nowszej). Domyślnie projekty będą budowane dla Windows XP+ i mogą nie działać poprawnie na poprzednich systemach.

Dokumentacja
----------
Możesz wygenerować dokumentacje samemu za pomocą programu <a target="_blank" href="http://www.stack.nl/~dimitri/doxygen/index.html">Doxygen</a> lub wysłać mi maila z prośbą o udostępnienie dokumentacji. Dokumentacja znajduję się też na moim <a target="_blank" href="http://kuszki.myftp.org/slites/api">serwerze</a>, nie gwarantuję jednak, że będzie on czynny.
