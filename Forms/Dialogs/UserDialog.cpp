using namespace KuszkAPI;

KuszkAPI::Forms::UserDialog::UserDialog(const HWND& hOwn)
: Window(hOwn), Control(hUchwyt)
{
      pvResult = NULL;
}

KuszkAPI::Forms::UserDialog::~UserDialog(void)
{
      Destroy();
}

HWND KuszkAPI::Forms::UserDialog::Create(const Containers::String& cRes, DLGPROC pfDlgProc, bool bModalDial)
{
      Destroy();
      bModal = bModalDial;
      hUchwyt = CreateDialog(GetModuleHandle(NULL), cRes.Str(), hOwner, pfDlgProc);
      if (bModal){
              EnableWindow(hOwner, false);
              SetPos();
      }
      ShowWindow(hUchwyt, SW_SHOW);
      SendMessage(hUchwyt, WM_CREATEWINDOW, 0, 0);
      return hUchwyt;
}

void KuszkAPI::Forms::UserDialog::Close(void* pvReturn)
{
      Destroy();
}

void* KuszkAPI::Forms::UserDialog::GetResult(void) const
{
      return pvResult;
}

void KuszkAPI::Forms::UserDialog::SetModal(bool bNewModal)
{
      bModal = bNewModal;
      if (hOwner) EnableWindow(hOwner, !bModal);
}

bool KuszkAPI::Forms::UserDialog::GetModal(void) const
{
      return bModal;
}

void KuszkAPI::Forms::UserDialog::SetTitle(const Containers::String& sTekst)
{
      Window::SetWndName(hUchwyt, sTekst);
}

Containers::String KuszkAPI::Forms::UserDialog::GetTitle(void) const
{
      return Window::GetWndName(hUchwyt);
}

void KuszkAPI::Forms::UserDialog::Destroy(void)
{
      if (hUchwyt){
              Clean();
              DestroyWindow(hUchwyt);
              SetModal(false);
              hUchwyt = NULL;
      }
}

void KuszkAPI::Forms::UserDialog::Clean(void)
{
      Control.Clean();
}
