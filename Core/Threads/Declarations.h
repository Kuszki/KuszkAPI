using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Core)

// ----- CLASS DECLARATIONS -----
class Instance;
// ------------------------------

// --- TEMPLATES DECLARATIONS ---
template<typename tnKey> class Threads;
template<typename tnKey> class Events;
template<typename tnKey> class Sections;
template<typename tnKey> class Process;
// ------------------------------

// ---- THREAD DECLARATIONS -----
template<typename tnKey = unsigned> class Threads
{
      private:
              struct ItemData
              {
                       LPTHREAD_START_ROUTINE fProc;
                       HANDLE hThread;
              };
              Containers::Map<ItemData, tnKey> mThread;
      public:
              Threads(void);
              ~Threads(void);
              void Add(const tnKey& tKey,
                       LPTHREAD_START_ROUTINE fProc);
              void Delete(const tnKey& tKey);
              HANDLE Start(const tnKey& tKey,
                           void* pvParam = NULL);
              void Stop(const tnKey& tKey,
                        unsigned uCode = 0);
              void Pause(const tnKey& tKey);
              void Resume(const tnKey& tKey);
              int Wait(const tnKey& tKey,
                       unsigned uTime = INFINITE) const;
              bool Work(const tnKey& tKey) const;
              void SetPriority(const tnKey& tKey,
                               int iPriority = 0);
              unsigned GetCode(const tnKey& tKey) const;
              const HANDLE& GetHandle(const tnKey& tKey) const;
              void Clean(void);
              const HANDLE& operator[] (const tnKey& tKey) const;
};
// ------------------------------

// ----- EVENT DECLARATIONS -----
template<typename tnKey = unsigned> class Events
{
      private:
              Containers::Map<HANDLE, tnKey> mEvents;
      public:
              Events(void);
              ~Events(void);
              HANDLE Add(const tnKey& tKey,
                         const Containers::String& sName = Containers::String());
              void Delete(const tnKey& tKey);
              void Start(const tnKey& tKey);
              void Stop(const tnKey& tKey);
              int Wait(const tnKey& tKey,
                       unsigned uTime = INFINITE) const;
              HANDLE GetHandle(const tnKey& tKey) const;
              void Clean(void);
              HANDLE operator[] (const tnKey& tKey) const;
};
// ------------------------------

// ---- SECTION DECLARATIONS ----
template<typename tnKey = unsigned> class Sections
{
      private:
              Containers::Map<CRITICAL_SECTION, tnKey> mSection;
      public:
              Sections(void);
              ~Sections(void);
              void Add(const tnKey& tKey);
              void Delete(const tnKey& tKey);
              void Enter(const tnKey& tKey);
              void Leave(const tnKey& tKey);
              void Clean(void);
};
// ------------------------------

// ---- PROCESS DECLARATIONS ----
template<typename tnKey = unsigned> class Process
{
      private:
              HANDLE hProcess;
      public:
              Process(void);
              ~Process(void);
              Threads<tnKey> Thread;
              Events<tnKey> Event;
              Sections<tnKey> Section;
              void Terminate(unsigned uCode = 0);
              const HANDLE& GetHandle(void) const;
              void Clean(void);
              operator const HANDLE& (void) const;
};
// ------------------------------

// --- INSTANCE DECLARATIONS ----
class Instance
{
      private:
              HINSTANCE hInstance;
      public:
              Instance(void);
              ~Instance(void);
              const HINSTANCE& GetHandle(void) const;
              operator const HINSTANCE& (void) const;
              static Containers::String GetExeFull(void);
              static Containers::String GetExeName(void);
              static Containers::String GetExePath(void);
              static void SetPath(const Containers::String& sPath);
              static Containers::String GetPath(void);
              static void SetEnv(const Containers::String& sName,
                                 const Containers::String& sValue);
              static Containers::String GetEnv(const Containers::String& sName);
              static void ResetPath(void);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
