using namespace std;

KuszkAPI::Forms::Form::Form(const HWND& hOwn)
: Window(hOwn), Control(hUchwyt)
{
      memset(&Class, 0, sizeof(WNDCLASSEX));
      hMenu = NULL;
}

KuszkAPI::Forms::Form::~Form(void)
{
      Destroy();
}

void KuszkAPI::Forms::Form::New(const Containers::String& sNazwaKlasy, const Containers::String& sNazwaOkna, WNDPROC pfProc, unsigned uStyl, HBRUSH hKolor)
{
      Destroy();
      sClassName = sNazwaKlasy;
      sWindowName = sNazwaOkna;
      Class.hInstance = GetModuleHandle(NULL);
      Class.lpszClassName = sClassName.Str();
      Class.lpfnWndProc = pfProc;
      Class.style = uStyl;
      Class.cbSize = sizeof(WNDCLASSEX);
      Class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
      Class.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
      Class.hCursor = LoadCursor(NULL, IDC_ARROW);
      Class.lpszMenuName = NULL;
      Class.cbClsExtra = 0;
      Class.cbWndExtra = 0;
      Class.hbrBackground = hKolor;
}

HWND KuszkAPI::Forms::Form::Create(unsigned uExStyl, unsigned uStyl, HMENU hMenuGl, int iSzerokosc, int iWysokosc, int iXPos, int iYPos)
{
      hMenu = hMenuGl;
      if (hUchwyt) DestroyWindow(hUchwyt);
      hUchwyt = CreateWindowEx(uExStyl, sClassName.Str(), sWindowName.Str(), uStyl, iXPos, iYPos, iSzerokosc, iWysokosc, HWND_DESKTOP, hMenuGl, GetModuleHandle(NULL), NULL);
      SendMessage(hUchwyt, WM_CREATEWINDOW, 0, 0);
      return hUchwyt;
}

bool KuszkAPI::Forms::Form::Register(void)
{
      UnregisterClass(sClassName.Str(), GetModuleHandle(NULL));
      return RegisterClassEx(&Class);
}

void KuszkAPI::Forms::Form::SetTitle(const Containers::String& sTekst)
{
      Window::SetWndName(hUchwyt, sTekst);
}

Containers::String KuszkAPI::Forms::Form::GetTitle(void) const
{
      return Window::GetWndName(hUchwyt);
}

HMENU KuszkAPI::Forms::Form::GetMenu(void) const
{
      return hMenu;
}

void KuszkAPI::Forms::Form::Destroy(void)
{
      if (hUchwyt){
              Clean();
              DestroyWindow(hUchwyt);
              hUchwyt = NULL;
      }
}

void KuszkAPI::Forms::Form::Clean(void)
{
      Control.Clean();
}
