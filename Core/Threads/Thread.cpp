using namespace KuszkAPI;

template<typename tnKey>
KuszkAPI::Core::Threads<tnKey>::Threads(void) {}

template<typename tnKey>
KuszkAPI::Core::Threads<tnKey>::~Threads(void)
{
      Clean();
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::Add(const tnKey& tKey, LPTHREAD_START_ROUTINE fProc)
{
      if (mThread.Allow(tKey)){
              ItemData tTmp = {fProc, NULL};
              mThread.Add(tTmp, tKey);
      }
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::Delete(const tnKey& tKey)
{
      if (mThread.Contain(tKey)){
              Stop(tKey, (unsigned) -1);
              mThread.Delete(tKey);
      }
}

template<typename tnKey>
HANDLE KuszkAPI::Core::Threads<tnKey>::Start(const tnKey& tKey, void* pvParam)
{
      if (!mThread.Contain(tKey)) return NULL;
      ItemData tTmp = mThread[tKey];
      if (!tTmp.fProc) return NULL;
      mThread[tKey].hThread = CreateThread(NULL, 0, tTmp.fProc, pvParam, 0, 0);
      return tTmp.hThread;
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::Stop(const tnKey& tKey, unsigned uCode)
{
      if (mThread.Contain(tKey)){
              HANDLE hTmp = mThread[tKey].hThread;
              if (hTmp) if (Work(tKey)) TerminateThread(hTmp, uCode);
      }
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::Pause(const tnKey& tKey)
{
      if (mThread.Contain(tKey)){
              HANDLE hTmp = mThread[tKey].hThread;
              if (hTmp) SuspendThread(hTmp);
      }
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::Resume(const tnKey& tKey)
{
      HANDLE hTmp = mThread[tKey].hThread;
      if (hTmp) ResumeThread(hTmp);
}

template<typename tnKey>
int KuszkAPI::Core::Threads<tnKey>::Wait(const tnKey& tKey, unsigned uTime) const
{
      if (mThread.Contain(tKey)) return WaitForSingleObject(mThread.GetData(tKey).hThread, uTime);
}

template<typename tnKey>
bool KuszkAPI::Core::Threads<tnKey>::Work(const tnKey& tKey) const
{
      if (!mThread.Contain(tKey)) return false;
      unsigned long uTmp;
      GetExitCodeThread(mThread.GetData(tKey).hThread, &uTmp);
      return uTmp == STILL_ACTIVE;
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::SetPriority(const tnKey& tKey, int iPriority)
{
      HANDLE hTmp = NULL;
      if (mThread.Contain(tKey)) hTmp = mThread[tKey].hThread;
      if (hTmp) SetThreadPriority(hTmp, iPriority);
}

template<typename tnKey>
unsigned KuszkAPI::Core::Threads<tnKey>::GetCode(const tnKey& tKey) const
{
      if (!mThread.Contain(tKey)) return (unsigned) -1;
      unsigned long uTmp;
      if (!GetExitCodeThread(mThread.GetData(tKey).hThread, &uTmp)) return (unsigned) -1; else if (uTmp == STILL_ACTIVE) return (unsigned) -1; else return uTmp;
}

template<typename tnKey>
const HANDLE& KuszkAPI::Core::Threads<tnKey>::GetHandle(const tnKey& tKey) const
{
      return mThread.GetData(tKey).hThread;
}

template<typename tnKey>
void KuszkAPI::Core::Threads<tnKey>::Clean(void)
{
      for (int i = 1; i <= mThread.Capacity(); i++) Stop(mThread.GetKey(i));
      mThread.Clean();
}

template<typename tnKey>
const HANDLE& KuszkAPI::Core::Threads<tnKey>::operator[] (const tnKey& tKey) const
{
      return mThread.GetData(tKey).hThread;
}
