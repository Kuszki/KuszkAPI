using namespace KuszkAPI;

KuszkAPI::Forms::ListBox::ListBox(const HWND& hOwn, unsigned uCrtId) : ListControl(hOwn, uCrtId) {}

const HWND& KuszkAPI::Forms::ListBox::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, const Containers::Strings& sLista, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), TEXT("Containers::ListContainers::Box"), uStyl | WS_VISIBLE | WS_CHILD | WS_BORDER, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);
      SetFont();
      AddItems(sLista);
      return hUchwyt;
}

void KuszkAPI::Forms::ListBox::AddItem(const Containers::String& sTekst)
{
      if (sTekst) ListBox_AddString(hUchwyt, sTekst.Str());
}

void KuszkAPI::Forms::ListBox::AddItems(const Containers::Strings& sLista)
{
      for (int i = 1; i <= sLista.Capacity(); i++) AddItem(sLista.GetData(i));
}

void KuszkAPI::Forms::ListBox::DeleteItem(unsigned uNumer)
{
      if (!uNumer) uNumer = GetIndex();
      if (uNumer <= Capacity()) ListBox_DeleteString(hUchwyt, uNumer - 1);
}

void KuszkAPI::Forms::ListBox::SetItems(const Containers::Strings& sLista)
{
      Clean();

      AddItems(sLista);
}

Containers::String KuszkAPI::Forms::ListBox::GetItem(unsigned uNumer) const
{
      Containers::String sTmp;
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return sTmp;
      unsigned uCount = ListBox_GetTextLen(hUchwyt, --uNumer);
      TCHAR* pcBufor = new TCHAR[uCount + 1];
      ListBox_GetText(hUchwyt, uNumer, pcBufor);
      pcBufor[uCount] = 0;
      sTmp = pcBufor;
      delete [] pcBufor;
      return sTmp;
}

Containers::Strings KuszkAPI::Forms::ListBox::GetItems(void) const
{
      Containers::Strings sTmp;
      for (int i = 1; i <= Capacity(); i++) sTmp.Add(GetItem(i));
      return sTmp;
}

unsigned KuszkAPI::Forms::ListBox::GetIndex(void) const
{
      return ListBox_GetCurSel(hUchwyt) + 1;
}

unsigned KuszkAPI::Forms::ListBox::Capacity(void) const
{
      return ListBox_GetCount(hUchwyt);
}

void KuszkAPI::Forms::ListBox::Sort(bool bGrow)
{
      Containers::Strings sTmp = GetItems();
      sTmp.Sort(bGrow);
      SetItems(sTmp);
}

void KuszkAPI::Forms::ListBox::Clean(void)
{
      ListBox_ResetContent(hUchwyt);
}
