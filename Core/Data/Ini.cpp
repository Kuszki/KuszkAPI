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
      if (sFile) return WritePrivateProfileString(sSection.Str(), sName.Str(), sValue.Str(), sFile.Str()); else return false;
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
      if (sFile) return WritePrivateProfileString(sSection.Str(), sName.Str(), Containers::String(iValue).Str(), sFile.Str()); else return false;
}

int KuszkAPI::Core::Ini::GetInt(const Containers::String& sSection, const Containers::String& sName) const
{
      if (sFile) return GetPrivateProfileInt(sSection.Str(), sName.Str(), 0, sFile.Str()); else return 0;
}

void KuszkAPI::Core::Ini::Clean(void)
{
      sFile.Clean();
}
