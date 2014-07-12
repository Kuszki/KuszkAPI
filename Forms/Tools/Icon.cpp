using namespace KuszkAPI;

KuszkAPI::Forms::Icon::Icon(const Containers::Strings& sImages)
{
      for (int i = 1; i <= sImages.Capacity(); i++) Load(sImages.GetData(i));
}

KuszkAPI::Forms::Icon::~Icon(void) {}

HICON KuszkAPI::Forms::Icon::Load(const Containers::String& sImage)
{
      bool bRes = !sImage.Contain(TEXT('.'));
      HICON hTmp = (HICON) LoadImage(bRes ? GetModuleHandle(NULL) : NULL, sImage.Str(), IMAGE_ICON, 0, 0, bRes ? NULL : LR_LOADFROMFILE);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

void KuszkAPI::Forms::Icon::Free(unsigned uNumer)
{
      if (bObject.Capacity() >= uNumer){
              DestroyIcon(bObject[uNumer]);
              bObject.Delete(uNumer);
      }
}

void KuszkAPI::Forms::Icon::Clean(void)
{
      for (int i = 1; i <= bObject.Capacity(); i++) DestroyIcon(bObject[i]);
      bObject.Clean();
}
