using namespace KuszkAPI;

KuszkAPI::Forms::Region::Region(const Containers::Strings& sRegions)
{
      for (int i = 1; i <= sRegions.Capacity(); i++) Load(sRegions.GetData(i));
}

KuszkAPI::Forms::Region::~Region(void) {}

HRGN KuszkAPI::Forms::Region::Create(HBITMAP hBitmap, COLORREF cColor)
{
      WORD wBmpWidth, wBmpHeight;
      HRGN hTmp, hTmpRgn;

      BYTE jTranspR = GetRValue(cColor);
      BYTE jTranspG = GetGValue(cColor);
      BYTE jTranspB = GetBValue(cColor);

      BITMAP bmpBmp;
      LPBITMAPINFO pbmiInfo;
      BITMAPINFO bmiInfo;

      GetObject(hBitmap, sizeof(bmpBmp), &bmpBmp);
      pbmiInfo = (LPBITMAPINFO) &bmpBmp;

      wBmpWidth = (WORD) pbmiInfo->bmiHeader.biWidth;
      wBmpHeight = (WORD) pbmiInfo->bmiHeader.biHeight;

      BYTE* pPixels = new BYTE[wBmpWidth * wBmpHeight * 3];
      if (!pPixels) return NULL;

      HDC hDC = GetWindowDC(NULL);

      bmiInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
      bmiInfo.bmiHeader.biWidth = wBmpWidth;
      bmiInfo.bmiHeader.biHeight = -wBmpHeight;
      bmiInfo.bmiHeader.biPlanes = 1;
      bmiInfo.bmiHeader.biBitCount = 24;
      bmiInfo.bmiHeader.biCompression = BI_RGB;
      bmiInfo.bmiHeader.biSizeImage = wBmpWidth * wBmpHeight * 3;
      bmiInfo.bmiHeader.biXPelsPerMeter = 0;
      bmiInfo.bmiHeader.biYPelsPerMeter = 0;
      bmiInfo.bmiHeader.biClrUsed = 0;
      bmiInfo.bmiHeader.biClrImportant = 0;

      int iRes = GetDIBits(hDC, hBitmap, 0, wBmpHeight, pPixels, &bmiInfo, DIB_RGB_COLORS);

      ReleaseDC(NULL, hDC);

      if (!iRes){
              delete pPixels;
              return NULL;
      }

      if (!pPixels) return NULL;

      hTmp = CreateRectRgn(0, 0, wBmpWidth, wBmpHeight);

      if (!hTmp){
              delete pPixels;
              return NULL;
      }

      for (DWORD y = 0, p = 0; y < wBmpHeight; y++) for (DWORD x = 0; x < wBmpWidth; x++){
              BYTE jRed = pPixels[p + 2];
              BYTE jGreen = pPixels[p + 1];
              BYTE jBlue = pPixels[p + 0];
              if (jRed == jTranspR && jGreen == jTranspG && jBlue == jTranspB){
                       hTmpRgn = CreateRectRgn(x, y, x + 1, y + 1);
                       CombineRgn(hTmp, hTmp, hTmpRgn, RGN_XOR);
                       DeleteObject(hTmpRgn);
             }
             p+=3;
      }

      delete pPixels;

      if (hTmp) bObject.Add(hTmp);

      return hTmp;
}

HRGN KuszkAPI::Forms::Region::Load(const Containers::String& sRegion)
{
      Containers::File<char, unsigned> fRgn(sRegion, MODE_STRUCT, OPEN_EXISTING);
      if (!fRgn.Load()) return NULL;
      HRGN hTmp = ExtCreateRegion(NULL, fRgn.Head, (LPRGNDATA) fRgn.Data.GetBegin());
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

void KuszkAPI::Forms::Region::Free(unsigned uNumer)
{
      if (bObject.Capacity() >= uNumer){
              DeleteObject(bObject[uNumer]);
              bObject.Delete(uNumer);
      }
}

bool KuszkAPI::Forms::Region::Save(const Containers::String& sRegion, unsigned uNumer) const
{
      if (uNumer > bObject.Capacity()) return false;
      HRGN hTmp = bObject.GetData(uNumer);
      unsigned uCount = GetRegionData(hTmp, 0, 0);
      LPRGNDATA pdData = new RGNDATA[uCount];
      if (!pdData) return false;
      GetRegionData(hTmp, uCount, pdData);
      Containers::File<char, unsigned> fRgn(sRegion, MODE_STRUCT, CREATE_ALWAYS);
      fRgn.Data.Add((char*) pdData, uCount);
      fRgn.Head = uCount;
      delete pdData;
      return fRgn.Save();
}
