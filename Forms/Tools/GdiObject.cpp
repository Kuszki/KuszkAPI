using namespace KuszkAPI;

template<typename tnData>
KuszkAPI::Forms::GdiObject<tnData>::GdiObject(void) {}

template<typename tnData>
KuszkAPI::Forms::GdiObject<tnData>::~GdiObject(void)
{
      Clean();
}

template<typename tnData>
tnData KuszkAPI::Forms::GdiObject<tnData>::GetHandle(unsigned uNumer) const
{
      if (bObject.Capacity() < uNumer) return NULL; else return bObject.GetData(uNumer);
}

template<typename tnData>
void KuszkAPI::Forms::GdiObject<tnData>::Clean(void)
{
      for (int i = 1; i <= bObject.Capacity(); i++) DeleteObject(bObject[i]);
      bObject.Clean();
}

template<typename tnData>
tnData KuszkAPI::Forms::GdiObject<tnData>::operator[] (unsigned uNumer) const
{
      if (bObject.Capacity() < uNumer) return NULL; else return bObject.GetData(uNumer);
}
