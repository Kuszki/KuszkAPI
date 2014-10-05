using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Containers)

// ---- CLASES DECLARATIONS -----
class String;
// ------------------------------

// ---- STRING DECLARATIONS -----
class String
{

	protected:

		static unsigned uFormat;

		TCHAR* pcData;

		unsigned uIlosc;
		unsigned uDataSize;

		mutable TCHAR* pcBufor;
		mutable DCHAR* pcConvert;
		mutable TCHAR cAbstract;

	public:

		String(const String& sString);
		String(const TCHAR pcString[]);
		String(const DCHAR pcString[]);
		String(const void* pvVoid);
		String(float fFloat);
		String(unsigned uUnsigned);
		String(int iInt);
		String(TCHAR cChar);
		String(void);
		~String(void);

		unsigned Add(TCHAR cChar,
				   int iPos = 0,
				   bool bMode = ADD_AFTER);
		unsigned Add(const TCHAR pcString[],
				   int iPos = 0,
				   bool bMode = ADD_AFTER);
		unsigned Add(const DCHAR pcString[],
				   int iPos = 0,
				   bool bMode = ADD_AFTER);
		unsigned Delete(TCHAR cChar,
					 bool bAll = false);
		unsigned Delete(const String& sString,
					 bool bAll = false);
		unsigned Delete(int iNumer);
		const TCHAR& GetData(int iNumer) const;
		TCHAR GetFirst(void) const;
		TCHAR GetLast(void) const;
		unsigned Find(TCHAR cChar,
				    unsigned uStart = 0) const;
		unsigned Find(const String& sString,
				    unsigned uStart = 0) const;
		String Part(unsigned uStart,
				  unsigned uCount = 0) const;
		bool Contain(TCHAR cChar) const;
		unsigned Count(TCHAR cChar) const;
		bool Change(unsigned uOne,
				  unsigned uTwo);
		unsigned Change(TCHAR cOld,
					 TCHAR cNew,
					 bool bAll = false);
		unsigned Change(const String& sOld,
					 const String& sNew,
					 bool bAll = false);
		TCHAR* Str(void) const;
		DCHAR* Convert(void) const;
		char* Ascii(void) const;
		wchar_t* Unicode(void) const;
		int Int(void) const;
		unsigned Capacity(void) const;
		bool Empty(void) const;
		void Clean(void);

		TCHAR& operator[] (int iNumer);
		const TCHAR& operator[] (int iNumer) const;
		String& operator<< (const String& sString);
		String& operator<< (const TCHAR pcString[]);
		bool operator== (const String& sString) const;
		bool operator!= (const String& sString) const;
		bool operator> (const String& sString) const;
		bool operator< (const String& sString) const;
		String operator+ (const String& sString) const;
		String operator+ (const TCHAR pcString[]) const;
		String& operator+= (const String& sString);
		String& operator+= (const TCHAR pcString[]);
		String& operator= (const String& sString);

		operator int (void) const;
		operator bool (void) const;

		static void SetFormat(unsigned uFmt);
		static unsigned GetFormat(void);
		static unsigned GetSize(const TCHAR pcString[]);
		static bool Compare(const TCHAR pcOne[],
						const TCHAR pcTwo[]);
		static unsigned Copy(const TCHAR pcSource[],
						 TCHAR pcDestonation[],
						 unsigned uCount);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
