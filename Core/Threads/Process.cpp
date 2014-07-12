using namespace KuszkAPI;

template<typename tnKey>
KuszkAPI::Core::Process<tnKey>::Process(void)
{
      hProcess = GetCurrentProcess();
}

template<typename tnKey>
KuszkAPI::Core::Process<tnKey>::~Process(void)
{
      Clean();
}

template<typename tnKey>
const HANDLE& KuszkAPI::Core::Process<tnKey>::GetHandle(void) const
{
      return hProcess;
}

template<typename tnKey>
void KuszkAPI::Core::Process<tnKey>::Terminate(unsigned uCode)
{
      Event.Clean();
      Section.Clean();
      ExitProcess(uCode);
}

template<typename tnKey>
void KuszkAPI::Core::Process<tnKey>::Clean(void)
{
      Thread.Clean();
      Event.Clean();
      Section.Clean();
}

template<typename tnKey>
KuszkAPI::Core::Process<tnKey>::operator const HANDLE& (void) const
{
      return hProcess;
}
