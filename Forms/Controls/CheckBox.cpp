using namespace KuszkAPI;

KuszkAPI::Forms::CheckBox::CheckBox(const HWND& hOwn, unsigned uCrtId) : CheckControl(hOwn, uCrtId) {}

HWND KuszkAPI::Forms::CheckBox::Create(const Containers::String& sTekst, int iXPos, int iYPos, int iSzerokosc, int iWysokosc, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), sTekst.Str(), uStyl | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);
      SetFont();
      return hUchwyt;
}

void KuszkAPI::Forms::CheckBox::SetCheckBox(bool bZaznacz)
{
      Button_SetCheck(hUchwyt, bZaznacz ? BST_CHECKED : BST_UNCHECKED);
}
