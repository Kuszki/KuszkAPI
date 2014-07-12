using namespace KuszkAPI;

KuszkAPI::Core::Reg::Reg(HKEY hStart)
{
      vBack.SetMode(MODE_HEEP);
      hKey = hStart;
}

KuszkAPI::Core::Reg::~Reg(void)
{
      Clean();
}

bool KuszkAPI::Core::Reg::Open(const Containers::String& sName)
{
      HKEY hOld = hKey;
      HKEY hTmp;
      Containers::Strings sTmp(sName, TEXT('\\'));
      if (sName.Contain(TEXT('\\'))) for (int i = 1; i <= sTmp.Capacity(); i++){
              if (RegOpenKeyEx(hKey, sTmp[i].Str(), 0, KEY_ALL_ACCESS, &hTmp)){
                       hKey = hOld;
                       return false;
              }
              if (hKey != hOld) RegCloseKey(hKey);
              hKey = hTmp;
      } else {
              bool bTmp =  !RegOpenKeyEx(hKey, sName.Str(), 0, KEY_ALL_ACCESS, &hTmp);
              if (!bTmp) return false;
              hKey = hTmp;
      }
      vBack << hOld;
      if (vBack.Capacity() > 10){
              RegCloseKey(vBack[1]);
              vBack.Delete(1);
      }
      return true;
}

void KuszkAPI::Core::Reg::Open(HKEY hStart)
{
      Clean();
      hKey = hStart;
}

bool KuszkAPI::Core::Reg::Back(void)
{
      if (vBack){
              RegCloseKey(hKey);
              vBack >> hKey;
      } else return false;
      return true;
}

bool KuszkAPI::Core::Reg::AddKey(const Containers::String& sName, bool bOpen)
{
      HKEY hTmp;
      bool bTmp = !RegCreateKeyEx(hKey, sName.Str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hTmp, NULL);
      if (bOpen) Open(sName);
      return bTmp;
}

bool KuszkAPI::Core::Reg::DeleteKey(const Containers::String& sName)
{
      return !RegDeleteKey(hKey, sName.Str());
}

bool KuszkAPI::Core::Reg::SetStr(const Containers::String& sName, const Containers::String& sValue)
{
      return !RegSetValueEx(hKey, sName.Str(), 0, REG_SZ, (LPBYTE) sValue.Str(), sValue.Capacity() + 1);
}

Containers::String KuszkAPI::Core::Reg::GetStr(const Containers::String& sName)
{
      Containers::String sBufor;
      if (!hKey) return sBufor;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      unsigned long uBufSize = sizeof(TCHAR) * MAX_PATH;
      unsigned long uRegsz = REG_SZ;
      if (RegQueryValueEx(hKey, sName.Str(), 0, &uRegsz, (LPBYTE) pcBufor, &uBufSize)){
              delete [] pcBufor;
              return sBufor;
      }
      sBufor = pcBufor;
      delete [] pcBufor;
      return sBufor;
}

bool KuszkAPI::Core::Reg::SetInt(const Containers::String& sName, unsigned uValue)
{
      if (!hKey) return false;
      return !RegSetValueEx(hKey, sName.Str(), 0, REG_DWORD, (LPBYTE) &uValue, sizeof(uValue));
}

int KuszkAPI::Core::Reg::GetInt(const Containers::String& sName)
{
      int iBufor = 0;
      if (!hKey) return iBufor;
      unsigned long uBufSize = sizeof(iBufor);
      RegQueryValueEx(hKey, sName.Str(), 0, NULL, (LPBYTE) &iBufor, &uBufSize);
      return iBufor;
}

bool KuszkAPI::Core::Reg::DeleteItem(const Containers::String& sName)
{
      if (!hKey) return false;
      return !RegDeleteValue(hKey, sName.Str());
}

void KuszkAPI::Core::Reg::Clean(void)
{
      if (hKey){
              for (int i = 1; i <= vBack.Capacity(); i++) RegCloseKey(vBack[i]);
              RegCloseKey(hKey);
              vBack.Clean();
              hKey = NULL;
      }
}
