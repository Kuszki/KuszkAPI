#ifndef _KUSZKAPI_FORMS_BASE_H
#define _KUSZKAPI_FORMS_BASE_H

// ---- MESSAGES DEFINITIONS ----
#define WM_CREATEWINDOW (WM_USER + 1)
#define WM_SOCKET (WM_USER + 2)
#define WM_TRAY (WM_USER + 3)
// ------------------------------

// ---- HEADERS DECLARATIONS ----
#include "Base\Declarations.hpp"
// ------------------------------

// ---- HEADERS DEFINITIONS -----
#ifndef KUSZKAPI_HPPONLY
#include "Base\Window.cpp"
#include "Base\Control.cpp"
#include "Base\TextControl.cpp"
#include "Base\CheckControl.cpp"
#include "Base\ListControl.cpp"
#include "Base\DateControl.cpp"
#endif
// ------------------------------

#endif
