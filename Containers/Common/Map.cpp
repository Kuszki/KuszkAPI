using namespace KuszkAPI;

template<typename tnData, typename tnKey>
KuszkAPI::Containers::Map<tnData, tnKey>::Map(void)
{
      uIlosc = 0;
}

template<typename tnData, typename tnKey>
KuszkAPI::Containers::Map<tnData, tnKey>::~Map(void)
{
      bData.Clean();
      lKey.Clean();
}

template<typename tnData, typename tnKey>
unsigned KuszkAPI::Containers::Map<tnData, tnKey>::Add(const tnData& tData, const tnKey& tKey)
{
      if (lKey.Contain(tKey)) return 0;
      bData.Add(tData);
      lKey.Add(tKey);
      return ++uIlosc;
}

template<typename tnData, typename tnKey>
unsigned KuszkAPI::Containers::Map<tnData, tnKey>::Add(tnData* ptData, const tnKey& tKey)
{
      if (lKey.Contain(tKey)) return 0;
      bData.Add(ptData);
      lKey.Add(tKey);
      return ++uIlosc;
}

template<typename tnData, typename tnKey>
bool KuszkAPI::Containers::Map<tnData, tnKey>::Delete(const tnKey& tKey)
{
      unsigned uTmp = lKey.Find(tKey);
      if (uTmp){
              bData.Delete(uTmp);
              lKey.Delete(uTmp);
              uIlosc--;
              return true;
      } else return false;
}

template<typename tnData, typename tnKey>
const tnData& KuszkAPI::Containers::Map<tnData, tnKey>::GetData(const tnKey& tKey) const
{
      return bData.GetData(lKey.Find(tKey));
}

template<typename tnData, typename tnKey>
void KuszkAPI::Containers::Map<tnData, tnKey>::SetKey(const tnKey& tKey, int iNumer)
{
      return lKey[iNumer] = tKey;
}

template<typename tnData, typename tnKey>
const tnKey& KuszkAPI::Containers::Map<tnData, tnKey>::GetKey(int iNumer) const
{
      return lKey.GetData(iNumer);
}

template<typename tnData, typename tnKey>
void KuszkAPI::Containers::Map<tnData, tnKey>::SetDataByInt(const tnData& tData, int iNumer)
{
      bData[iNumer] = tData;
}

template<typename tnData, typename tnKey>
tnData& KuszkAPI::Containers::Map<tnData, tnKey>::GetDataByInt(int iNumer)
{
      return bData[iNumer];
}

template<typename tnData, typename tnKey>
unsigned KuszkAPI::Containers::Map<tnData, tnKey>::Capacity(void) const
{
      return uIlosc;
}

template<typename tnData, typename tnKey>
bool KuszkAPI::Containers::Map<tnData, tnKey>::Allow(const tnKey& tKey) const
{
      return !lKey.Contain(tKey);
}

template<typename tnData, typename tnKey>
bool KuszkAPI::Containers::Map<tnData, tnKey>::Contain(const tnKey& tKey) const
{
      return lKey.Contain(tKey);
}

template<typename tnData, typename tnKey>
void KuszkAPI::Containers::Map<tnData, tnKey>::Clean(void)
{
      bData.Clean();
      lKey.Clean();
      uIlosc = 0;
}

template<typename tnData, typename tnKey>
tnData& KuszkAPI::Containers::Map<tnData, tnKey>::operator[] (const tnKey& tKey)
{
      return bData[lKey.Find(tKey)];
}

template<typename tnData, typename tnKey>
const tnData& KuszkAPI::Containers::Map<tnData, tnKey>::operator[] (const tnKey& tKey) const
{
      return bData.GetData(lKey.Find(tKey));
}
