using namespace KuszkAPI;

KuszkAPI::Core::Comport::Comport(const Containers::String& sPort, unsigned uSpeed)
{
	hPort = NULL;

	if (sPort) Open(sPort, uSpeed);
}

KuszkAPI::Core::Comport::~Comport(void)
{
	Close();
}

bool KuszkAPI::Core::Comport::Open(const Containers::String& sPort, unsigned uSpeed)
{
	Containers::String sTmp;

	sTmp += TEXT("\\\\.\\");
	sTmp += sPort;

	if (hPort) Close();

	hPort = CreateFile(sTmp.Str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

	if (!hPort) return false;

	DCB dSettings;
	memset(&dSettings, 0, sizeof(DCB));
	dSettings.DCBlength = sizeof(DCB);

	COMMTIMEOUTS cTimes;
	memset(&cTimes, 0, sizeof(COMMTIMEOUTS));
	cTimes.ReadIntervalTimeout = MAXDWORD;

	sTmp.Clean();
	sTmp += TEXT("baud=");
	sTmp += uSpeed;
	sTmp += TEXT(" data=8 parity=N stop=1 dtr=on rts=on");

	if (SetCommTimeouts(hPort, &cTimes)) if (BuildCommDCBA(sTmp.Str(), &dSettings)) if (SetCommState(hPort, &dSettings)) return true, WriteFile(hPort, (LPVOID) "", 1, (LPDWORD) &uSpeed, NULL);

	Close();

	return false;
}

void KuszkAPI::Core::Comport::Close(void)
{
	CloseHandle(hPort);

	hPort = NULL;
}

bool KuszkAPI::Core::Comport::Opened(void) const
{
	return hPort;
}

bool KuszkAPI::Core::Comport::Closed(void) const
{
	return !hPort;
}

Containers::String KuszkAPI::Core::Comport::ReadString(char cStop)
{
	if (Closed()) return Containers::String();

	Containers::String sOut;

	char	cBuff	=	0;
	int	uBytes	=	0;

	while (true)
	{
		ReadFile(hPort, (LPVOID) &cBuff, 1, (LPDWORD) &uBytes, NULL);

		if (uBytes) if (cBuff != cStop) sOut += cBuff; else return sOut;

		Sleep(1);
	}
}

unsigned KuszkAPI::Core::Comport::WriteString(const Containers::String& sStr)
{
	if (Closed()) return 0;

	unsigned uBytes = 0;

	WriteFile(hPort, (LPVOID) sStr.Ascii(), sStr.Capacity(), (LPDWORD) &uBytes, NULL);

	return uBytes;
}

template<typename tnData>
unsigned KuszkAPI::Core::Comport::ReadData(tnData& tData)
{
	if (Closed()) return tnData();

	char	pcBuff[sizeof(tnData)];
	unsigned	uBytes	=	0;
	unsigned	uRead	=	0;

	while (uRead != sizeof(tnData))
	{
		ReadFile(hPort, (LPVOID) (pcBuff + uRead), sizeof(tnData) - uRead, (LPDWORD) &uBytes, NULL);

		uRead += uBytes;

		Sleep(1);
	}

	memcpy(&tData, pcBuff, sizeof(tnData));

	return uRead;
}

template<typename tnData>
unsigned KuszkAPI::Core::Comport::WriteData(const tnData& tData)
{
	if (Closed()) return 0;

	unsigned uBytes = 0;

	WriteFile(hPort, (LPVOID) &tData, sizeof(tData), (LPDWORD) &uBytes, NULL);

	return uBytes;
}

Core::Comport& KuszkAPI::Core::Comport::operator<< (const Containers::String& sMessage)
{
	WriteString(sMessage);

	return *this;
}

Core::Comport& KuszkAPI::Core::Comport::operator>> (Containers::String& sMessage)
{
	sMessage = ReadString();

	return *this;
}

Core::Comport::operator bool (void) const
{
	return hPort;
}
