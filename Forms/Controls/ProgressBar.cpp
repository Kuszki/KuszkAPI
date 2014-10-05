using namespace KuszkAPI;

KuszkAPI::Forms::ProgressBar::ProgressBar(const HWND& hOwn, unsigned uCtrId) : BarControl(hOwn, uCtrId) {}

HWND KuszkAPI::Forms::ProgressBar::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, unsigned short uStart, unsigned short uStop, unsigned uStep, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
     Destroy();

     uMin = uStart;
     uMax = uStop;

     hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), NULL, uStyl | WS_VISIBLE | WS_CHILD | PBS_SMOOTH | PBS_SMOOTHREVERSE, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);

	if (hUchwyt){

		SendMessage(hUchwyt, PBM_SETRANGE, 0, (LPARAM) MAKELONG(uMin, uMax));
		SendMessage(hUchwyt, PBM_SETSTEP, (WPARAM) uStep, 0);

	}

     return hUchwyt;
}

void KuszkAPI::Forms::ProgressBar::SetValue(unsigned uValue)
{
	SendMessage(hUchwyt, PBM_SETPOS, (WPARAM) uValue, 0);
}

unsigned KuszkAPI::Forms::ProgressBar::GetValue(void) const
{
	return SendMessage(hUchwyt, PBM_GETPOS, 0, 0);
}

void KuszkAPI::Forms::ProgressBar::SetProgress(float fProgress)
{
	SendMessage(hUchwyt, PBM_SETPOS, (WPARAM) (fProgress * (uMax - uMin)), 0);
}

float KuszkAPI::Forms::ProgressBar::GetProgress(void) const
{
	return ((float) SendMessage(hUchwyt, PBM_GETPOS, 0, 0)) / (uMax - uMin);
}

void KuszkAPI::Forms::ProgressBar::Increment(int iValue)
{
	if (!iValue) SendMessage(hUchwyt, PBM_STEPIT, 0, 0); else SendMessage(hUchwyt, PBM_DELTAPOS, (WPARAM) iValue, 0);
}
