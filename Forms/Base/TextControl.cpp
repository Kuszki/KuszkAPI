using namespace KuszkAPI;

KuszkAPI::Forms::TextControl::TextControl(const HWND& hOwn, unsigned uCtrId) : Control(hOwn, uCtrId){}

void KuszkAPI::Forms::TextControl::SetText(const Containers::String& sTekst)
{
      Containers::String sTmp(sTekst);
      sTmp.Change(TEXT("\n"), TEXT("\r\n"), true);
      Window::SetWndName(hUchwyt, sTmp);
}

Containers::String KuszkAPI::Forms::TextControl::GetText(void) const
{
      return Window::GetWndName(hUchwyt);
}

KuszkAPI::Forms::TextControl::operator Containers::String (void) const
{
      return GetText();
}
