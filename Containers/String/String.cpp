using namespace KuszkAPI;

unsigned KuszkAPI::Containers::String::uFormat = 10;

KuszkAPI::Containers::String::String(const String& sString)
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	if (sString.uIlosc) Add(sString.pcData);
}

KuszkAPI::Containers::String::String(const TCHAR pcString[])
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	Add(pcString);
}

KuszkAPI::Containers::String::String(const DCHAR pcString[])
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	Add(pcString);
}

KuszkAPI::Containers::String::String(const void* pvVoid)
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	TCHAR* pcTmp = new TCHAR[MAX_PATH];

	memset(pcTmp, 0, MAX_PATH);

	LongToStr((unsigned) pvVoid, pcTmp, 16);

	Add(TEXT("0x"));
	Add(pcTmp);

	delete [] pcTmp;
}

KuszkAPI::Containers::String::String(unsigned uUnsigned)
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	TCHAR* pcTmp = new TCHAR[MAX_PATH];

	memset(pcTmp, 0, MAX_PATH);

	UnsToStr(uUnsigned, pcTmp, uFormat);

	if (uFormat == 16) Add(TEXT("0x"));
	if (uFormat == 8) Add(TEXT('0'));

	Add(pcTmp);

	delete [] pcTmp;
}

KuszkAPI::Containers::String::String(int iInt)
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	TCHAR* pcTmp = new TCHAR[64];

	LongToStr(iInt, pcTmp, uFormat);

	if (uFormat == 16) Add(TEXT("0x"));
	if (uFormat == 8) Add(TEXT('0'));

	Add(pcTmp);

	delete [] pcTmp;
}

KuszkAPI::Containers::String::String(TCHAR cChar)
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;

	Add(cChar);
}

KuszkAPI::Containers::String::String(void)
{
	uDataSize = sizeof(TCHAR);

	pcData = NULL;
	pcBufor = NULL;
	pcConvert = NULL;

	uIlosc = 0;
	cAbstract = 0;
}

KuszkAPI::Containers::String::~String(void)
{
	Clean();
}

unsigned KuszkAPI::Containers::String::Add(TCHAR cChar, int iPos, bool bMode)
{
	if (iPos < 1) iPos += uIlosc;
	if (iPos > uIlosc || iPos < 0) return uIlosc;
	else if (pcData){

		TCHAR* pcTmp = new TCHAR[uIlosc + 2];

		if (!bMode) iPos--;

		if (iPos == uIlosc){

			memcpy(pcTmp, pcData, uDataSize * uIlosc);

			pcTmp[uIlosc] = cChar;

		} else {

			memcpy(pcTmp, pcData, uDataSize * iPos);
			memcpy(pcTmp + iPos, pcData + iPos - 1, uDataSize * (uIlosc - iPos + 1));

			pcTmp[iPos] = cChar;

		}

		pcTmp[uIlosc + 1] = 0;

		delete [] pcData;

		pcData = pcTmp;

		uIlosc++;

	} else {

		uIlosc = 1;

		pcData = new TCHAR[2];

		pcData[0] = cChar;
		pcData[1] = 0;

	}

	return uIlosc;
}

unsigned KuszkAPI::Containers::String::Add(const TCHAR pcString[], int iPos, bool bMode)
{
	if (!pcString) return uIlosc;

	unsigned uCount = GetSize(pcString);

	if (!uCount) return uIlosc;

	if (iPos < 1) iPos += uIlosc;
	if (iPos > uIlosc || iPos < 0) return uIlosc;
	else if (pcData){

		TCHAR* pcTmp = new TCHAR[uIlosc + uCount + 1];

		if (!bMode) iPos--;

		if (iPos == uIlosc){

			memcpy(pcTmp, pcData, uDataSize * uIlosc);
			memcpy(pcTmp + uIlosc, pcString, uDataSize * uCount);

		} else {

			memcpy(pcTmp, pcData, uDataSize * iPos);
			memcpy(pcTmp + iPos, pcString, uDataSize * uCount);
			memcpy(pcTmp + uCount + iPos, pcData + iPos, uDataSize * (uIlosc - iPos + 1));

		}

		pcTmp[uIlosc + uCount] = 0;

		delete [] pcData;

		pcData = pcTmp;

		uIlosc += uCount;

	} else {

		pcData = new TCHAR[uCount + 1];

		memcpy(pcData, pcString, uDataSize * uCount);

		pcData[uCount] = 0;

		uIlosc = uCount;
	}

	return uIlosc;
}

unsigned KuszkAPI::Containers::String::Add(const DCHAR pcString[], int iPos, bool bMode)
{
	if (!pcString) return uIlosc;

	if (sizeof(TCHAR) == sizeof(char)){

		unsigned uCount = StrLenW((wchar_t*) pcString);

		if (!uCount) return uIlosc;

		char pcBufor[uCount + 1];

		WideCharToMultiByte(CP_ACP, 0, (wchar_t*) pcString, uCount, pcBufor, uCount, NULL, NULL);

		pcBufor[uCount] = 0;

		return Add((TCHAR*) pcBufor, iPos, bMode);

	} else if (sizeof(TCHAR) == sizeof(wchar_t)){

		unsigned uCount = StrLenA((char*) pcString);

		if (!uCount) return uIlosc;

		wchar_t pcBufor[uCount + 1];

		MultiByteToWideChar(CP_ACP, 0, (char*) pcString, uCount, pcBufor, uCount);

		pcBufor[uCount] = 0;

		return Add((TCHAR*) pcBufor, iPos, bMode);

	}
}

unsigned KuszkAPI::Containers::String::Delete(TCHAR cChar, bool bAll)
{
	if (!uIlosc) return false;

	unsigned uTmp = Find(cChar);
	unsigned uCount = 0;

	while (uTmp){

		TCHAR* pcTmp = new TCHAR[uIlosc];

		memcpy(pcTmp, pcData, uDataSize * (uTmp - 1));
		memcpy(pcTmp + uTmp - 1, pcData + uTmp, uDataSize * (uIlosc - uTmp));

		pcTmp[--uIlosc] = 0;

		delete [] pcData;

		pcData = pcTmp;

		if (!bAll) return true;

		uTmp = Find(cChar);

		uCount++;

	}

	return uCount;
}

unsigned KuszkAPI::Containers::String::Delete(const String& sString, bool bAll)
{
	if (!uIlosc) return false;

	unsigned uTmp = Find(sString);
	unsigned uCount = 0;

	while (uTmp){

		TCHAR* pcTmp = new TCHAR[uIlosc - sString.uIlosc + 1];

		memcpy(pcTmp, pcData, uDataSize * (uTmp - 1));
		memcpy(pcTmp + uTmp - 1, pcData + uTmp + sString.uIlosc - 1, uDataSize * (uIlosc - uTmp - sString.uIlosc + 1));

		uIlosc -= sString.uIlosc;

		pcTmp[uIlosc] = 0;

		delete [] pcData;

		pcData = pcTmp;

		if (!bAll) return true;

		uTmp = Find(sString);

		uCount++;

	}

	return uCount;
}

unsigned KuszkAPI::Containers::String::Delete(int iNumer)
{
	if (iNumer < 1) iNumer += uIlosc;
	if (iNumer > uIlosc || iNumer <= 0) return false;

	TCHAR* pcTmp = new TCHAR[--uIlosc];

	memcpy(pcTmp, pcData, uDataSize * (iNumer - 1));
	memcpy(pcTmp + iNumer - 1, pcData + iNumer, uDataSize * (uIlosc - iNumer + 1));

	pcTmp[uIlosc] = 0;

	delete [] pcData;

	pcData = pcTmp;

	return uIlosc;
}

const TCHAR& KuszkAPI::Containers::String::GetData(int iNumer) const
{
	if (iNumer < 1) iNumer += uIlosc;
	if (iNumer > uIlosc || iNumer <= 0) return cAbstract; else return pcData[iNumer - 1];
}

TCHAR KuszkAPI::Containers::String::GetFirst(void) const
{
	if (uIlosc) return pcData[0]; else return 0;
}

TCHAR KuszkAPI::Containers::String::GetLast(void) const
{
	if (uIlosc) return pcData[uIlosc - 1]; else return 0;
}

unsigned KuszkAPI::Containers::String::Find(TCHAR cChar, unsigned uStart) const
{
	if (!uIlosc) return false;

	for (int i = uStart; i < uIlosc; i++) if (pcData[i] == cChar) return ++i;

	return false;
}

unsigned KuszkAPI::Containers::String::Find(const String& sString, unsigned uStart) const
{
	if (!uIlosc || !sString.uIlosc || uIlosc < sString.uIlosc) return false;

	for (int i = uStart; i <= uIlosc - sString.uIlosc; i++) if (!memcmp(pcData + i, sString.pcData, sString.uIlosc * uDataSize)) return ++i;

	return false;
}

Containers::String KuszkAPI::Containers::String::Part(unsigned uStart, unsigned uCount) const
{
	uStart--;

	if (!uCount || uCount > uIlosc) uCount = uIlosc - uStart;
	if (!uIlosc || uStart > uIlosc) return String();

	TCHAR* pcBufor = new TCHAR[uCount + 1];

	memcpy(pcBufor, pcData + uStart, uCount * uDataSize);

	pcBufor[uCount] = 0;

	String sTmp(pcBufor);

	delete [] pcBufor;

	return sTmp;
}

bool KuszkAPI::Containers::String::Contain(TCHAR cChar) const
{
	return Find(cChar);
}

unsigned KuszkAPI::Containers::String::Count(TCHAR cChar) const
{
	if (!uIlosc) return false;

	unsigned uCount = 0;

	for (int i = 0; i < uIlosc; i++) if (pcData[i] == cChar) uCount++;

	return uCount;
}

bool KuszkAPI::Containers::String::Change(unsigned uOne, unsigned uTwo)
{
	if (uOne == uTwo || uOne > uIlosc || uTwo > uIlosc || !uIlosc) return false;

	Container::Change(pcData[uOne], pcData[uTwo]);
}

unsigned KuszkAPI::Containers::String::Change(TCHAR cOld, TCHAR cNew, bool bAll)
{
	unsigned uTmp = Find(cOld);

	if (uTmp) if (bAll){

		unsigned uCount = 0;

		while (uTmp){

			pcData[uTmp] = cNew;
			uTmp = Find(cOld);
			uCount++;

		}

		return uCount;

	} else {

		pcData[uTmp] = cNew;

		return true;

	} else return false;
}

unsigned KuszkAPI::Containers::String::Change(const String& sOld, const String& sNew, bool bAll)
{
	if (!uIlosc) return false;

	unsigned uTmp = Find(sOld);
	unsigned uCount = 0;

	while (uTmp){

		TCHAR* pcTmp = new TCHAR[uIlosc - sOld.uIlosc + sNew.uIlosc + 1];

		memcpy(pcTmp, pcData, uDataSize * (uTmp - 1));
		memcpy(pcTmp + uTmp - 1, sNew.pcData, uDataSize * sNew.uIlosc);
		memcpy(pcTmp + uTmp + sNew.uIlosc - 1, pcData + uTmp + sOld.uIlosc - 1, uDataSize * (uIlosc - uTmp - sOld.uIlosc + 1));

		uIlosc += sNew.uIlosc - sOld.uIlosc;

		pcTmp[uIlosc] = 0;

		delete [] pcData;

		pcData = pcTmp;

		if (!bAll) return true;

		uTmp = Find(sOld, uTmp + sNew.Capacity() - 1);

		uCount++;

	}

	return uCount;
}

TCHAR* KuszkAPI::Containers::String::Str(void) const
{
	if (!uIlosc) return NULL;

	if (Compare(pcBufor, pcData)) return pcBufor;

	if (pcBufor) delete [] pcBufor;

	pcBufor = new TCHAR[uIlosc + 1];

	memcpy(pcBufor, pcData, uDataSize * uIlosc);

	pcBufor[uIlosc] = 0;

	return pcBufor;
}

DCHAR* KuszkAPI::Containers::String::Convert(void) const
{
	if (!uIlosc) return NULL;

	if (pcConvert) delete [] pcConvert;

	pcConvert = new DCHAR[uIlosc + 1];

	if (sizeof(TCHAR) == sizeof(wchar_t)) WideCharToMultiByte(CP_ACP, 0, (wchar_t*) pcData, uIlosc, (char*) pcConvert, uIlosc, NULL, NULL);
	if (sizeof(TCHAR) == sizeof(char)) MultiByteToWideChar(CP_ACP, 0, (char*) pcData, uIlosc, (wchar_t*) pcConvert, uIlosc);

	pcConvert[uIlosc] = 0;

	return pcConvert;
}

char* KuszkAPI::Containers::String::Ascii(void) const
{
	if (sizeof(TCHAR) == sizeof(wchar_t)) return (char*) Convert();
	if (sizeof(TCHAR) == sizeof(char)) return (char*) Str();
}

wchar_t* KuszkAPI::Containers::String::Unicode(void) const
{
	if (sizeof(TCHAR) == sizeof(wchar_t)) return (wchar_t*) Str();
	if (sizeof(TCHAR) == sizeof(char)) return (wchar_t*) Convert();
}

int KuszkAPI::Containers::String::Int(void) const
{
	return StrToLong(pcData);
}

unsigned KuszkAPI::Containers::String::Capacity() const
{
	return uIlosc;
}

bool KuszkAPI::Containers::String::Empty(void) const
{
	return !(bool) uIlosc;
}

void KuszkAPI::Containers::String::Clean(void)
{
	if (pcData) delete [] pcData;
	if (pcBufor) delete [] pcBufor;

	pcData = NULL;
	pcBufor = NULL;

	uIlosc = 0;
	cAbstract = 0;
}

TCHAR& KuszkAPI::Containers::String::operator[] (int iNumer)
{
	if (iNumer < 1) iNumer += uIlosc;
	if (iNumer > uIlosc || iNumer <= 0) return cAbstract; else return pcData[iNumer - 1];
}

const TCHAR& KuszkAPI::Containers::String::operator[] (int iNumer) const
{
	if (iNumer < 1) iNumer += uIlosc;
	if (iNumer > uIlosc || iNumer <= 0) return cAbstract; else return pcData[iNumer - 1];
}

Containers::String& KuszkAPI::Containers::String::operator<< (const String& sString)
{
	if (sString.uIlosc) Add(sString.pcData);

	return *this;
}

Containers::String& KuszkAPI::Containers::String::operator<< (const TCHAR pcString[])
{
	Add(pcString);

	return *this;
}

bool KuszkAPI::Containers::String::operator== (const String& sString) const
{
	if (this == &sString) return true;

	if (uIlosc != sString.uIlosc) return false;

	if (memcmp(pcData, sString.pcData, uIlosc * uDataSize)) return false;

	return true;
}

bool KuszkAPI::Containers::String::operator!= (const String& sString) const
{
	if (this == &sString) return false;

	if (uIlosc != sString.uIlosc) return true;

	if (memcmp(pcData, sString.pcData, uIlosc * uDataSize)) return true;

	return false;
}

bool KuszkAPI::Containers::String::operator> (const String& sString) const
{
	unsigned uCount = uIlosc;;

	if (uIlosc < sString.uIlosc) uCount = uIlosc; else uCount = sString.uIlosc;

	unsigned uBufor = 0;

	while (pcData[uBufor] == sString.pcData[uBufor] || uBufor >= uCount) uBufor++;

	return pcData[uBufor] > sString.pcData[uBufor];
}

bool KuszkAPI::Containers::String::operator< (const String& sString) const
{
	unsigned uCount = uIlosc;;

	if (uIlosc < sString.uIlosc) uCount = uIlosc; else uCount = sString.uIlosc;

	unsigned uBufor = 0;

	while (pcData[uBufor] == sString.pcData[uBufor] || uBufor >= uCount) uBufor++;

	return pcData[uBufor] < sString.pcData[uBufor];
}

Containers::String KuszkAPI::Containers::String::operator+ (const String& sString) const
{
	String sTmp;

	if (uIlosc) sTmp.Add(pcData);
	if (sString.uIlosc) sTmp.Add(sString.Str());

	return sTmp;
}

Containers::String KuszkAPI::Containers::String::operator+ (const TCHAR pcString[]) const
{
	String sTmp;

	if (uIlosc) sTmp.Add(pcData);

	sTmp.Add(pcString);

	return sTmp;
}

Containers::String& KuszkAPI::Containers::String::operator+= (const String& sString)
{
	if (sString.uIlosc) Add(sString.pcData);

	return *this;
}

Containers::String& KuszkAPI::Containers::String::operator+= (const TCHAR pcString[])
{
	Add(pcString);

	return *this;
}

Containers::String& KuszkAPI::Containers::String::operator= (const String& sString)
{
	if (this == &sString) return *this;

	Clean();

	Add(sString.pcData);

	return *this;
}

KuszkAPI::Containers::String::operator int (void) const
{
	return Int();
}

KuszkAPI::Containers::String::operator bool (void) const
{
	return !Empty();
}

void KuszkAPI::Containers::String::SetFormat(unsigned uFmt)
{
	if (uFmt > 1 && uFmt < 17) uFormat = uFmt;
}

unsigned KuszkAPI::Containers::String::GetFormat(void)
{
	return uFormat;
}

unsigned KuszkAPI::Containers::String::GetSize(const TCHAR pcString[])
{
	return StrLen(pcString);
}

bool KuszkAPI::Containers::String::Compare(const TCHAR pcOne[], const TCHAR pcTwo[])
{
	if (!pcOne && !pcTwo) return true;
	if (!pcOne || !pcTwo) return false;

	unsigned uCount = GetSize(pcOne);

	if (uCount != GetSize(pcTwo)) return false;
	if (memcmp(pcOne, pcTwo, uCount * sizeof(TCHAR))) return false;

	return true;
}

unsigned KuszkAPI::Containers::String::Copy(const TCHAR pcSource[], TCHAR pcDestonation[], unsigned uCount)
{
	unsigned uTmp = GetSize(pcSource);

	if (uTmp > uCount) uTmp = uCount;

	memset(pcDestonation, 0, sizeof(TCHAR) * uCount);
	memcpy(pcDestonation, pcSource, sizeof(TCHAR) * uTmp);

	return uCount;
}
