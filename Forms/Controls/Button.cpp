using namespace KuszkAPI;

KuszkAPI::Forms::Button::Button(const HWND& hOwn, unsigned uCrtId) : TextControl(hOwn, uCrtId) {}

const HWND& KuszkAPI::Forms::Button::Create(const Containers::String& sTekst, int iXPos, int iYPos, int iSzerokosc, int iWysokosc, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), sTekst.Str(), uStyl | WS_VISIBLE | WS_CHILD | BS_MULTILINE, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);
      SetFont();
      return hUchwyt;
}
