using namespace KuszkAPI;

template<typename tnKey>
KuszkAPI::Core::Dll<tnKey>::Dll(void) {}

template<typename tnKey>
KuszkAPI::Core::Dll<tnKey>::~Dll(void)
{
      Clean();
}

template<typename tnKey>
HINSTANCE KuszkAPI::Core::Dll<tnKey>::Load(const tnKey& tKey, const Containers::String& sFile)
{
      if (!mDll.Allow(tKey)) return NULL;
      HINSTANCE hTmp = LoadLibrary(sFile.Str());
      if (hTmp) mDll.Add(hTmp, tKey);
      return hTmp;
}

template<typename tnKey>
void KuszkAPI::Core::Dll<tnKey>::Free(const tnKey& tKey)
{
      FreeLibrary(mDll[tKey]);
      mDll.Delete(tKey);
}

template<typename tnKey>
HINSTANCE KuszkAPI::Core::Dll<tnKey>::GetHandle(const tnKey& tKey) const
{
      if (mDll.Contain(tKey)) return mDll.GetData(tKey); else return NULL;
}

template<typename tnKey>
FARPROC KuszkAPI::Core::Dll<tnKey>::GetFunction(const tnKey& tKey, const Containers::String& sProc) const
{
      if (mDll.Contain(tKey)) return GetProcAddress(mDll.GetData(tKey), sProc.Ascii()); else return NULL;
}

template<typename tnKey>
unsigned KuszkAPI::Core::Dll<tnKey>::Capacity(void) const
{
      return mDll.Capacity();
}

template<typename tnKey>
void KuszkAPI::Core::Dll<tnKey>::Clean(void)
{
      for (int i = 1; i <= mDll.Capacity(); i++) FreeLibrary(mDll.GetDataByInt(i));
      mDll.Clean();
}

template<typename tnKey>
HINSTANCE KuszkAPI::Core::Dll<tnKey>::operator[] (const tnKey& tKey) const
{
      if (mDll.Contain(tKey)) return mDll.GetData(tKey); else return NULL;
}
