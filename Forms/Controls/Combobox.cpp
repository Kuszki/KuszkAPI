using namespace KuszkAPI;

KuszkAPI::Forms::ComboBox::ComboBox(const HWND& hOwn, unsigned uCrtId) : ListControl(hOwn, uCrtId), Icons(16, 16) {}

const HWND& KuszkAPI::Forms::ComboBox::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, const Containers::Strings& sLista, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), TEXT("ComboContainers::Box"), uStyl | WS_VISIBLE | WS_CHILD, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);
      SetFont();
      SetItems(sLista);
      return hUchwyt;
}

void KuszkAPI::Forms::ComboBox::AddItem(const Containers::String& sTekst, unsigned uIkona)
{
      if (!sTekst) return;
      COMBOBOXEXITEM cItem;
      memset(&cItem, 0, sizeof(COMBOBOXEXITEM));
      cItem.mask = CBEIF_TEXT | CBEIF_IMAGE;
      cItem.iItem = -1;
      cItem.pszText = sTekst.Str();
      cItem.iImage = uIkona;
      SendMessage(hUchwyt, CBEM_INSERTITEM, 0, (LPARAM) &cItem);
}

void KuszkAPI::Forms::ComboBox::AddItems(const Containers::Strings& sLista, unsigned uIkona)
{
      for (int i = 1; i < sLista.Capacity(); i++) AddItem(sLista.GetData(i), uIkona);
}

void KuszkAPI::Forms::ComboBox::DeleteItem(unsigned uNumer)
{
      SendMessage(hUchwyt, CBEM_DELETEITEM, uNumer - 1, 0);
}

void KuszkAPI::Forms::ComboBox::SetItem(const Containers::String& sTekst, unsigned uNumer)
{
      if (!sTekst) return;
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return;
      COMBOBOXEXITEM cItem;
      memset(&cItem, 0, sizeof(COMBOBOXEXITEM));
      cItem.mask = CBEIF_TEXT;
      cItem.iItem = uNumer - 1;
      cItem.pszText = sTekst.Str();
      SendMessage(hUchwyt, CBEM_SETITEM, 0, (LPARAM) &cItem);
}

void KuszkAPI::Forms::ComboBox::SetItems(const Containers::Strings& sLista, unsigned uIkona)
{
      Clean();

      for (int i = 1; i <= sLista.Capacity(); i++) AddItem(sLista.GetData(i), uIkona);
}

Containers::String KuszkAPI::Forms::ComboBox::GetItem(unsigned uNumer) const
{
      return GetItemStruct(uNumer).Name;
}

Containers::Strings KuszkAPI::Forms::ComboBox::GetItems(void) const
{
      unsigned uCount = Capacity();
      Containers::Strings sBufor;
      for (int i = 1; i <= uCount; i++) sBufor.Add(GetItem(i));
      return sBufor;
}

KuszkAPI::Forms::ComboBox::ItemData KuszkAPI::Forms::ComboBox::GetItemStruct(unsigned uNumer) const
{
      ItemData tBufor;
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return tBufor;
      COMBOBOXEXITEM cItem;
      memset(&cItem, 0, sizeof(COMBOBOXEXITEM));
      cItem.mask = CBEIF_TEXT | CBEIF_IMAGE;
      cItem.iItem = uNumer - 1;
      cItem.pszText = new TCHAR[MAX_PATH];
      cItem.cchTextMax = MAX_PATH;
      SendMessage(hUchwyt, CBEM_GETITEM, 0, (LPARAM) &cItem);
      tBufor.Name = cItem.pszText;
      tBufor.Icon = cItem.iImage;
      delete [] cItem.pszText;
      return tBufor;
}

void KuszkAPI::Forms::ComboBox::SetItemIcon(unsigned uIkona, unsigned uNumer)
{
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return;
      COMBOBOXEXITEM cItem;
      memset(&cItem, 0, sizeof(COMBOBOXEXITEM));
      cItem.mask = CBEIF_IMAGE;
      cItem.iItem = uNumer - 1;
      cItem.iImage = uIkona;
      SendMessage(hUchwyt, CBEM_SETITEM, 0, (LPARAM) &cItem);
}

unsigned KuszkAPI::Forms::ComboBox::GetItemIcon(unsigned uNumer) const
{
      return GetItemStruct(uNumer).Icon;
}

void KuszkAPI::Forms::ComboBox::SetImages(bool bEnable)
{
      if (bEnable) SendMessage(hUchwyt, CBEM_SETIMAGELIST, 0, (LPARAM) Icons.GetHandle()); else SendMessage(hUchwyt, CBEM_SETIMAGELIST, 0, 0);
}

unsigned KuszkAPI::Forms::ComboBox::GetIndex(void) const
{
      return ComboBox_GetCurSel(hUchwyt) + 1;
}

unsigned KuszkAPI::Forms::ComboBox::Capacity(void) const
{
      return ComboBox_GetCount(hUchwyt);
}

void KuszkAPI::Forms::ComboBox::Sort(bool bGrow)
{
      unsigned uCount = Capacity();
      Containers::Strings psTmp[2];
      for (int i = 1; i <= uCount; i++){
              ItemData tBufor = GetItemStruct(i);
              psTmp[0].Add(tBufor.Name);
              psTmp[1].Add(Containers::String(tBufor.Icon));
      }
      psTmp[0].Sort(psTmp, 2, bGrow);
      for (int i = 1; i <= uCount; i++){
              SetItemIcon(psTmp[1][i].Int());
              SetItem(psTmp[0][i]);
      }
}

void KuszkAPI::Forms::ComboBox::Clean(void)
{
      ComboBox_ResetContent(hUchwyt);
}
