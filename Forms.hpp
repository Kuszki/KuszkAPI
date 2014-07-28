/*! \file
    \brief Dołącza do projektu moduł graficznego interfejsu użytkownika.
    \warning Należy dołączyć brakujące zależności ręcznie.
    \see Containers.hpp

Po dołączeniu dyrektywą "include" do projektu zostaną dodane wszystkie składowe modułu interfejsu graficznego takie jak obsługa okien, dialogów, czcionek i kontrolek ułatwiających sterowanie aplikacją.
*/

/*! \namespace KuszkAPI::Forms
    \brief Przestrzeń nazw modułu okienek.

Zawiera wszystkie deklaracje i definicje składowych modułu okienek.
*/

#ifndef _KUSZKAPI_FORMS_H
#define _KUSZKAPI_FORMS_H

// -------- USED HEADERS --------
#include <Windows.h>
#include <Windowsx.h>
#include <Commctrl.h>
// ------------------------------

// ------ MISSING HEADERS -------
#include "Forms\Headers.hpp"
// ------------------------------

// ------ OWN USED HEADERS ------
#include "Forms\Tools.hpp"
#include "Forms\Base.hpp"
#include "Forms\Controls.hpp"
#include "Forms\Form.hpp"
#include "Forms\Dialogs.hpp"
#include "Forms\Fonts.hpp"
// ------------------------------

#endif
