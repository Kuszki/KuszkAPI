using namespace KuszkAPI;

KuszkAPI::Core::Tray::Tray(const HWND& hWnd)
: hOwner(hWnd)
{
      memset(&dData, 0, sizeof(NOTIFYICONDATA));
}

KuszkAPI::Core::Tray::~Tray(void)
{
      Delete();
}

void KuszkAPI::Core::Tray::Add(unsigned uTrayId, unsigned uTrayMsg, const Containers::String& sOpis, const Containers::String& sIkona)
{
      if (dData.uID) Delete();
      dData.cbSize = sizeof(NOTIFYICONDATA);
      dData.uFlags = NIF_MESSAGE | NIF_TIP | NIF_ICON;
      dData.hWnd = hOwner;
      dData.uID = uTrayId;
      dData.uCallbackMessage = uTrayMsg;
      dData.hIcon = LoadIcon(GetModuleHandle(NULL), sIkona.Str());
      memcpy(dData.szTip, sOpis.Str(), sizeof(dData.szTip) / sizeof(TCHAR) < sOpis.Capacity() ? sizeof(dData.szTip) : sOpis.Capacity() * sizeof(TCHAR));
      Shell_NotifyIcon(NIM_ADD, &dData);
}

void KuszkAPI::Core::Tray::Set(const Containers::String& sOpis, const Containers::String& sIkona)
{
      dData.uFlags = 0;
      if (sOpis){
              dData.uFlags |= NIF_TIP;
              memcpy(dData.szTip, sOpis.Str(), sizeof(dData.szTip) / sizeof(TCHAR) < sOpis.Capacity() ? sizeof(dData.szTip) : sOpis.Capacity() * sizeof(TCHAR));
      }
      if (sIkona){
              if (dData.hIcon) DeleteObject(dData.hIcon);
              dData.uFlags |= NIF_ICON;
              dData.hIcon = LoadIcon(GetModuleHandle(NULL), sIkona.Str());
      }
      if (sOpis || sIkona) Shell_NotifyIcon(NIM_MODIFY, &dData);
}

void KuszkAPI::Core::Tray::Delete(void)
{
      if (dData.hIcon) DeleteObject(dData.hIcon);
      Shell_NotifyIcon(NIM_DELETE, &dData);
      memset(&dData, 0, sizeof(NOTIFYICONDATA));
}

void KuszkAPI::Core::Tray::Msg(const Containers::String& sTytul, const Containers::String& sTekst, int iIkona) const
{
      NOTIFYICONDATA dTmp;
      memcpy(&dTmp, &dData, sizeof(NOTIFYICONDATA));
      if (dData.uID){
              dTmp.uFlags = NIF_INFO;
              dTmp.dwInfoFlags = iIkona;
              memcpy(dTmp.szInfoTitle, sTytul.Str(), sizeof(dTmp.szInfoTitle) / sizeof(TCHAR) < sTytul.Capacity() ? sizeof(dTmp.szInfoTitle) : sTytul.Capacity() * sizeof(TCHAR));
              memcpy(dTmp.szInfo, sTekst.Str(), sizeof(dTmp.szInfo) / sizeof(TCHAR) < sTekst.Capacity() ? sizeof(dTmp.szInfo) : sTekst.Capacity() * sizeof(TCHAR));
              Shell_NotifyIcon(NIM_MODIFY, &dTmp);
      }
}

unsigned KuszkAPI::Core::Tray::GetId(void) const
{
      return dData.uID;
}

unsigned KuszkAPI::Core::Tray::GetMsg(void) const
{
      return dData.uCallbackMessage;
}
