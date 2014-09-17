using namespace KuszkAPI;

KuszkAPI::Core::Ini::Ini(const Containers::String& sFileName)
{
     if (sFileName) SetFile(sFileName);
}

KuszkAPI::Core::Ini::~Ini(void)
{
     sFile.Clean();
}

void KuszkAPI::Core::Ini::SetFile(const Containers::String& sFileName)
{
     if (sFileName.Contain(TEXT(':'))) sFile = sFileName; else{

          TCHAR* pcBufor = new TCHAR[MAX_PATH];

          unsigned uTmp = GetModuleFileName(NULL, pcBufor, MAX_PATH) - 1;

          for (bool bNext = true; uTmp >= 0 && bNext; uTmp--) if (pcBufor[uTmp] == TEXT('\\')){

               pcBufor[++uTmp] = 0;

               bNext = false;

          }

          sFile = Containers::String(pcBufor) + sFileName;

     }
}

Containers::String KuszkAPI::Core::Ini::GetFile(void) const
{
     return sFile;
}

bool KuszkAPI::Core::Ini::SetStr(const Containers::String& sSection, const Containers::String& sName, const Containers::String& sValue)
{
     if (sFile) return WritePrivateProfileString(sSection.Str(), sName.Str(), sValue.Str(), sFile.Str());
     else return false;
}

Containers::String KuszkAPI::Core::Ini::GetStr(const Containers::String& sSection, const Containers::String& sName) const
{
     Containers::String sBufor;

     if (!sFile) return sBufor;

     TCHAR* pcBufor = new TCHAR[MAX_PATH];

     unsigned uTmp = GetPrivateProfileString(sSection.Str(), sName.Str(), NULL, pcBufor, MAX_PATH, sFile.Str());

     pcBufor[uTmp] = 0;

     sBufor = pcBufor;

     delete [] pcBufor;

     return sBufor;
}

bool KuszkAPI::Core::Ini::SetInt(const Containers::String& sSection, const Containers::String& sName, int iValue)
{
     if (sFile) return WritePrivateProfileString(sSection.Str(), sName.Str(), Containers::String(iValue).Str(), sFile.Str());
     else return false;
}

int KuszkAPI::Core::Ini::GetInt(const Containers::String& sSection, const Containers::String& sName) const
{
     if (sFile) return GetPrivateProfileInt(sSection.Str(), sName.Str(), 0, sFile.Str());
     else return 0;
}

Containers::Strings KuszkAPI::Core::Ini::GetSections() const
{
     TCHAR* pcBufor = new TCHAR[MAX_PATH];

     unsigned uTmp = GetPrivateProfileString(NULL, NULL, NULL, pcBufor, MAX_PATH, sFile.Str());

     Containers::Vector<char>::Change(pcBufor, uTmp, 0, 10, true);

     pcBufor[uTmp - 1] = 0;

	return Containers::Strings(pcBufor);
}

Containers::Strings KuszkAPI::Core::Ini::GetKeys(const Containers::String& sSection) const
{
	TCHAR* pcBufor = new TCHAR[MAX_PATH];

     unsigned uTmp = GetPrivateProfileString(sSection.Str(), NULL, NULL, pcBufor, MAX_PATH, sFile.Str());

     Containers::Vector<char>::Change(pcBufor, uTmp, 0, 10, true);

     pcBufor[uTmp - 1] = 0;

	return Containers::Strings(pcBufor);
}

Containers::Map<Containers::String, Containers::String> KuszkAPI::Core::Ini::GetStrValues(const Containers::String& sSection) const
{
	Containers::Strings sKeys = GetKeys(sSection);

	Containers::Map<Containers::String, Containers::String> mValues;

	for (int i = 1; i <= sKeys.Capacity(); i++) mValues.Add(GetStr(sSection, sKeys[i]), sKeys[i]);

	return mValues;
}

Containers::Map<int, Containers::String> KuszkAPI::Core::Ini::GetIntValues(const Containers::String& sSection) const
{
	Containers::Strings sKeys = GetKeys(sSection);

	Containers::Map<int, Containers::String> mValues;

	for (int i = 1; i <= sKeys.Capacity(); i++) mValues.Add(GetInt(sSection, sKeys[i]), sKeys[i]);

	return mValues;
}

void KuszkAPI::Core::Ini::Clean(void)
{
     sFile.Clean();
}
