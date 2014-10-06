using namespace KuszkAPI;

KuszkAPI::Forms::CommonDialog::CommonDialog(const HWND& hOwn)
: hOwner(hOwn)
{
      memset(ptColors, 0, sizeof(ptColors));
      memset(&tLastFont, 0, sizeof(LOGFONT));
      memset(&tLastColor, 0, sizeof(COLORREF));
}

KuszkAPI::Forms::CommonDialog::~CommonDialog(void)
{
      memset(ptColors, 0, sizeof(ptColors));
      memset(&tLastFont, 0, sizeof(LOGFONT));
      memset(&tLastColor, 0, sizeof(COLORREF));
}

bool KuszkAPI::Forms::CommonDialog::GetFileOpen(const TCHAR pcDefExt[], const TCHAR pcMask[], unsigned uFlags) const
{
      OPENFILENAME oPlik;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      memset(pcBufor, 0, sizeof(TCHAR) * MAX_PATH);
      memset(&oPlik, 0, sizeof(OPENFILENAME));
      oPlik.lStructSize = sizeof(OPENFILENAME);
      oPlik.hwndOwner = hOwner;
      oPlik.lpstrFilter = pcMask;
      oPlik.nMaxFile = MAX_PATH;
      oPlik.lpstrFile = pcBufor;
      oPlik.lpstrDefExt = pcDefExt;
      oPlik.Flags = uFlags;
      bool bTmp = GetOpenFileName(&oPlik);
      if (bTmp){
              tLastFile.Full = Containers::String(pcBufor);
              tLastFile.Name = Containers::String(pcBufor + oPlik.nFileOffset);
              pcBufor[oPlik.nFileOffset] = 0;
              tLastFile.Path = Containers::String(pcBufor);
      }
      delete [] pcBufor;
      return bTmp;
}

bool KuszkAPI::Forms::CommonDialog::GetFileSave(const TCHAR pcDefExt[], const TCHAR pcMask[], unsigned uFlags) const
{
      OPENFILENAME oPlik;
      TCHAR* pcBufor = new TCHAR[MAX_PATH];
      memset(pcBufor, 0, sizeof(TCHAR) * MAX_PATH);
      memset(&oPlik, 0, sizeof(OPENFILENAME));
      oPlik.lStructSize = sizeof(OPENFILENAME);
      oPlik.hwndOwner = hOwner;
      oPlik.lpstrFilter = pcMask;
      oPlik.nMaxFile = MAX_PATH;
      oPlik.lpstrFile = pcBufor;
      oPlik.lpstrDefExt = pcDefExt;
      oPlik.Flags = uFlags;
      bool bTmp = GetSaveFileName(&oPlik);
      if (bTmp){
              tLastFile.Full = Containers::String(pcBufor);
              tLastFile.Name = Containers::String(pcBufor + oPlik.nFileOffset);
              pcBufor[oPlik.nFileOffset] = 0;
              tLastFile.Path = Containers::String(pcBufor);
      }
      delete [] pcBufor;
      return bTmp;
}

bool KuszkAPI::Forms::CommonDialog::GetFont(unsigned uMin, unsigned uMax) const
{
      CHOOSEFONT cFont;
      LOGFONT tTmp = tLastFont.Data;
      memset(&cFont, 0, sizeof(CHOOSEFONT));
      cFont.lStructSize = sizeof(CHOOSEFONT);
      cFont.hwndOwner = hOwner;
      cFont.Flags = CF_EFFECTS | CF_FORCEFONTEXIST | CF_SCREENFONTS;
      if (uMin && uMax){
              cFont.Flags |= CF_LIMITSIZE;
              cFont.nSizeMin = uMin;
              cFont.nSizeMax = uMax;
      }
      cFont.lpLogFont = &tTmp;
      bool bTmp = ChooseFont(&cFont);
      if (bTmp){
              tLastFont.Data = tTmp;
              tLastFont.Color = cFont.rgbColors;
      }
      return bTmp;
}

bool KuszkAPI::Forms::CommonDialog::GetFont(LOGFONT tPrev, COLORREF tColor, unsigned uMin, unsigned uMax) const
{
      CHOOSEFONT cFont;
      LOGFONT tTmp = tPrev;
      memset(&cFont, 0, sizeof(CHOOSEFONT));
      cFont.lStructSize = sizeof(CHOOSEFONT);
      cFont.hwndOwner = hOwner;
      cFont.rgbColors = tColor;
      cFont.Flags = CF_EFFECTS | CF_FORCEFONTEXIST | CF_SCREENFONTS;
      if (uMin && uMax){
              cFont.Flags |= CF_LIMITSIZE;
              cFont.nSizeMin = uMin;
              cFont.nSizeMax = uMax;
      }
      cFont.lpLogFont = &tTmp;
      bool bTmp = !ChooseFont(&cFont);
      if (bTmp){
              tLastFont.Data = tTmp;
              tLastFont.Color = cFont.rgbColors;
      }
      return bTmp;
}

bool KuszkAPI::Forms::CommonDialog::GetColor(COLORREF tPrev) const
{
      CHOOSECOLOR cColor;
      memset(&cColor, 0, sizeof(CHOOSECOLOR));
      cColor.lStructSize = sizeof(CHOOSECOLOR);
      cColor.hwndOwner = hOwner;
      cColor.lpCustColors = ptColors;
      cColor.rgbResult = tPrev ? tPrev : tLastColor;
      cColor.Flags = CC_ANYCOLOR | CC_FULLOPEN | CC_RGBINIT;
      bool bTmp = ChooseColor(&cColor);
      if (bTmp) tLastColor = cColor.rgbResult;
      return bTmp;
}

const KuszkAPI::Forms::CommonDialog::FilePath& KuszkAPI::Forms::CommonDialog::GetLastFile(void) const
{
      return tLastFile;
}

const KuszkAPI::Forms::CommonDialog::FontInfo& KuszkAPI::Forms::CommonDialog::GetLastFont(void) const
{
      return tLastFont;
}

const COLORREF& KuszkAPI::Forms::CommonDialog::GetLastColor(void) const
{
      return tLastColor;
}
