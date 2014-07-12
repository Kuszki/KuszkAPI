using namespace KuszkAPI;

template<typename tnKey>
KuszkAPI::Core::Events<tnKey>::Events(void) {}

template<typename tnKey>
KuszkAPI::Core::Events<tnKey>::~Events(void)
{
      Clean();
}

template<typename tnKey>
HANDLE KuszkAPI::Core::Events<tnKey>::Add(const tnKey& tKey, const Containers::String& sName)
{
      HANDLE hTmp = NULL;
      if (mEvents.Allow(tKey)){
              hTmp = CreateEvent(NULL, true, false, sName.Str());
              if (hTmp) mEvents.Add(hTmp, tKey);
      }
      return hTmp;
}

template<typename tnKey>
void KuszkAPI::Core::Events<tnKey>::Delete(const tnKey& tKey)
{
      if (mEvents.Contain(tKey)){
              CloseHandle(mEvents[tKey]);
              mEvents.Delete(tKey);
      }
}

template<typename tnKey>
void KuszkAPI::Core::Events<tnKey>::Start(const tnKey& tKey)
{
      if (mEvents.Contain(tKey)) SetEvent(mEvents[tKey]);
}

template<typename tnKey>
void KuszkAPI::Core::Events<tnKey>::Stop(const tnKey& tKey)
{
      if (mEvents.Contain(tKey)) ResetEvent(mEvents[tKey]);
}

template<typename tnKey>
int KuszkAPI::Core::Events<tnKey>::Wait(const tnKey& tKey, unsigned uTime) const
{
      if (mEvents.Contain(tKey)) return WaitForSingleObject(mEvents.GetData(tKey), uTime);
}

template<typename tnKey>
HANDLE KuszkAPI::Core::Events<tnKey>::GetHandle(const tnKey& tKey) const
{
      return mEvents.GetData(tKey);
}

template<typename tnKey>
void KuszkAPI::Core::Events<tnKey>::Clean(void)
{
      for (int i = 1; i <= mEvents.Capacity(); i++) CloseHandle(mEvents[i]);
      mEvents.Clean();
}

template<typename tnKey>
HANDLE KuszkAPI::Core::Events<tnKey>::operator[] (const tnKey& tKey) const
{
      return mEvents.GetData(tKey);
}
