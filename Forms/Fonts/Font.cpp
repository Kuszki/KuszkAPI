using namespace KuszkAPI;

template<typename tnKey>
HFONT KuszkAPI::Forms::Font<tnKey>::hDef = (HFONT) GetStockObject(DEFAULT_GUI_FONT);

template<typename tnKey>
KuszkAPI::Forms::Font<tnKey>::Font(const HWND& hOwn) : hOwner(hOwn) {}

template<typename tnKey>
KuszkAPI::Forms::Font<tnKey>::~Font(void)
{
      Clean();
}

template<typename tnKey>
HFONT KuszkAPI::Forms::Font<tnKey>::Add(const tnKey& tKey, const Containers::String& sFont, unsigned short uSize, COLORREF cColor, unsigned uStyle, unsigned short uBold)
{
      if (!mFont.Allow(tKey)) return NULL;
      LOGFONT lTmp;
      memset(&lTmp, 0, sizeof(LOGFONT));
      lTmp.lfWidth = uSize;
      lTmp.lfWeight = uBold;
      lTmp.lfItalic = uStyle & STYLE_ITALIC;
      lTmp.lfUnderline = uStyle & STYLE_UNDERLINE;
      lTmp.lfStrikeOut = uStyle & STYLE_STRIKEOUT;
      lTmp.lfCharSet = DEFAULT_CHARSET;
      lTmp.lfOutPrecision = OUT_DEFAULT_PRECIS;
      lTmp.lfClipPrecision = CLIP_DEFAULT_PRECIS;
      lTmp.lfQuality = DEFAULT_QUALITY;
      lTmp.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
      memcpy(sFont.Str(), lTmp.lfFaceName, sFont.Capacity() > sizeof(lTmp.lfFaceName) ? sizeof(lTmp.lfFaceName) : sFont.Capacity());
      HFONT hTmp = CreateFontIndirect(&lTmp);
      if (hTmp){
              ItemData tTmp = {hTmp, lTmp, cColor};
              mFont.Add(tTmp, tKey);
              return hTmp;
      } else return NULL;
}

template<typename tnKey>
HFONT KuszkAPI::Forms::Font<tnKey>::Add(const tnKey& tKey, HWND hOwn)
{
      if (!mFont.Allow(tKey)) return NULL;
      HWND hTmp = hOwn ? hOwn : hOwner;
      CommonDialog dDialog(hTmp);
      if (dDialog.GetFont()){
              LOGFONT lTmp = dDialog.GetLastFont().Data;
              HFONT hTmp = CreateFontIndirect(&lTmp);
              if (hTmp){
                       ItemData tTmp = {hTmp, lTmp, dDialog.GetLastFont().Color};
                       mFont.Add(tTmp, tKey);
                       return hTmp;
              }
      }
      return NULL;
}

template<typename tnKey>
void KuszkAPI::Forms::Font<tnKey>::Delete(const tnKey& tKey)
{
      if (mFont.Contain(tKey)){
              DeleteObject(mFont[tKey].hFont);
              mFont.Delete(tKey);
      }
}

template<typename tnKey>
HFONT KuszkAPI::Forms::Font<tnKey>::Set(const tnKey& tKey, HWND hOwn)
{
      if (!mFont.Contain(tKey)) return NULL;
      ItemData tTmp = mFont[tKey];
      HWND hTmp = hOwn ? hOwn : hOwner;
      CommonDialog dDialog(hTmp);
      if (dDialog.GetFont(tTmp.lFont, tTmp.cColor)){
              LOGFONT lTmp = dDialog.GetLastFont().Data;
              HFONT hTmp = CreateFontIndirect(&lTmp);
              if (hTmp){
                       DeleteObject(tTmp.hFont);
                       ItemData tBufor = {hTmp, lTmp, dDialog.GetLastFont().Color};
                       mFont[tKey] = tBufor;
                       return hTmp;
              }
      }
      return NULL;
}

template<typename tnKey>
void KuszkAPI::Forms::Font<tnKey>::SetColor(const tnKey& tKey, HWND hOwn)
{
      if (mFont.Contain(tKey)){
              HWND hTmp = hOwn ? hOwn : hOwner;
              CommonDialog dDialog(hTmp);
              if (dDialog.GetColor(mFont[tKey].cColor)) mFont[tKey].cColor = dDialog.GetLastColor();
      }
}

template<typename tnKey>
COLORREF KuszkAPI::Forms::Font<tnKey>::GetColor(const tnKey& tKey) const
{
      if (!mFont.Contain(tKey)) return 0; else return mFont.GetData(tKey).cColor;
}

template<typename tnKey>
LOGFONT KuszkAPI::Forms::Font<tnKey>::GetData(const tnKey& tKey) const
{
      LOGFONT lTmp;
      memset(&lTmp, 0, sizeof(LOGFONT));
      if (mFont.Contain(tKey)) lTmp = mFont.GetData(tKey).lFont;
      return lTmp;
}

template<typename tnKey>
HFONT KuszkAPI::Forms::Font<tnKey>::GetHandle(const tnKey& tKey) const
{
      if (!mFont.Contain(tKey)) return hDef; else return mFont.GetData(tKey).hFont;
}

template<typename tnKey>
void KuszkAPI::Forms::Font<tnKey>::Clean(void)
{
      for (int i = 1; i <= mFont.Capacity(); i++) DeleteObject(mFont[i].hFont);
      mFont.Clean();
}

template<typename tnKey>
HFONT KuszkAPI::Forms::Font<tnKey>::operator[] (const tnKey& tKey) const
{
      if (!mFont.Contain(tKey)) return hDef; else return mFont.GetData(tKey).hFont;
}
