using namespace KuszkAPI;

template<typename tnData, typename tnHead>
KuszkAPI::Containers::File<tnData, tnHead>::File(const String& sNazwaPliku, unsigned uFileMode, unsigned uCreate, unsigned uAccess, unsigned uShare)
{
      uDataSize = sizeof(tnData);
      uHeadSize = sizeof(tnHead);
      hUchwyt = NULL;
      uMode = uFileMode;
      memset(&Head, 0, uHeadSize);
      Assign(sNazwaPliku, uCreate, uAccess, uShare);
}

template<typename tnData, typename tnHead>
KuszkAPI::Containers::File<tnData, tnHead>::File(void)
{
      uDataSize = sizeof(tnData);
      uHeadSize = sizeof(tnHead);
      hUchwyt = NULL;
      uMode = MODE_STREAM;
      memset(&Head, 0, uHeadSize);
}

template<typename tnData, typename tnHead>
KuszkAPI::Containers::File<tnData, tnHead>::~File(void)
{
      if (hUchwyt) CloseHandle(hUchwyt);
      memset(&Head, 0, uHeadSize);
      sNazwa.Clean();
      Data.Clean();
      hUchwyt = NULL;
}

template<typename tnData, typename tnHead>
bool KuszkAPI::Containers::File<tnData, tnHead>::Assign(const String& sNazwaPliku, unsigned uCreate, unsigned uAccess, unsigned uShare)
{
      sNazwa = sNazwaPliku;
      if (hUchwyt) CloseHandle(hUchwyt);
      hUchwyt = CreateFile(sNazwa.Str(), uAccess, uShare, NULL, uCreate, 0, NULL);
      if (hUchwyt == INVALID_HANDLE_VALUE) hUchwyt = NULL;
      return (bool) hUchwyt;
}

template<typename tnData, typename tnHead>
bool KuszkAPI::Containers::File<tnData, tnHead>::Load(void)
{
      if (!hUchwyt) return false;
      DWORD uReaded;
      unsigned uSize = GetFileSize(hUchwyt, NULL);
      if (uMode) uSize -= uHeadSize;
      tnData* ptBufor = new tnData[uSize / uDataSize];
      SetFilePointer(hUchwyt, 0, NULL, FILE_BEGIN);
      if (uMode) ReadFile(hUchwyt, &Head, uHeadSize, &uReaded, NULL);
      ReadFile(hUchwyt, ptBufor, uSize, &uReaded, NULL);
      Data.Clean();
      Data.Add(ptBufor, uReaded / uDataSize);
      delete [] ptBufor;
      return true;
}

template<typename tnData, typename tnHead>
bool KuszkAPI::Containers::File<tnData, tnHead>::Save(void) const
{
      if (!hUchwyt) return false;
      DWORD uWrited;
      SetFilePointer(hUchwyt, 0, NULL, FILE_BEGIN);
      if (uMode) WriteFile(hUchwyt, &Head, uHeadSize, &uWrited, NULL);
      WriteFile(hUchwyt, Data.GetBegin(), Data.Capacity() * uDataSize, &uWrited, NULL);
      return true;
}

template<typename tnData, typename tnHead>
bool KuszkAPI::Containers::File<tnData, tnHead>::Copy(const String& sNazwaPliku) const
{
      return false;
}

template<typename tnData, typename tnHead>
void KuszkAPI::Containers::File<tnData, tnHead>::SetMode(unsigned uNewMode)
{
      uMode = uNewMode;
}

template<typename tnData, typename tnHead>
unsigned KuszkAPI::Containers::File<tnData, tnHead>::GetMode(void) const
{
      return uMode;
}

template<typename tnData, typename tnHead>
void KuszkAPI::Containers::File<tnData, tnHead>::Clean(void)
{
      memset(&Head, 0, uHeadSize);
      Data.Clean();
}
