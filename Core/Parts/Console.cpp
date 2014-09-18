using namespace KuszkAPI;

HWND KuszkAPI::Core::Console::hUchwyt = NULL;
HANDLE KuszkAPI::Core::Console::hIn = NULL;
HANDLE KuszkAPI::Core::Console::hOut = NULL;
unsigned KuszkAPI::Core::Console::uIlosc = 0;

KuszkAPI::Core::Console::Console(bool bShow)
{
     if (!hUchwyt){

          AllocConsole();

          SetConsoleOutputCP(28591);

          hUchwyt = GetConsoleWindow();
          hIn = GetStdHandle(STD_INPUT_HANDLE);
          hOut = GetStdHandle(STD_OUTPUT_HANDLE);

          if (!bShow) ShowWindow(hUchwyt, SW_HIDE);

          bVisible = IsWindowVisible(hUchwyt);

     } else {

          bVisible = IsWindowVisible(hUchwyt);

          ShowWindow(hUchwyt, bShow ? SW_SHOW : SW_HIDE);

     }

     uIlosc++;
}

KuszkAPI::Core::Console::~Console(void)
{
     if (!--uIlosc){

          FreeConsole();

          hUchwyt = NULL;
          hIn = NULL;
          hOut = NULL;

     } else if (!bVisible) ShowWindow(hUchwyt, SW_HIDE);
}

void KuszkAPI::Core::Console::Show(bool bShow)
{
     ShowWindow(hUchwyt, bShow ? SW_SHOW : SW_HIDE);
}

bool KuszkAPI::Core::Console::Visible(void) const
{
     return IsWindowVisible(hUchwyt);
}

bool KuszkAPI::Core::Console::Exists(void) const
{
     return hUchwyt;
}

void KuszkAPI::Core::Console::Write(const TCHAR pcTekst[], bool bEol)
{
     if (!hOut || !pcTekst) return;

     DWORD dTmp;

     WriteConsole(hOut, pcTekst, Containers::String::GetSize(pcTekst), &dTmp, NULL);

     if (bEol) WriteConsole(hOut, TEXT("\n"), 1, &dTmp, NULL);
}

void KuszkAPI::Core::Console::Write(const Containers::String& sTekst, bool bEol)
{
     if (!hOut || !sTekst) return;

     DWORD dTmp;

     WriteConsole(hOut, sTekst.Str(), sTekst.Capacity(), &dTmp, NULL);

     if (bEol) WriteConsole(hOut, TEXT("\n"), 1, &dTmp, NULL);
}

void KuszkAPI::Core::Console::Read(Containers::String& sTekst)
{
     if (!hIn) return;

     CONSOLE_SCREEN_BUFFER_INFO cInfo;

     memset(&cInfo, 0, sizeof(CONSOLE_SCREEN_BUFFER_INFO));

     GetConsoleScreenBufferInfo(hOut, &cInfo);

     TCHAR* pcBufor = new TCHAR[cInfo.dwSize.X + 1];

     DWORD dTmp;

     ReadConsole(hIn, pcBufor, cInfo.dwSize.X, &dTmp, NULL);

     pcBufor[dTmp - 2] = 0;

     sTekst = pcBufor;

     delete [] pcBufor;
}

void KuszkAPI::Core::Console::Command(const Containers::String& sCmd)
{
     system(sCmd.Ascii());
}

void KuszkAPI::Core::Console::Pause(bool bMessage)
{
     if (bMessage) system("pause"); else system("pause>nil");
}

void KuszkAPI::Core::Console::SetTitle(const Containers::String& sNazwa)
{
     SetConsoleTitle(sNazwa.Str());
}

Containers::Strings KuszkAPI::Core::Console::GetLines(unsigned uPoczatek, unsigned uKoniec) const
{
     Containers::Strings sTmp;

     if (!hIn) return sTmp;

     DWORD dTmp;
     COORD cCord;

     CONSOLE_SCREEN_BUFFER_INFO cInfo;

     memset(&cInfo, 0, sizeof(CONSOLE_SCREEN_BUFFER_INFO));

     GetConsoleScreenBufferInfo(hOut, &cInfo);

     if (uPoczatek) uPoczatek--;

     cCord.X = 0;
     cCord.Y = uPoczatek;

     if (!uKoniec || uKoniec > cInfo.dwCursorPosition.Y + 1) uKoniec = cInfo.dwCursorPosition.Y;

     for (int i = uPoczatek; i < uKoniec - 1; i++, cCord.Y++){

          unsigned uTmp = cInfo.dwSize.X - 1;

          TCHAR* pcBufor = new TCHAR[cInfo.dwSize.X + 1];

          ReadConsoleOutputCharacter(hOut, pcBufor, cInfo.dwSize.X, cCord, &dTmp);

          do if (pcBufor[uTmp] != pcBufor[uTmp - 1]){

               pcBufor[uTmp] = 0;

               uTmp = 0;

          } else if (!uTmp) pcBufor[0] = 0;

          while (uTmp--);

          sTmp.Add(pcBufor);

          delete [] pcBufor;

     }

     return sTmp;
}

const HWND& KuszkAPI::Core::Console::GetHandle(void) const
{
     return hUchwyt;
}

void KuszkAPI::Core::Console::Clean(void)
{
     system("cls");
}

Core::Console& KuszkAPI::Core::Console::operator<< (const Containers::String& sTekst)
{
     Write(sTekst, false);

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator<< (const unsigned& uUnsigned)
{
     Write(Containers::String(uUnsigned), false);

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator<< (const int& iInt)
{
     Write(Containers::String(iInt), false);

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator<< (const TCHAR& cChar)
{
     Write(Containers::String(cChar), false);

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator<< (const TCHAR pcChar[])
{
     Write(pcChar, false);

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator>> (Containers::String& sTekst)
{
     Read(sTekst);

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator>> (unsigned& uUnsigned)
{
     Containers::String sBufor;

     Read(sBufor);

     uUnsigned = sBufor.Int();

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator>> (int& iInt)
{
     Containers::String sBufor;

     Read(sBufor);

     iInt = sBufor.Int();

     return *this;
}

Core::Console& KuszkAPI::Core::Console::operator>> (TCHAR& cChar)
{
     Containers::String sBufor;

     Read(sBufor);

     cChar = sBufor[1];

     return *this;
}

Core::Console::operator const HWND& (void) const
{
     return hUchwyt;
}
