KuszkAPI
==========

Wstęp
----------
Amatorski silnik pozwalający w łatwy sposób projektować programy zgodne z WinAPI, ShellAPI i WinSock używając obiektowo zorientowanych modeli do zarządzania kodem.

Zdaję sobie sprawę, że cała idea może wydawać się śmieszna i daremna, a także, że istnieje wiele podobnych silników, wydajniejszych i lepszych.

Jeśli znalazłeś błąd, masz jakieś propozycje lub uwagi, zgłoś to w <a target="_blank" href="https://github.com/Kuszki/KuszkAPI/issues">bugtrackerze</a> na GitHubie.

Założenia
----------
Projekt powstał w celu zapoznania się z działaniem WinAPI oraz WinSock, a także w celu zrozumienia idei programowania obiektowego. Jako, że jest to dość wygodna forma zarządzania kodem stosuje ją w sowich programach.

Jeśli masz ochotę możesz korzystać z tego projektu na zasadzie licencji GNU GENERAL PUBLIC LICENSE v2.

Instalacja
----------
Aby używać projektu należy rozpakować go w dowolne miejsce, a następnie dołączyć plik KuszkAPI.hpp dyrektywą `#include <path to KuszkAPI root dir>/KuszkAPI.hpp`.

Należy wziąć pod uwagę, aby pliki nagłówkowe dołączane w windows.h były kompletne i zawierały wszystkie definicje (Common Control w wersji 6 lub nowszej). Domyślnie projekty będą budowane dla Windows XP+ i mogą nie działać poprawnie na poprzednich systemach.
