using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Containers)

// --- TEMPLATES DECLARATIONS ---
template<typename tnData, typename tnHead> class File;
// ------------------------------

// ----- FILE DECLARATIONS ------
template<typename tnData, typename tnHead = int>
class File
{
      private:
              String sNazwa;
              HANDLE hUchwyt;
              unsigned uDataSize;
              unsigned uHeadSize;
              unsigned uMode;
      public:
              Vector<tnData> Data;
              tnHead Head;
              File(const String& sNazwaPliku,
                    unsigned uFileMode = MODE_STREAM,
                    unsigned uCreate = OPEN_ALWAYS,
                    unsigned uAccess = GENERIC_READ | GENERIC_WRITE,
                    unsigned uShare = FILE_SHARE_READ);
              File(void);
              ~File(void);
              bool Assign(const String& sNazwaPliku,
                          unsigned uCreate = OPEN_ALWAYS,
                          unsigned uAccess = GENERIC_READ | GENERIC_WRITE,
                          unsigned uShare = FILE_SHARE_READ);
              bool Load(void);
              bool Save(void) const;
              bool Copy(const String& sNazwaPliku) const;
              void SetMode(unsigned uNewMode);
              unsigned GetMode(void) const;
              void Clean(void);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
