/*! \file
    \brief Główny plik dołączający do projektu skrócone nazwy dla wybranych klas.

Aby nie dołączać skróconych nazw (na przykład gdy kolidują z użytymi w innym projekcie) należy zdefiniować makro KUSZKAPI_NOSCROUTS przed dołączeniem głównego pliku KuszkAPI.h.
*/

#ifndef _KUSZKAPI_H_SCROUTS
#define _KUSZKAPI_H_SCROUTS

// ----- MACROS DEFINITIONS -----
/// Makro powodujące wyłączenie używania skróconych nazw w projekcie.
/// Jeśli nie chcesz używać skróconych nazw, bądź kolidują one z nazwami w Twoim projekcie, zwyczajnie zdefiniuj to makro przed dołączeniem biblioteki.
#define KUSZKAPI_NOSCROUTS

#define SRV KuszkAPI::Sockets::Server        //!< Skrócona nazwa dla klasy KuszkAPI::Sockets::Server.
#define CLI KuszkAPI::Sockets::Client        //!< Skrócona nazwa dla klasy KuszkAPI::Sockets::Client.

#define STR KuszkAPI::Containers::String     //!< Skrócona nazwa dla klasy KuszkAPI::Sockets::String.

#define CON KuszkAPI::Core::Console          //!< Skrócona nazwa dla klasy KuszkAPI::Sockets::Console.

#define WND KuszkAPI::Forms::Form            //!< Skrócona nazwa dla klasy KuszkAPI::Sockets::Form.

#undef KUSZKAPI_NOSCROUTS
// ------------------------------

#endif
