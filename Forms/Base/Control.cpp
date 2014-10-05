using namespace KuszkAPI;

HINSTANCE KuszkAPI::Forms::Control::hInstance = GetModuleHandle(NULL);
HFONT KuszkAPI::Forms::Control::hDefFont = (HFONT) GetStockObject(DEFAULT_GUI_FONT);

KuszkAPI::Forms::Control::ToolTip::ToolTip(const HWND& hWnd, const HWND& hOwn)
: hWindow(hWnd), hOwner(hOwn)
{
     memset(&tToolTipInfo, 0, sizeof(TOOLINFO));

     hUchwyt = NULL;
}

KuszkAPI::Forms::Control::ToolTip::~ToolTip(void)
{
     Delete();
}

void KuszkAPI::Forms::Control::ToolTip::Add(const Containers::String& sTekst, const Containers::String& sTytul, unsigned uIkona)
{
     Delete();

     hUchwyt = CreateWindowEx(WS_EX_TOPMOST | WS_EX_NOACTIVATE, TOOLTIPS_CLASS, NULL, WS_POPUP | TTS_NOPREFIX, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hUchwyt, NULL, GetModuleHandle(NULL), NULL);

     RECT rObszar;

     memset(&rObszar, 0, sizeof(RECT));

     GetClientRect(hOwner, &rObszar);

     tToolTipInfo.cbSize = sizeof(TOOLINFO);
     tToolTipInfo.uFlags = TTF_SUBCLASS | TTF_IDISHWND;
     tToolTipInfo.hwnd = hOwner;
     tToolTipInfo.hinst = NULL;
     tToolTipInfo.uId = (UINT_PTR) hWindow;
     tToolTipInfo.lpszText = sTekst.Str();
     tToolTipInfo.rect.left = rObszar.left;
     tToolTipInfo.rect.top = rObszar.top;
     tToolTipInfo.rect.right = rObszar.right;
     tToolTipInfo.rect.bottom = rObszar.bottom;

     SendMessage(hUchwyt, TTM_ADDTOOL, 0, (LPARAM) &tToolTipInfo);
     SendMessage(hUchwyt, TTM_SETMAXTIPWIDTH, 0, 200);

     if (sTytul) SendMessage(hUchwyt, TTM_SETTITLE, uIkona, (LPARAM) sTytul.Str());
}

void KuszkAPI::Forms::Control::ToolTip::Delete(void)
{
     if (hUchwyt){

          SendMessage(hUchwyt, TTM_DELTOOL, 0, (LPARAM) &tToolTipInfo);

          memset(&tToolTipInfo, 0, sizeof(TOOLINFO));

          hUchwyt = NULL;

     }
}

void KuszkAPI::Forms::Control::ToolTip::Set(const Containers::String& sTekst, const Containers::String& sTytul, unsigned uIkona)
{
     if (!hUchwyt) return;

     if (sTekst){

            tToolTipInfo.lpszText = sTekst.Str();

            SendMessage(hUchwyt, TTM_SETTOOLINFO, 0, (LPARAM) &tToolTipInfo);

     }

     if (sTytul) SendMessage(hUchwyt, TTM_SETTITLE, uIkona, (LPARAM) sTytul.Str());
}

KuszkAPI::Forms::Control::Control(const HWND& hOwn, unsigned uCrtId)
: Tooltip(hUchwyt, hOwner), Window(hOwn)
{
     uId = uCrtId;

     fDefProc = NULL;
}

void KuszkAPI::Forms::Control::SetFont(HFONT hCzcionka)
{
     SendMessage(hUchwyt, WM_SETFONT, hCzcionka ? (WPARAM) hCzcionka : (WPARAM) hDefFont, MAKELPARAM(true, 0));
}

HWND KuszkAPI::Forms::Control::GetOwner(void) const
{
     return hOwner;
}

unsigned KuszkAPI::Forms::Control::GetId(void) const
{
     return uId;
}

WNDPROC KuszkAPI::Forms::Control::GetDefProc(void) const
{
     return fDefProc;
}

WNDPROC KuszkAPI::Forms::Control::Subclass(WNDPROC fProc)
{
     WNDPROC fTmp = SubclassWindow(hUchwyt, fProc);

     if (!fDefProc) fDefProc = fTmp;

     return fDefProc;
}

void KuszkAPI::Forms::Control::Destroy(void)
{
     if (hUchwyt){

          Clean();

          Window::Destroy();

     }
}

void KuszkAPI::Forms::Control::Clean(void)
{
     Tooltip.Delete();
}

KuszkAPI::Forms::Control::operator WNDPROC (void) const
{
     return fDefProc;
}

template<typename tnControl>
tnControl KuszkAPI::Forms::Control::Clone(HWND hWindow)
{
	tnControl cControl(GetParent(hWindow), (unsigned) GetMenu(hWindow));

	cControl.hUchwyt = hWindow;
	cControl.bTmpWindow = true;

	return cControl;
}
