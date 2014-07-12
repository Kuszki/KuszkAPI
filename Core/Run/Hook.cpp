using namespace KuszkAPI;

template<typename tnKey>
KuszkAPI::Core::Hook<tnKey>::Hook(void) {}

template<typename tnKey>
KuszkAPI::Core::Hook<tnKey>::~Hook(void)
{
      Clean();
}

template<typename tnKey>
HHOOK KuszkAPI::Core::Hook<tnKey>::Add(const tnKey& tKey, unsigned uTyp, HOOKPROC fProc, HINSTANCE hInst, bool bGlobal)
{
      if (!mHook.Allow(tKey)) return NULL;
      unsigned uThread = bGlobal && hInst ? 0 : GetCurrentThreadId();
      HHOOK hTmp = SetWindowsHookEx(uTyp, fProc, hInst, uThread);
      if (hTmp) mHook.Add(hTmp, tKey);
      return hTmp;
}

template<typename tnKey>
void KuszkAPI::Core::Hook<tnKey>::Delete(const tnKey& tKey)
{
      UnhookWindowsHookEx(mHook.GetData(tKey));
      mHook.Delete(tKey);
}

template<typename tnKey>
HHOOK KuszkAPI::Core::Hook<tnKey>::GetHandle(const tnKey& tKey) const
{
      return mHook.GetData(tKey);
}

template<typename tnKey>
void KuszkAPI::Core::Hook<tnKey>::Clean(void)
{
      for (int i = 1; i <= mHook.Capacity(); i++) UnhookWindowsHookEx(mHook.GetDataByInt(i));
      mHook.Clean();
}

template<typename tnKey>
HHOOK KuszkAPI::Core::Hook<tnKey>::operator[] (const tnKey& tKey) const
{
      return mHook.GetData(tKey);
}
