using namespace KuszkAPI;

KuszkAPI::Forms::Window::Timer::Timer(const HWND& hOwn) : hOwner(hOwn) {}

KuszkAPI::Forms::Window::Timer::~Timer(void)
{
     Clean();
}

UINT_PTR KuszkAPI::Forms::Window::Timer::Add(unsigned uTick, unsigned uId, TIMERPROC fProc)
{
     UINT_PTR uTmp = SetTimer(hOwner, uId, uTick, fProc);

     if (uTmp) if (mTimer.Add(uTmp, uId)) return uTmp; else KillTimer(hOwner, uId);

     return 0;
}

void KuszkAPI::Forms::Window::Timer::Delete(unsigned uNumer)
{
     KillTimer(hOwner, uNumer);

     mTimer.Delete(uNumer);
}

UINT_PTR KuszkAPI::Forms::Window::Timer::GetHandle(unsigned uNumer) const
{
     return mTimer.GetData(uNumer);
}

void KuszkAPI::Forms::Window::Timer::Clean(void)
{
     for (int i = 1; i <= mTimer.Capacity(); i++) KillTimer(hOwner, mTimer.GetKey(i));

     mTimer.Clean();
}

UINT_PTR KuszkAPI::Forms::Window::Timer::operator[] (unsigned uNumer) const
{
     return mTimer.GetData(uNumer);
}

KuszkAPI::Forms::Window::Window(const HWND& hOwn)
: hOwner(hOwn), Watch(hUchwyt)
{
     hUchwyt = NULL;

     bTmpWindow = false;
}

KuszkAPI::Forms::Window::~Window(void)
{
     if (!bTmpWindow) Destroy();
}

void KuszkAPI::Forms::Window::Show(int iStyl)
{
     ShowWindow(hUchwyt, iStyl);
}

bool KuszkAPI::Forms::Window::Visible(void) const
{
     return IsWindowVisible(hUchwyt);
}

bool KuszkAPI::Forms::Window::Exists(void) const
{
     return hUchwyt;
}

void KuszkAPI::Forms::Window::Focus(void)
{
     SetFocus(hUchwyt);
}

void KuszkAPI::Forms::Window::Ground(void)
{
     SetForegroundWindow(hUchwyt);
}

void KuszkAPI::Forms::Window::Enable(void)
{
     EnableWindow(hUchwyt, true);
}

void KuszkAPI::Forms::Window::Disable(void)
{
     EnableWindow(hUchwyt, false);
}

LRESULT KuszkAPI::Forms::Window::Msg(UINT mMessage, LPARAM lParam, WPARAM wParam)
{
     return SendMessage(hUchwyt, mMessage, lParam, wParam);
}

const HWND& KuszkAPI::Forms::Window::GetHandle(void) const
{
     return hUchwyt;
}

void KuszkAPI::Forms::Window::SetPos(int iXPos, int iYPos)
{
     RECT rObszar;

     GetClientRect(hUchwyt, &rObszar);

     if (!iXPos) iXPos = GetSystemMetrics(SM_CXFULLSCREEN) / 2 - (rObszar.right - rObszar.left) / 2;
     if (!iYPos) iYPos = GetSystemMetrics(SM_CYFULLSCREEN) / 2 - (rObszar.bottom - rObszar.top) / 2;

     SetWindowPos(hUchwyt, hOwner, iXPos, iYPos, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void KuszkAPI::Forms::Window::SetPos(const Cord& tPos)
{
     SetPos(tPos.X, tPos.Y);
}

KuszkAPI::Forms::Window::Cord KuszkAPI::Forms::Window::GetPos(void) const
{
     Cord tCord;
     POINT pTmp;

     memset(&pTmp, 0, sizeof(POINT));

     MapWindowPoints(hUchwyt, hOwner, &pTmp, 1);

     tCord.X = pTmp.x;
     tCord.Y = pTmp.y;

     return tCord;
}

void KuszkAPI::Forms::Window::SetSize(int iSzerokosc, int iWysokosc)
{
     SetWindowPos(hUchwyt, hOwner, 0, 0, iSzerokosc, iWysokosc, SWP_NOMOVE | SWP_NOZORDER);

     UpdateWindow(hOwner);
}

KuszkAPI::Forms::Window::Cord KuszkAPI::Forms::Window::GetSize(void) const
{
     Cord tTmp;
     RECT rTmp;

     GetWindowRect(hUchwyt, &rTmp);

     tTmp.X = rTmp.right - rTmp.left;
     tTmp.Y = rTmp.bottom - rTmp.top;

     return tTmp;
}

void KuszkAPI::Forms::Window::SetRegion(HRGN hRegion)
{
     SetWindowRgn(hUchwyt, hRegion, true);
}

void KuszkAPI::Forms::Window::SetTopMost(bool bTop)
{
     SetWindowPos(hUchwyt, bTop ? HWND_TOPMOST : HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void KuszkAPI::Forms::Window::SetWndLong(int iId, unsigned uWartosc)
{
     SetWindowLong(hUchwyt, iId, uWartosc);
}

unsigned KuszkAPI::Forms::Window::GetWndlong(int iId) const
{
     return GetWindowLong(hUchwyt, iId);
}

void KuszkAPI::Forms::Window::SetClaLong(int iId, unsigned uWartosc)
{
     SetClassLong(hUchwyt, iId, uWartosc);
}

unsigned KuszkAPI::Forms::Window::GetClaLong(int iId) const
{
     return GetClassLong(hUchwyt, iId);
}

KuszkAPI::Forms::Window::operator const HWND& (void) const
{
     return hUchwyt;
}

void KuszkAPI::Forms::Window::Destroy(void)
{
     if (hUchwyt){

          DestroyWindow(hUchwyt);

          hUchwyt = NULL;

     }
}

void KuszkAPI::Forms::Window::SetWndName(HWND hWnd, const Containers::String& sName)
{
     SetWindowText(hWnd, sName.Str());
}

Containers::String KuszkAPI::Forms::Window::GetWndName(HWND hWnd)
{
     unsigned uTmp = GetWindowTextLength(hWnd) + 1;

     TCHAR cBufor[uTmp + 1];

     GetWindowText(hWnd, cBufor, uTmp);

     cBufor[uTmp] = 0;

     return cBufor;
}
