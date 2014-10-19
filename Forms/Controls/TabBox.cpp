using namespace KuszkAPI;

KuszkAPI::Forms::TabBox::TabBox(const HWND& hOwn, unsigned uCrtId) : ListControl(hOwn, uCrtId) {}

Forms::TabBox& KuszkAPI::Forms::TabBox::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, const Containers::Strings& sLista, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
     Destroy();

     hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), TEXT("TabBox"), uStyl | WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);

     SetFont();
     AddItems(sLista);

     return *this;
}

void KuszkAPI::Forms::TabBox::AddItem(const Containers::String& sTekst)
{
     if (sTekst){

          TCITEM iItem;

          memset(&iItem, 0, sizeof(TCITEM));

          iItem.mask = TCIF_TEXT;
          iItem.pszText = sTekst.Str();

          TabCtrl_InsertItem(hUchwyt, Capacity() + 1, &iItem);

     }
}

void KuszkAPI::Forms::TabBox::AddItems(const Containers::Strings& sLista)
{
     for (int i = 1; i <= sLista.Capacity(); i++) AddItem(sLista.GetData(i));
}

void KuszkAPI::Forms::TabBox::DeleteItem(unsigned uNumer)
{
     if (!uNumer) uNumer = GetIndex();
     if (uNumer <= Capacity()) TabCtrl_DeleteItem(hUchwyt, uNumer - 1);
}

void KuszkAPI::Forms::TabBox::SetItems(const Containers::Strings& sLista)
{
     Clean();

     AddItems(sLista);
}

void KuszkAPI::Forms::TabBox::AddControl(HWND hWnd, unsigned uTab)
{
	mWindows.Add(uTab, hWnd);
}

void KuszkAPI::Forms::TabBox::DeleteControl(HWND hWnd)
{
	mWindows.Delete(hWnd);
}

void KuszkAPI::Forms::TabBox::SetTab(unsigned uNumer)
{
	unsigned uTab = TabCtrl_GetCurSel(hUchwyt) + 1;

	if (uNumer && uTab != uNumer) TabCtrl_SetCurSel(hUchwyt, uNumer - 1), uTab = uNumer;

	for (int i = 1; i <= mWindows.Capacity(); i++) ShowWindow(mWindows.GetKey(i), (mWindows.GetDataByInt(i) == uTab) ? SW_SHOW : SW_HIDE);
}

unsigned KuszkAPI::Forms::TabBox::GetTab(void) const
{
	return TabCtrl_GetCurSel(hUchwyt) + 1;
}

Containers::String KuszkAPI::Forms::TabBox::GetItem(unsigned uNumer) const
{
     Containers::String sTmp;

     if (!uNumer) uNumer = GetIndex();
     if (uNumer > Capacity()) return sTmp;

     TCITEM iItem;

     memset(&iItem, 0, sizeof(TCITEM));

     iItem.mask = TCIF_TEXT;
     iItem.cchTextMax = MAX_PATH;
     iItem.pszText = new TCHAR[MAX_PATH];

     TabCtrl_GetItem(hUchwyt, --uNumer, &iItem);

     sTmp = iItem.pszText;

     delete [] iItem.pszText;

     return sTmp;
}

Containers::Strings KuszkAPI::Forms::TabBox::GetItems(void) const
{
     Containers::Strings sTmp;

     for (int i = 1; i <= Capacity(); i++) sTmp.Add(GetItem(i));

     return sTmp;
}

unsigned KuszkAPI::Forms::TabBox::GetIndex(void) const
{
     return TabCtrl_GetCurSel(hUchwyt) + 1;
}

unsigned KuszkAPI::Forms::TabBox::Capacity(void) const
{
     return TabCtrl_GetItemCount(hUchwyt);
}

void KuszkAPI::Forms::TabBox::Clean(void)
{
     TabCtrl_DeleteAllItems(hUchwyt);
}
