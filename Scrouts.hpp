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

#define SRV KuszkAPI::Sockets::Server		//!< Skrócona nazwa dla klasy KuszkAPI::Sockets::Server.
#define CLI KuszkAPI::Sockets::Client		//!< Skrócona nazwa dla klasy KuszkAPI::Sockets::Client.

#define STR KuszkAPI::Containers::String	//!< Skrócona nazwa dla klasy KuszkAPI::Containers::String.
#define MAP KuszkAPI::Containers::Map		//!< Skrócona nazwa dla klasy KuszkAPI::Containers::Map.
#define ARA KuszkAPI::Containers::Array		//!< Skrócona nazwa dla klasy KuszkAPI::Containers::Array.
#define LST KuszkAPI::Containers::List		//!< Skrócona nazwa dla klasy KuszkAPI::Containers::List.
#define BOX KuszkAPI::Containers::Box		//!< Skrócona nazwa dla klasy KuszkAPI::Containers::Box.
#define VCT KuszkAPI::Containers::Vector	//!< Skrócona nazwa dla klasy KuszkAPI::Containers::Vector.

#define INI KuszkAPI::Core::Ini              //!< Skrócona nazwa dla klasy KuszkAPI::Core::Ini.
#define CON KuszkAPI::Core::Console		//!< Skrócona nazwa dla klasy KuszkAPI::Core::Console.
#define THR KuszkAPI::Core::Threads<INT>	//!< Skrócona nazwa dla klasy KuszkAPI::Core::Threads.
#define SEC KuszkAPI::Core::Sections<INT>	//!< Skrócona nazwa dla klasy KuszkAPI::Core::Sections.
#define DLL KuszkAPI::Core::Dll<INT>		//!< Skrócona nazwa dla klasy KuszkAPI::Core::Dll.

#define WND KuszkAPI::Forms::Form			//!< Skrócona nazwa dla klasy KuszkAPI::Forms::Form.

#undef KUSZKAPI_NOSCROUTS
// ------------------------------

#endif
