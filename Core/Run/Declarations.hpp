using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Core)

// --- TEMPLATES DECLARATIONS ---
template<typename tnResult, typename tnParam> class Script;
template<typename tnKey> class Dll;
template<typename tnKey> class Hook;
// ------------------------------

// ---- SCRIPT DECLARATIONS -----
template<typename tnResult = LRESULT, typename tnParam = void*>
class Script
{
     protected:

		typedef tnResult (*ExecuteProc)(unsigned, Containers::Strings&, tnParam);
		typedef unsigned (*PrepareProc)(const Containers::String&, Containers::Strings&, tnParam);

		ExecuteProc fExe;
		PrepareProc fPre;

		mutable tnResult tLast;

     public:

		Script(ExecuteProc fExeFun,
		       PrepareProc fPreFun);
		~Script(void);

		void SetAction(ExecuteProc fExeFun = NULL,
				     PrepareProc fPreFun = NULL);
		tnResult GetValue(void) const;

		tnResult operator() (Containers::Strings sCommand,
						 tnParam tParam = tnParam()) const;
		tnResult operator() (Console& cConsole,
						 tnParam tParam = tnParam()) const;

};
// ------------------------------

// ------ DLL DECLARATIONS ------
template<typename tnKey = unsigned> class Dll
{
     protected:

		Containers::Map<HINSTANCE, tnKey> mDll;

     public:

		Dll(void);
		~Dll(void);

		HINSTANCE Load(const tnKey& tKey,
				     const Containers::String& sFile);
		void Free(const tnKey& tKey);
		HINSTANCE GetHandle(const tnKey& tKey) const;
		FARPROC GetFunction(const tnKey& tKey,
						const Containers::String& sProc) const;
		unsigned Capacity(void) const;
		void Clean(void);

		HINSTANCE operator[] (const tnKey& tKey) const;

};
// ------------------------------

// ----- HOOK DECLARATIONS ------
template<typename tnKey = unsigned> class Hook
{
     protected:

		Containers::Map<HHOOK, tnKey> mHook;

     public:

		Hook(void);
		~Hook(void);

		HHOOK Add(const tnKey& tKey,
				unsigned uTyp,
				HOOKPROC fProc,
				HINSTANCE hInst = NULL,
				bool bGlobal = false);
		void Delete(const tnKey& tKey);
		HHOOK GetHandle(const tnKey& tKey) const;
		void Clean(void);

		HHOOK operator[] (const tnKey& tKey) const;

};
// ------------------------------
KUSZKAPI_NAMESPACE_END
