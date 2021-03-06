using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Core)

// ---- CLASES DECLARATIONS -----
class Ini;
class Reg;
// ------------------------------

// ------ INI DECLARATIONS ------
class Ini
{

     protected:

          Containers::String sFile;

     public:

          Ini(const Containers::String& sFileName = Containers::String());
          ~Ini(void);

          void SetFile(const Containers::String& sFileName);
          Containers::String GetFile(void) const;
          bool SetStr(const Containers::String& sSection,
                      const Containers::String& sName,
                      const Containers::String& sValue);
          Containers::String GetStr(const Containers::String& sSection,
                                    const Containers::String& sName) const;
          bool SetInt(const Containers::String& sSection,
                      const Containers::String& sName,
                      int iValue);
          int GetInt(const Containers::String& sSection,
                     const Containers::String& sName) const;
          Containers::Strings GetSections() const;
          Containers::Strings GetKeys(const Containers::String& sSection) const;
          void SetStrValues(const Containers::Map<Containers::String, Containers::String>& mValues,
                            const Containers::String& sSection);
          Containers::Map<Containers::String, Containers::String> GetStrValues(const Containers::String& sSection) const;
          void SetIntValues(const Containers::Map<int, Containers::String>& mValues,
                            const Containers::String& sSection);
          Containers::Map<int, Containers::String> GetIntValues(const Containers::String& sSection) const;
          void Clean(void);

};
// ------------------------------

// ------ REG DECLARATIONS ------
class Reg
{

     protected:

          Containers::Vector<HKEY> vBack;

          HKEY hKey;

     public:

          Reg(HKEY hStart = NULL);
          ~Reg(void);

          bool Open(const Containers::String& sName);
          void Open(HKEY hStart);
          bool Back(void);
          bool AddKey(const Containers::String& sName,
                      bool bOpen = true);
          bool DeleteKey(const Containers::String& sName);
          bool SetStr(const Containers::String& sName,
                      const Containers::String& sValue);
          Containers::String GetStr(const Containers::String& sName);
          bool SetInt(const Containers::String& sName,
                      unsigned uValue);
          int GetInt(const Containers::String& sName);
          bool DeleteItem(const Containers::String& sName);
          void Clean(void);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
