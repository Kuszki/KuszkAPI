using namespace KuszkAPI;

KuszkAPI::Forms::EditBox::EditBox(const HWND& hOwn, unsigned uCrtId) : TextControl(hOwn, uCrtId){}

HWND KuszkAPI::Forms::EditBox::Create(int iXPos, int iYPos, int iSzerokosc, int iWysokosc, const Containers::String& sTekst, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      hUchwyt = CreateWindowEx(uExStyl | WS_EX_CLIENTEDGE, sClass.Str(), NULL, uStyl | WS_VISIBLE | WS_CHILD, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);
      SetFont();
      SetText(sTekst);
      return hUchwyt;
}

void KuszkAPI::Forms::EditBox::AddLine(const Containers::String& sTekst, bool bScrool)
{
      Containers::Strings sTmp = GetLines();
      sTmp.Add(sTekst);
      SetLines(sTmp, bScrool);
}

void KuszkAPI::Forms::EditBox::AddLines(const Containers::Strings& sLines, bool bScrool)
{
      Containers::Strings sTmp = GetLines() + sLines;
      SetLines(sTmp, bScrool);
}

void KuszkAPI::Forms::EditBox::SetLine(const Containers::String& sTekst, unsigned uNumer)
{
      Containers::Strings sTmp = GetLines();
      sTmp[uNumer] = sTekst;
      SetText(sTmp.All());
}

void KuszkAPI::Forms::EditBox::SetLines(const Containers::Strings& sLines, bool bScrool)
{
      SetText(sLines.All());
      if (bScrool) Scrool();
}

Containers::String KuszkAPI::Forms::EditBox::GetLine(unsigned uNumer) const
{
      Containers::String sTmp;
      if (uNumer > Capacity()) return sTmp;
      unsigned uTmp = Edit_LineLength(hUchwyt, Edit_LineIndex(hUchwyt, --uNumer));
      TCHAR* pcBufor = new TCHAR[uTmp + 1];
      Edit_GetLine(hUchwyt, uNumer, pcBufor, uTmp);
      pcBufor[uTmp] = 0;
      sTmp = pcBufor;
      delete [] pcBufor;
      return sTmp;
}

Containers::Strings KuszkAPI::Forms::EditBox::GetLines(void) const
{
      Containers::Strings sTmp;
      unsigned uCount = Capacity();
      for (int i = 0; i < uCount; i++){
              unsigned uTmp = Edit_LineLength(hUchwyt, Edit_LineIndex(hUchwyt, i));
              TCHAR* pcBufor = new TCHAR[uTmp + 1];
              Edit_GetLine(hUchwyt, i, pcBufor, uTmp);
              pcBufor[uTmp] = 0;
              Containers::String sBufor(pcBufor);
              if (i + 1 != uCount || sBufor) sTmp.Add(sBufor);
              delete [] pcBufor;
      }
      return sTmp;
}

void KuszkAPI::Forms::EditBox::SetPass(TCHAR cZnak)
{
      Edit_SetPasswordChar(hUchwyt, cZnak);
}

void KuszkAPI::Forms::EditBox::Scrool(bool bPos)
{
      Edit_Scroll(hUchwyt, bPos ? Edit_GetLineCount(hUchwyt) : -Edit_GetLineCount(hUchwyt), 0);
}

unsigned KuszkAPI::Forms::EditBox::Capacity(void) const
{
      return Edit_GetLineCount(hUchwyt);
}

void KuszkAPI::Forms::EditBox::CleanLines(void)
{
      SetText(Containers::String());
}

KuszkAPI::Forms::EditBox::operator Containers::Strings (void) const
{
      return GetLines();
}
