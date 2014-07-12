using namespace KuszkAPI;

Containers::Box<KuszkAPI::Forms::RadioBox::ItemData> KuszkAPI::Forms::RadioBox::bData = Containers::Box<KuszkAPI::Forms::RadioBox::ItemData>();

KuszkAPI::Forms::RadioBox::RadioBox(const HWND& hOwn, unsigned uCrtId)
: CheckBoxControl(hOwn, uCrtId)
{
      uGroupId = 0;
}

KuszkAPI::Forms::RadioBox::~RadioBox(void)
{
      for (int i = 1; i <= bData.Capacity(); i++) if (bData[i].hUchwyt == hUchwyt) bData.Delete(i);
}

HWND KuszkAPI::Forms::RadioBox::Create(const Containers::String& sTekst, unsigned uGrpId, int iXPos, int iYPos, int iSzerokosc, int iWysokosc, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      uGroupId = uGrpId;
      hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), sTekst.Str(), uStyl | WS_VISIBLE | WS_CHILD | BS_RADIOBUTTON, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);
      ItemData tTmp = {hUchwyt, hOwner, uGroupId};
      bData.Add(tTmp);
      SetFont();
      return hUchwyt;
}

unsigned KuszkAPI::Forms::RadioBox::GetGroupId(void) const
{
      return uGroupId;
}

void KuszkAPI::Forms::RadioBox::SetCheckBox(bool bZaznacz)
{
      if (GetCheck()) return;
      for (int i = 1; i <= bData.Capacity(); i++) if (bData[i].hUchwyt != hUchwyt && bData[i].hOwner == hOwner && bData[i].uGroupId == uGroupId) Button_SetCheck(bData[i].hUchwyt, BST_UNCHECKED);
      Button_SetCheck(hUchwyt, bZaznacz ? BST_CHECKED : BST_UNCHECKED);
}
