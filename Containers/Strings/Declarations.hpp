using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Containers)

// ---- CLASES DECLARATIONS -----
class Strings;
// ------------------------------

// ---- STRINGS DECLARATIONS ----
class Strings
{

     protected:

          List<String> lData;

          unsigned uIlosc;

     public:

          Strings(const Strings& sStrings);
          Strings(const String& sString,
               TCHAR cConvert = TEXT('\n'),
               bool bIgnore = false);
          Strings(void);
          ~Strings(void);

          unsigned Add(const String& sString,
                       TCHAR cConvert = '\0',
                       bool bIgnore = true,
                       int iPos = LAST,
                       bool bMode = ADD_AFTER);
          bool Delete(int iNumer);
          unsigned Delete(const String& sString,
                          bool bAll = false);
          const String& GetData(int iNumer) const;
          unsigned Change(const String& sOld,
                         const String& sNew,
                         bool bAll = false);
          bool Change(unsigned uOne,
                      unsigned uTwo);
          String All(const String& sBreak = String(TEXT("\n"))) const;
          unsigned Capacity(void) const;
          bool Contain(const String& sString) const;
          bool Empty(void) const;
          bool Sort(bool bGrow = true);
          bool Sort(Strings* ppsStrings[],
                    unsigned uCount,
                    bool bGrow = true);
          bool Sort(Strings psStrings[],
                    unsigned uCount,
                    bool bGrow = true);
          void Reverse(void);
          bool SaveToFile(const String& sPlik,
                          bool bMode = MODE_ASCII) const;
          bool LoadFromFile(const String& sPlik,
                            bool bMode = MODE_ASCII);
          bool AddToFile(const String& sPlik,
                         bool bMode = MODE_ASCII) const;
          void DeleteFile(const String& sPlik) const;
          void SetMode(unsigned uNewMode);
          unsigned GetMode(void) const;
          bool ParseQuotes(void);
          void Clean(void);

          String& operator[] (int iNumer);
          String& operator[] (const String& sString);
          Strings& operator<< (const String& sString);
          Strings& operator>> (String& sString);
          bool operator== (const Strings& sStrings) const;
          bool operator!= (const Strings& sStrings) const;
          Strings operator+ (const Strings& sStrings) const;
          Strings& operator+= (const Strings& sStrings);
          Strings& operator= (const Strings& sStrings);

          operator String (void) const;
          operator bool (void) const;

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
