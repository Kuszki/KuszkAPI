using namespace KuszkAPI;

KuszkAPI::Forms::Images::Images(unsigned uXSize, unsigned uYSize)
{
      hUchwyt = NULL;
      Create(uXSize, uYSize);
}

KuszkAPI::Forms::Images::Images(const Containers::Strings& sImages)
{
      hUchwyt = NULL;
      Create(sImages);
}

KuszkAPI::Forms::Images::Images(void)
{
      hUchwyt = NULL;
}

KuszkAPI::Forms::Images::~Images(void)
{
      Destroy();
}

HIMAGELIST KuszkAPI::Forms::Images::Create(const Containers::Strings& sImages)
{
      Destroy();
      Bitmap bImages(sImages);
      Bitmap::Size tTmp = bImages.GetSize(1);
      hUchwyt = ImageList_Create(tTmp.X, tTmp.Y, ILC_COLOR32, sImages.Capacity(), 0);
      for (int i = 1; i <= sImages.Capacity(); i++) Add(bImages[i]);
}

HIMAGELIST KuszkAPI::Forms::Images::Create(unsigned uXSize, unsigned uYSize)
{
      Destroy();
      hUchwyt = ImageList_Create(uXSize, uYSize, ILC_COLOR32, 0, 0);
      return hUchwyt;
}

void KuszkAPI::Forms::Images::Add(HBITMAP hImage)
{
      ImageList_Add(hUchwyt, hImage, NULL);
}

void KuszkAPI::Forms::Images::Delete(unsigned uNumer)
{
      ImageList_Remove(hUchwyt, uNumer - 1);
}

const HIMAGELIST& KuszkAPI::Forms::Images::GetHandle(void) const
{
      return hUchwyt;
}

void KuszkAPI::Forms::Images::Destroy(void)
{
      if (hUchwyt){
              Clean();
              ImageList_Destroy(hUchwyt);
              hUchwyt = NULL;
      }
}

void KuszkAPI::Forms::Images::Clean(void)
{
      ImageList_RemoveAll(hUchwyt);
}

KuszkAPI::Forms::Images::operator const HIMAGELIST& (void) const
{
      return hUchwyt;
}
