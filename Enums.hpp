/*! \file
    \brief Plik dołączający do projektu makra używane jako typy wyliczeniowe.

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie makra wyliczeniowe używane przez wszystkie moduły.
*/

#define WM_CREATEWINDOW	(WM_USER + 1)	//!< Identyfikator zdarzenia utworzenia okna.
#define WM_SOCKET		(WM_USER + 2)	//!< Identyfikator zdarzenia gniazda.
#define WM_TRAY		(WM_USER + 3)	//!< Identyfikator zdarzenia obszaru powiadomień.

#define LAST        	0	//!< Użyty jako indeks elementu w kontenerze wskazuje ostatni element w tym kontenerze.
#define ADD_AFTER   	1	//!< Używane jako parametr metody dodającej do kontenera nowy element ustala, że ma on zostać dodany za wybranym elementem.
#define ADD_BEFORE  	0	//!< Używane jako parametr metody dodającej do kontenera nowy element ustala, że ma on zostać dodany przed wybranym elementem.

#define MODE_ASCII       0	//!< Ustala tryb kodowania na ASCII. Używane jako parametr metod klasy Containers::Strings, pozwala ustalić jak kodowane mają być znaki w odczytywanym lub zapisywanym pliku.
#define MODE_UNICODE     1	//!< Ustala tryb kodowania na Unicode. Używane jako parametr metod klasy Containers::Strings, pozwala ustalić jak kodowane mają być znaki w odczytywanym lub zapisywanym pliku.

#define MODE_STREAM      0	//!< Odpowiada modelowi pliku strumieniowego. Należy używać w połączeniu z plikami w których dane zapisywane są za pomocą ciągu bitów.
#define MODE_STRUCT      1	//!< Odpowiada modelowi pliku strukturalnego. Należy używać w połączeniu z plikami w których dane zapisywane są jako uporządkowane wpisy o jednakowej wielkości.

#define MODE_QUEUE  	0	//!< Odpowiada modelowi kolejki. Pierwszy element na wejściu jest pierwszym elementem na wyjściu.
#define MODE_HEEP   	1	//!< Odpowiada modelowi stosu. Pierwszy element na wejściu jest ostatnim elementem na wyjściu.

#define SCRIPT_ERROR	-1	//!< Wartość zwracana przez klasę Core::Script w przypadku błędu.

#define STYLE_ITALIC	1	//!< Styl czcionki. Czcionka z tym stylem będzie ukośna.
#define STYLE_UNDERLINE	2	//!< Styl czcionki. Czcionka z tym stylem będzie podkreślona.
#define STYLE_STRIKEOUT	4	//!< Styl czcionki. Czcionka z tym stylem będzie przekreślona.

#define ADD_ZEROS   	1	//!< Styl czasu. Wartości kolejnych pól zastaną zapisane przy użyciu dwóch cyfr.
#define HOURS 			2	//!< Styl czasu. Do wyjścia zostaną dodane godziny.
#define MINUTES 		4	//!< Styl czasu. Do wyjścia zostaną dodane minuty.
#define SECONDS 		8	//!< Styl czasu. Do wyjścia zostaną dodane sekundy.

#define DAY 			2	//!< Styl daty. Do wyjścia zostanie dodany dzień miesiąca.
#define MONTH 			4	//!< Styl daty. Do wyjścia zostanie dodany numer miesiąca.
#define YEAR 			8	//!< Styl daty. Do wyjścia zostanie dodany rok.
#define WEEKDAY 		16	//!< Styl daty. Do wyjścia zostanie dodany dzień tygodnia.
#define WORDS 			32	//!< Styl daty. Nazwy w wyjściu zostaną wygenerowane używając słów zamiast cyfr.

#define WDMY 			2	//!< Styl daty. Wyjście będzie zawierało informacje w kolejności: [dzień tygodnia] [dzień miesiąca] [miesiąc] [rok].
#define WYMD 			4	//!< Styl daty. Wyjście będzie zawierało informacje w kolejności: [dzień tygodnia] [rok] [miesiąc] [dzień miesiąca].
