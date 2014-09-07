using namespace KuszkAPI;

KuszkAPI::Forms::TableBox::TableBox(const HWND& hOwn, unsigned uCrtId)
: ListControl(hOwn, uCrtId), Imgs(48, 48), Icos(16, 16)
{
      uColumnCount = 0;
      uGroupCount = 0;
      bGroups = false;
}

KuszkAPI::Forms::TableBox::~TableBox(void)
{
      uColumnCount = 0;
      uGroupCount = 0;
}

HWND KuszkAPI::Forms::TableBox::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, const Containers::Strings& sHeader, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
     Destroy();

     hUchwyt = CreateWindowEx(uExStyl | WS_EX_CLIENTEDGE, sClass.Str(), TEXT("ListView"), uStyl | WS_VISIBLE | WS_CHILD | LVS_SHAREIMAGELISTS |
LVS_SHOWSELALWAYS, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);

     DWORD dwStyle = SendMessage(hUchwyt, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0);

     dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER;

     SendMessage(hUchwyt, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwStyle);

     SetFont();

     if (sHeader) SetHeader(sHeader);

     return hUchwyt;
}

void KuszkAPI::Forms::TableBox::AddItem(const Containers::String& sTekst, const Containers::Strings& sData, unsigned uGroup, unsigned uIkona)
{
      if (!sTekst) return;
      unsigned uTmp = ListView_GetItemCount(hUchwyt);
      LVITEM lItem;
      memset(&lItem, 0, sizeof(LVITEM));
      lItem.mask = LVIF_TEXT;
      if (uIkona){
              lItem.mask |= LVIF_IMAGE;
              lItem.iImage = uIkona - 1;
      }
      if (bGroups){
              lItem.mask |= LVIF_GROUPID;
              lItem.iGroupId = uGroup ? uGroup : (unsigned) I_GROUPIDNONE;
      }
      lItem.pszText = sTekst.Str();
      lItem.iItem = uTmp;
      uTmp = ListView_InsertItem(hUchwyt, &lItem);
      if (sData) SetItemData(sData, ++uTmp);
}

void KuszkAPI::Forms::TableBox::AddItem(const Containers::Strings& sData, unsigned uGroup, unsigned uIkona)
{
      if (!sData) return;

      unsigned uTmp = ListView_GetItemCount(hUchwyt);

      LVITEM lItem;
      memset(&lItem, 0, sizeof(LVITEM));

      lItem.mask = LVIF_TEXT;

      if (uIkona){
              lItem.mask |= LVIF_IMAGE;
              lItem.iImage = uIkona - 1;
      }

      if (bGroups){
              lItem.mask |= LVIF_GROUPID;
              lItem.iGroupId = uGroup ? uGroup : (unsigned) I_GROUPIDNONE;
      }

      lItem.iItem = uTmp;

      uTmp = ListView_InsertItem(hUchwyt, &lItem);

      for (int i = 1; i <= sData.Capacity(); i++) SetItemData(sData.GetData(i), i, uTmp + 1);
}

void KuszkAPI::Forms::TableBox::AddItems(const Containers::Strings& sData, unsigned uGroup, unsigned uIcon)
{
      for (int i = 1; i <= sData.Capacity(); i++) AddItem(sData.GetData(i), Containers::Strings(), uGroup, uIcon);
}

void KuszkAPI::Forms::TableBox::DeleteItem(unsigned uNumer)
{
      if (!uNumer) uNumer = GetIndex();
      if (uNumer <= Capacity()) ListView_DeleteItem(hUchwyt, uNumer - 1);
}

KuszkAPI::Forms::TableBox::ItemData KuszkAPI::Forms::TableBox::GetItemStruct(unsigned uNumer) const
{
      ItemData tBufor;
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return tBufor;
      LVITEM lItem;
      memset(&lItem, 0, sizeof(LVITEM));
      lItem.mask = LVIF_TEXT | LVIF_GROUPID | LVIF_IMAGE;
      lItem.pszText = new TCHAR[MAX_PATH];
      lItem.cchTextMax = MAX_PATH;
      lItem.iItem = uNumer - 1;
      ListView_GetItem(hUchwyt, &lItem);
      tBufor.Name = lItem.pszText;
      delete [] lItem.pszText;
      for (int i = 1; i < uColumnCount; i++){
              TCHAR* pcBufor = new TCHAR[MAX_PATH];
              ListView_GetItemText(hUchwyt, uNumer - 1, i, pcBufor, MAX_PATH);
              tBufor.Data.Add(pcBufor);
              delete [] pcBufor;
      }
      tBufor.Group = lItem.iGroupId;
      tBufor.Icon = lItem.iImage;
      return tBufor;
}

Containers::String KuszkAPI::Forms::TableBox::GetItem(unsigned uNumer) const
{
      Containers::String sBufor;
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return sBufor;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      ListView_GetItemText(hUchwyt, uNumer - 1, 0, pcBufor, MAX_PATH);
      sBufor = pcBufor;
      delete [] pcBufor;
      return sBufor;
}

Containers::Strings KuszkAPI::Forms::TableBox::GetItems(void) const
{
      Containers::Strings sBufor;
      unsigned uCount = Capacity();
      for (int i = 0; i < uCount; i++){
              TCHAR* pcBufor = new TCHAR[MAX_PATH];
              ListView_GetItemText(hUchwyt, i, 0, pcBufor, MAX_PATH);
              sBufor.Add(pcBufor);
              delete [] pcBufor;
      }
      return sBufor;
}

void KuszkAPI::Forms::TableBox::SetItemData(const Containers::String& sTekst, unsigned uXPos, unsigned uYPos)
{
      if (!uYPos) uYPos = GetIndex();
      if (uYPos <= Capacity()) ListView_SetItemText(hUchwyt, uYPos - 1, uXPos - 1, sTekst.Str());
}

void KuszkAPI::Forms::TableBox::SetItemData(const Containers::Strings& sData, unsigned uNumer)
{
      if (!uNumer) uNumer = GetIndex();
      if (uNumer <= Capacity()) if (sData) for (int i = 1; i <= sData.Capacity() && i < uColumnCount; i++) ListView_SetItemText(hUchwyt, uNumer - 1, i, sData.GetData(i).Str());
}

Containers::Strings KuszkAPI::Forms::TableBox::GetItemData(unsigned uNumer) const
{
      return GetItemStruct(uNumer).Data;
}

void KuszkAPI::Forms::TableBox::SetItemIcon(unsigned uIkona, unsigned uNumer)
{
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return;
      LVITEM lItem;
      memset(&lItem, 0, sizeof(LVITEM));
      lItem.mask = LVIF_IMAGE;
      lItem.iImage = uIkona - 1;
      lItem.iItem = uNumer - 1;
      ListView_SetItem(hUchwyt, &lItem);
}

unsigned KuszkAPI::Forms::TableBox::GetItemIcon(unsigned uNumer) const
{
      return GetItemStruct(uNumer).Icon;
}

void KuszkAPI::Forms::TableBox::SetItemGroup(unsigned uGroup, unsigned uNumer)
{
      if (!uNumer) uNumer = GetIndex();
      if (uNumer > Capacity()) return;
      LVITEM lItem;
      memset(&lItem, 0, sizeof(LVITEM));
      lItem.mask = LVIF_GROUPID;
      lItem.iGroupId = uGroup;
      lItem.iItem = uNumer - 1;
      ListView_SetItem(hUchwyt, &lItem);
}

unsigned KuszkAPI::Forms::TableBox::GetItemGroup(unsigned uNumer) const
{
      return GetItemStruct(uNumer).Group;
}

void KuszkAPI::Forms::TableBox::Select(unsigned uNumer)
{
	ListView_SetItemState(hUchwyt, -1, 0, LVIS_SELECTED);

	SendMessage(hUchwyt, LVM_ENSUREVISIBLE, uNumer - 1, false);

	ListView_SetItemState(hUchwyt, uNumer - 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);

	Focus();
}

void KuszkAPI::Forms::TableBox::AddGroup(const Containers::String& sGroup)
{
      if (!bGroups){
              bGroups = true;
              ListView_EnableGroupView(hUchwyt, true);
      }
      LVGROUP gInfo;
      memset(&gInfo, 0, sizeof(LVGROUP));
      gInfo.cbSize = sizeof(LVGROUP);
      gInfo.mask = LVGF_HEADER | LVGF_GROUPID | LVGF_STATE;
      gInfo.pszHeader = sGroup.Unicode();
      gInfo.iGroupId = ++uGroupCount;
      gInfo.state = LVGS_COLLAPSIBLE;
      ListView_InsertGroup(hUchwyt, -1, &gInfo);
}

void KuszkAPI::Forms::TableBox::AddGroups(const Containers::Strings& sGroups)
{
      for (int i = 1; i <= sGroups.Capacity(); i++) AddGroup(sGroups.GetData(i));
}

void KuszkAPI::Forms::TableBox::DeleteGroup(unsigned uNumer)
{
      ListView_RemoveGroup(hUchwyt, uNumer);
}

void KuszkAPI::Forms::TableBox::SetGroup(const Containers::String& sGroup, unsigned uNumer)
{
      LVGROUP gInfo;
      memset(&gInfo, 0, sizeof(LVGROUP));
      gInfo.cbSize = sizeof(LVGROUP);
      gInfo.mask = LVGF_HEADER;
      gInfo.pszHeader = sGroup.Unicode();
      ListView_SetGroupInfo(hUchwyt, uNumer, &gInfo);
}

void KuszkAPI::Forms::TableBox::SetColumn(const Containers::Strings& sLista, unsigned uNumer)
{
      int iTmp = GetColumn(uNumer).Capacity();
      for (int i = 1; i <= sLista.Capacity() && i <= iTmp; i++) SetItemData(sLista.GetData(i), uNumer, i);
}

Containers::Strings KuszkAPI::Forms::TableBox::GetColumn(unsigned uNumer) const
{
      Containers::Strings sBufor;
      if (uNumer > uColumnCount) return sBufor; else uNumer--;
      for (int i = 0; i < Capacity(); i++){
              TCHAR* pcBufor = new TCHAR[MAX_PATH];
              ListView_GetItemText(hUchwyt, i, uNumer, pcBufor, MAX_PATH);
              sBufor.Add(pcBufor);
              delete [] pcBufor;
      }
      return sBufor;
}

void KuszkAPI::Forms::TableBox::SetHeader(const Containers::Strings& sHeader, const Containers::Vector<unsigned> vSizes, const Containers::Vector<unsigned> vIcos)
{
     CleanHeader();
     uColumnCount = sHeader.Capacity();

     for (int i = 1; i <= uColumnCount; i++){

          LVCOLUMN lColumn;
		memset(&lColumn, 0, sizeof(LVCOLUMN));

          lColumn.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;

          if (vIcos.Capacity() >= i){

               lColumn.mask |= LVCF_IMAGE;
               lColumn.iImage = vIcos.GetData(i) ? vIcos.GetData(i) - 1 : 0;

          }

          lColumn.iSubItem = i - 1;
          lColumn.cx = vSizes.Capacity() >= i ? vSizes.GetData(i) : 100;
          lColumn.pszText = sHeader.GetData(i).Str();

          ListView_InsertColumn(hUchwyt, i - 1, &lColumn);

     }
}

void KuszkAPI::Forms::TableBox::SetImages(bool bSmallEnable, bool bLargeEnable)
{
      if (bSmallEnable) ListView_SetImageList(hUchwyt, Icos.GetHandle(), LVSIL_SMALL); else ListView_SetImageList(hUchwyt, NULL, LVSIL_SMALL);
      if (bLargeEnable) ListView_SetImageList(hUchwyt, Imgs.GetHandle(), LVSIL_NORMAL); else ListView_SetImageList(hUchwyt, NULL, LVSIL_NORMAL);
}

unsigned KuszkAPI::Forms::TableBox::Capacity(void) const
{
      return ListView_GetItemCount(hUchwyt);
}

unsigned KuszkAPI::Forms::TableBox::GetColumnCount(void) const
{
      return uColumnCount;
}

unsigned KuszkAPI::Forms::TableBox::GetIndex(void) const
{
      return ListView_GetSelectionMark(hUchwyt) + 1;
}

void KuszkAPI::Forms::TableBox::Sort(unsigned uNumer, bool bGrow)
{
      unsigned uCount = Capacity();
      if (uNumer > uColumnCount) return;
      if (!bGroups){
              Containers::Strings* psTmp = new Containers::Strings[uColumnCount + 1];
              ItemData tBufor = GetItemStruct(1);
              for (int i = 1; i <= uCount; i++){
                       psTmp[0].Add(tBufor.Name);
                       for (int j = 1; j < uColumnCount; j++) psTmp[j].Add(tBufor.Data[j]);
                       psTmp[uColumnCount].Add(Containers::String(tBufor.Icon));
                       tBufor = GetItemStruct(i + 1);
              }
              psTmp[uNumer - 1].Sort(psTmp, uColumnCount + 1, bGrow);
              for (int i = 1; i <= uCount; i++) SetItemIcon(psTmp[uColumnCount][i].Int(), i);
              for (int i = 0; i < uColumnCount; i++) SetColumn(psTmp[i], i + 1);
              delete [] psTmp;
      } else {
              unsigned uGroup = GetItemStruct(1).Group;
              Containers::Strings* psTmp = new Containers::Strings[uColumnCount + 1];
              Containers::Strings* psBufor = new Containers::Strings[uColumnCount + 1];
              ItemData tBufor = GetItemStruct(1);
              for (int i = 1; i <= uCount; i++){
                       psBufor[0].Add(tBufor.Name);
                       for (int j = 1; j < uColumnCount; j++) psBufor[j].Add(tBufor.Data[j]);
                       psBufor[uColumnCount].Add(Containers::String(tBufor.Icon));
                       uGroup = tBufor.Group;
                       tBufor = GetItemStruct(i + 1);
                       if (uGroup != tBufor.Group || i == uCount){
                               psBufor[uNumer - 1].Sort(psBufor, uColumnCount + 1, bGrow);
                               for (int j = 0; j <= uColumnCount; j++){
                                       psTmp[j] += psBufor[j];
                                       psBufor[j].Clean();
                               }
                       }
              }
              for (int i = 1; i <= uCount; i++) SetItemIcon(psTmp[uColumnCount][i].Int(), i);
              for (int i = 0; i < uColumnCount; i++) SetColumn(psTmp[i], i + 1);
              delete [] psBufor;
              delete [] psTmp;
      }
}


void KuszkAPI::Forms::TableBox::CleanGroups(void)
{
      ListView_RemoveAllGroups(hUchwyt);
}

void KuszkAPI::Forms::TableBox::CleanItems(void)
{
      ListView_DeleteAllItems(hUchwyt);
}

void KuszkAPI::Forms::TableBox::CleanHeader(void)
{
      ListView_DeleteAllItems(hUchwyt);
      for (int i = 0; i < uColumnCount; i++) ListView_DeleteColumn(hUchwyt, 0);
      uColumnCount = 0;
}

