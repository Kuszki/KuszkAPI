using namespace KuszkAPI;

template<typename tnData>
KuszkAPI::Containers::Box<tnData>::Box(const Box<tnData>& bBox)
{
     uIlosc = bBox.uIlosc;

     for (int i = 1; i <= uIlosc; i++) vPointers.Add(new tnData(*bBox.vPointers.GetData(i)));
}

template<typename tnData>
KuszkAPI::Containers::Box<tnData>::Box(void)
{
     uIlosc = 0;
}

template<typename tnData>
KuszkAPI::Containers::Box<tnData>::~Box(void)
{
     for (int i = 1; i <= uIlosc; i++) delete vPointers[i];
}

template<typename tnData>
unsigned KuszkAPI::Containers::Box<tnData>::Add(const tnData& tData, int iPos, bool bMode)
{
     if (vPointers.Add(new tnData(tData))) return ++uIlosc;

     return false;
}

template<typename tnData>
unsigned KuszkAPI::Containers::Box<tnData>::Add(tnData* ptData, int iPos, bool bMode)
{
     if (vPointers.Add(ptData)) return ++uIlosc;

     return false;
}

template<typename tnData>
bool KuszkAPI::Containers::Box<tnData>::Delete(int iNumer)
{
     if (iNumer > uIlosc) return false;

     delete vPointers[iNumer];

     vPointers.Delete(iNumer);

     uIlosc--;

     return true;
}

template<typename tnData>
const tnData& KuszkAPI::Containers::Box<tnData>::GetData(int iNumer) const
{
     return *vPointers.GetData(iNumer);
}

template<typename tnData>
unsigned KuszkAPI::Containers::Box<tnData>::Capacity(void) const
{
     return uIlosc;
}

template<typename tnData>
bool KuszkAPI::Containers::Box<tnData>::Empty(void) const
{
     return !uIlosc;
}

template<typename tnData>
void KuszkAPI::Containers::Box<tnData>::Clean(void)
{
     for (int i = 1; i <= uIlosc; i++) delete vPointers[i];

     vPointers.Clean();

     uIlosc = 0;
}

template<typename tnData>
tnData& KuszkAPI::Containers::Box<tnData>::operator[] (int iNumer)
{
     return *vPointers[iNumer];
}

template<typename tnData>
const tnData& KuszkAPI::Containers::Box<tnData>::operator[] (int iNumer) const
{
     return *vPointers.GetData(iNumer);
}

template<typename tnData>
Containers::Box<tnData>& KuszkAPI::Containers::Box<tnData>::operator= (const KuszkAPI::Containers::Box<tnData>& bBox)
{
     if (this == &bBox) return *this;

     Clean();

     uIlosc = bBox.uIlosc;

     for (int i = 1; i <= uIlosc; i++) vPointers.Add(new tnData(*bBox.vPointers.GetData(i)));

     return *this;
}
