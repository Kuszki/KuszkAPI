using namespace KuszkAPI::Application;

KuszkAPI::Application::WinApp::WinApp(bool bSingle)
: Terminal(false), Interface(Window.GetHandle()), Notification(Window.GetHandle()), Fonts(Window.GetHandle())
{
      if (bSingle){
              hMutex = CreateMutex(NULL, true, Program.GetExeName().Str());
              if (GetLastError()) ExitProcess((unsigned) -1);
      }
}

KuszkAPI::Application::WinApp::WinApp(const Containers::String& sClass, const Containers::String& sWnd)
: Terminal(false), Interface(Window.GetHandle()), Notification(Window.GetHandle()), Fonts(Window.GetHandle())
{
      HWND hTmp = FindWindow(sClass.Str(), sWnd.Str());
      if (hTmp){
              ShowWindow(hTmp, SW_RESTORE);
              ExitProcess((unsigned) -1);
      }
      hMutex = NULL;
}

KuszkAPI::Application::WinApp::~WinApp(void)
{
      if (hMutex) CloseHandle(hMutex);
}

Containers::String KuszkAPI::Application::WinApp::Debug(const Containers::String& sTekst, const Containers::String& sDate, const Containers::String& sTime, const Containers::String& sFile, const Containers::String& sFunction, const Containers::String& sLine)
{
      Containers::String sBufor;
      bool bShow = Terminal.Visible();
      if (!bShow) Terminal.Show();
      Terminal.Clean();
      Terminal.Write(TEXT("---------- Debug Info ---------->"));
      Terminal.Write(TEXT("DateTime::Date: "), false);
      Terminal.Write(sDate);
      Terminal.Write(TEXT("Time: "), false);
      Terminal.Write(sTime);
      Terminal.Write(TEXT("File: "), false);
      Terminal.Write(sFile);
      Terminal.Write(TEXT("Function: "), false);
      Terminal.Write(sFunction);
      Terminal.Write(TEXT("Line: "), false);
      Terminal.Write(sLine);
      Terminal.Write(TEXT("---------- Debug Output -------->"));
      Terminal.Write(sTekst);
      Terminal.Write(TEXT("---------- Debug Input --------->"));
      Terminal.Read(sBufor);
      Terminal.Write(TEXT("-------------------------------->"));
      if (bShow) Terminal.Show(false);
      return sBufor;
}
