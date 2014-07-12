using namespace KuszkAPI;

KuszkAPI::Forms::Cursor::Cursor(const Containers::Strings& sImages)
{
      for (int i = 1; i <= sImages.Capacity(); i++) Load(sImages.GetData(i));
}

KuszkAPI::Forms::Cursor::~Cursor(void) {}

HCURSOR KuszkAPI::Forms::Cursor::Load(const Containers::String& sImage)
{
      bool bRes = !sImage.Contain(TEXT('.'));
      HICON hTmp = (HICON) LoadImage(bRes ? GetModuleHandle(NULL) : NULL, sImage.Str(), IMAGE_CURSOR, 0, 0, bRes ? NULL : LR_LOADFROMFILE);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

void KuszkAPI::Forms::Cursor::Free(unsigned uNumer)
{
      if (bObject.Capacity() >= uNumer){
              DestroyCursor(bObject[uNumer]);
              bObject.Delete(uNumer);
      }
}

void KuszkAPI::Forms::Cursor::Clean(void)
{
      for (int i = 1; i <= bObject.Capacity(); i++) DestroyCursor(bObject[i]);
      bObject.Clean();
}
