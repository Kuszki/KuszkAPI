using namespace KuszkAPI;

KuszkAPI::Forms::Brush::Brush(void) {}

KuszkAPI::Forms::Brush::~Brush(void) {}

HBRUSH KuszkAPI::Forms::Brush::Create(COLORREF cColor)
{
      HBRUSH hTmp = CreateSolidBrush(cColor);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

HBRUSH KuszkAPI::Forms::Brush::Create(HBITMAP hImage)
{
      HBRUSH hTmp = CreatePatternBrush(hImage);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

HBRUSH KuszkAPI::Forms::Brush::Create(COLORREF cColor, unsigned uStyle)
{
      HBRUSH hTmp = CreateHatchBrush(uStyle, cColor);
      if (hTmp) bObject.Add(hTmp);
      return hTmp;
}

void KuszkAPI::Forms::Brush::Delete(unsigned uNumer)
{
      if (bObject.Capacity() >= uNumer){
              DeleteObject(bObject[uNumer]);
              bObject.Delete(uNumer);
      }
}
