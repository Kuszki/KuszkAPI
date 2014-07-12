using namespace KuszkAPI;

KuszkAPI::Forms::Bitmap::Bitmap(const Containers::Strings& sImages)
{
      for (int i = 1; i <= sImages.Capacity(); i++) Load(sImages.GetData(i));
}

KuszkAPI::Forms::Bitmap::~Bitmap(void) {}

HBITMAP KuszkAPI::Forms::Bitmap::Load(const Containers::String& sImage)
{
      bool bRes = !sImage.Contain(TEXT('.'));
      HBITMAP hTmp = (HBITMAP) LoadImage(bRes ? GetModuleHandle(NULL) : NULL, sImage.Str(), IMAGE_BITMAP, 0, 0, bRes ? LR_LOADTRANSPARENT : LR_LOADFROMFILE | LR_LOADTRANSPARENT);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

HBITMAP KuszkAPI::Forms::Bitmap::Load(HBITMAP hBitmap)
{
      HBITMAP hTmp = (HBITMAP) CopyImage(hBitmap, IMAGE_BITMAP, 0, 0, 0);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

void KuszkAPI::Forms::Bitmap::Free(unsigned uNumer)
{
      if (bObject.Capacity() >= uNumer){
              DeleteObject(bObject[uNumer]);
              bObject.Delete(uNumer);
      }
}

KuszkAPI::Forms::Bitmap::Size KuszkAPI::Forms::Bitmap::GetSize(unsigned uNumer) const
{
      Size tTmp;
      if (uNumer > bObject.Capacity()) return tTmp;
      return GetBitmapSize(bObject.GetData(uNumer));
}

KuszkAPI::Forms::Bitmap::Size KuszkAPI::Forms::Bitmap::GetBitmapSize(HBITMAP hImage)
{
      Size tSize;
      BITMAP bBmp;
      LPBITMAPINFO pbInfo;
      GetObject(hImage, sizeof(BITMAP), &bBmp);
      pbInfo = (LPBITMAPINFO) &bBmp;
      tSize.X = pbInfo->bmiHeader.biWidth;
      tSize.Y = pbInfo->bmiHeader.biHeight;
      return tSize;
}
