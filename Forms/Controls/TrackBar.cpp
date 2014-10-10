using namespace KuszkAPI;

KuszkAPI::Forms::TrackBar::TrackBar(const HWND& hOwn, unsigned uCtrId) : BarControl(hOwn, uCtrId) {}

const HWND& KuszkAPI::Forms::TrackBar::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, short iStart, short iStop, unsigned uStep, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
     Destroy();

     iMin = iStart;
     iMax = iStop;

     hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), NULL, uStyl | WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);

	if (hUchwyt){

		SendMessage(hUchwyt, TBM_SETRANGE, (WPARAM) TRUE, (LPARAM) MAKELONG(iMin, iMax));
		SendMessage(hUchwyt, TBM_SETPAGESIZE, 0, (LPARAM) uStep);

	}

     return hUchwyt;
}

void KuszkAPI::Forms::TrackBar::SetValue(unsigned uValue)
{
	SendMessage(hUchwyt, TBM_SETPOS, (WPARAM) TRUE, (LPARAM) uValue);
}

unsigned KuszkAPI::Forms::TrackBar::GetValue(void) const
{
	return SendMessage(hUchwyt, TBM_GETPOS, 0, 0);
}
