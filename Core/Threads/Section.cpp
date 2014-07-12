using namespace KuszkAPI;

template<typename tnKey>
KuszkAPI::Core::Sections<tnKey>::Sections(void) {}

template<typename tnKey>
KuszkAPI::Core::Sections<tnKey>::~Sections(void)
{
      Clean();
}

template<typename tnKey>
void KuszkAPI::Core::Sections<tnKey>::Add(const tnKey& tKey)
{
      if (mSection.Allow(tKey)){
              CRITICAL_SECTION sTmp;
              memset(&sTmp, 0, sizeof(CRITICAL_SECTION));
              InitializeCriticalSection(&sTmp);
              mSection.Add(sTmp, tKey);
      }
}

template<typename tnKey>
void KuszkAPI::Core::Sections<tnKey>::Delete(const tnKey& tKey)
{
      if (mSection.Contain(tKey)){
              DeleteCriticalSection(&mSection[tKey]);
              mSection.Delete(tKey);
      }
}

template<typename tnKey>
void KuszkAPI::Core::Sections<tnKey>::Enter(const tnKey& tKey)
{
      if (mSection.Contain(tKey)) EnterCriticalSection(&mSection[tKey]);
}

template<typename tnKey>
void KuszkAPI::Core::Sections<tnKey>::Leave(const tnKey& tKey)
{
      if (mSection.Contain(tKey)) LeaveCriticalSection(&mSection[tKey]);
}

template<typename tnKey>
void KuszkAPI::Core::Sections<tnKey>::Clean(void)
{
      for (int i = 1; i <= mSection.Capacity(); i++) DeleteCriticalSection(&mSection[mSection.GetKey(i)]);
      mSection.Clean();
}
