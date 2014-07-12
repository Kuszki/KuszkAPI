using namespace KuszkAPI;

KuszkAPI::Core::Instance::Instance(void)
{
      hInstance = GetModuleHandle(NULL);
      ResetPath();
}

KuszkAPI::Core::Instance::~Instance(void) {}

const HINSTANCE& KuszkAPI::Core::Instance::GetHandle(void) const
{
      return hInstance;
}

KuszkAPI::Core::Instance::operator const HINSTANCE& (void) const
{
      return hInstance;
}

Containers::String KuszkAPI::Core::Instance::GetExeFull(void)
{
      Containers::String sTmp;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      GetModuleFileName(NULL, pcBufor, MAX_PATH);
      sTmp = pcBufor;
      return sTmp;
}

Containers::String KuszkAPI::Core::Instance::GetExeName(void)
{
      Containers::String sTmp;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      unsigned uTmp = GetModuleFileName(NULL, pcBufor, MAX_PATH) - 1;
      for (bool bNext = true; uTmp >= 0 && bNext; uTmp--) if (pcBufor[uTmp] == TEXT('\\')){
              pcBufor[uTmp++] = 0;
              bNext = false;
      }
      sTmp = pcBufor + uTmp + 1;
      return sTmp;
}

Containers::String KuszkAPI::Core::Instance::GetExePath(void)
{
      Containers::String sTmp;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      unsigned uTmp = GetModuleFileName(NULL, pcBufor, MAX_PATH) - 1;
      for (bool bNext = true; uTmp >= 0 && bNext; uTmp--) if (pcBufor[uTmp] == TEXT('\\')){
              pcBufor[++uTmp] = 0;
              bNext = false;
      }
      sTmp = pcBufor;
      return sTmp;
}

void KuszkAPI::Core::Instance::SetPath(const Containers::String& sPath)
{
      if (sPath) SetCurrentDirectory(sPath.Str());
}

Containers::String KuszkAPI::Core::Instance::GetPath(void)
{
      Containers::String sTmp;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      GetCurrentDirectory(MAX_PATH, pcBufor);
      sTmp = pcBufor;
      return sTmp;
}

void KuszkAPI::Core::Instance::ResetPath(void)
{
      SetPath(GetExePath());
}

void KuszkAPI::Core::Instance::SetEnv(const Containers::String& sName, const Containers::String& sValue)
{
      Containers::String sTmp = sName + TEXT("=") + sValue;
      SETENV(sTmp.Str());
}

Containers::String KuszkAPI::Core::Instance::GetEnv(const Containers::String& sName)
{
      return Containers::String(GETENV(sName.Str()));
}
