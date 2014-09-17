using namespace KuszkAPI;

KuszkAPI::Containers::Strings::Strings(const Strings& sStrings)
{
     uIlosc = 0;

     lData = sStrings.lData;
}

KuszkAPI::Containers::Strings::Strings(const String& sString, TCHAR cConvert, bool bIgnore)
{
     uIlosc = 0;

     Add(sString, cConvert, bIgnore);
}

KuszkAPI::Containers::Strings::Strings(void)
{
     uIlosc = 0;
}

KuszkAPI::Containers::Strings::~Strings(void)
{
     Clean();
}

unsigned KuszkAPI::Containers::Strings::Add(const String& sString, TCHAR cConvert, bool bIgnore, int iPos, bool bMode)
{
     if (cConvert){

          if (bIgnore) for (int i = 1; i <= sString.Capacity(); i++) if (sString.GetData(i) != cConvert){

               unsigned uTmp = sString.Find(cConvert, i);

               if (uTmp){

                   lData.Add(sString.Part(i, uTmp - i), iPos, bMode);

                   i = uTmp;

                   uIlosc++;

               } else {

                   lData.Add(sString.Part(i), iPos, bMode);

                   return ++uIlosc;

               }

          }

          if (!bIgnore){

               unsigned uPos = 1;
               unsigned uTmp = sString.Find(cConvert);

               while (uTmp){

                   if (uTmp - uPos) lData.Add(sString.Part(uPos, uTmp - uPos), iPos, bMode); else lData.Add(String(), iPos, bMode);

                   uPos = uTmp;
                   uTmp = sString.Find(cConvert, uPos++);

                   uIlosc++;

               }

               lData.Add(sString.Part(uPos), iPos, bMode);

               return ++uIlosc;

          }

     } else lData.Add(sString, iPos, bMode);

     return ++uIlosc;
}

bool KuszkAPI::Containers::Strings::Delete(int iNumer)
{
     if (lData.Delete(iNumer)){

          uIlosc--;

          return true;

     } else return false;
}

unsigned KuszkAPI::Containers::Strings::Delete(const String& sString, bool bAll)
{
     if (bAll){

          unsigned uCount = 0;
          unsigned uTmp = lData.Find(sString);

          while (uTmp){

               Delete(uTmp);

               uTmp = lData.Find(sString);

               uCount++;

          }

          return uCount;

     } else {

          unsigned uTmp = lData.Find(sString);

          if (uTmp) lData.Delete(uTmp);

          return true;

     }
}

const Containers::String& KuszkAPI::Containers::Strings::GetData(int iNumer) const
{
     return lData.GetData(iNumer);
}

unsigned KuszkAPI::Containers::Strings::Change(const String& sOld, const String& sNew, bool bAll)
{
     unsigned uTmp = lData.Find(sOld);

     if (uTmp) if (bAll){

          unsigned uCount = 0;

          while (uTmp){

               lData[uTmp] = sNew;

               uTmp = lData.Find(sOld);

               uCount++;

          }

          return uCount;

     } else {

          lData[uTmp] = sNew;

          return true;

     } else return false;
}

bool KuszkAPI::Containers::Strings::Change(unsigned uOne, unsigned uTwo)
{
     lData.Change(uOne, uTwo);
}

Containers::String KuszkAPI::Containers::Strings::All(const String& sBreak) const
{
     String sTmp;

     for (int i = 1; i <= uIlosc; i++){

          sTmp += lData.GetData(i);

          if (i != uIlosc) sTmp += sBreak;

     }

     return sTmp;
}

unsigned KuszkAPI::Containers::Strings::Capacity(void) const
{
     return lData.Capacity();
}

bool KuszkAPI::Containers::Strings::Contain(const String& sString) const
{
     return lData.Contain(sString);
}

bool KuszkAPI::Containers::Strings::Empty(void) const
{
     return !uIlosc;
}

bool KuszkAPI::Containers::Strings::Sort(bool bGrow)
{
     return lData.Sort(bGrow);
}

bool KuszkAPI::Containers::Strings::Sort(Strings* ppsStrings[], unsigned uCount, bool bGrow)
{
     List<String>* ppsData[uCount];

     for (int i = 0; i < uCount; i++) ppsData[i] = &ppsStrings[i]->lData;

     return lData.Sort(ppsData, uCount, bGrow);
}

bool KuszkAPI::Containers::Strings::Sort(Strings psStrings[], unsigned uCount, bool bGrow)
{
     List<String>* psData[uCount];

     for (int i = 0; i < uCount; i++) psData[i] = &psStrings[i].lData;

     return lData.Sort(psData, uCount, bGrow);
}

void KuszkAPI::Containers::Strings::Reverse(void)
{
     lData.Reverse();
}

bool KuszkAPI::Containers::Strings::SaveToFile(const String& sPlik, bool bMode) const
{
     String sBufor = All();

     if (!sBufor.Capacity()) return false;

     if (bMode){

          File<wchar_t> fFile(sPlik, MODE_STREAM, OPEN_ALWAYS, GENERIC_WRITE, FILE_SHARE_READ);

          fFile.Data.Add(sBufor.Unicode(), sBufor.Capacity());

          return fFile.Save();

     } else {

          File<char> fFile(sPlik, MODE_STREAM, OPEN_ALWAYS, GENERIC_WRITE, FILE_SHARE_READ);

          fFile.Data.Add(sBufor.Ascii(), sBufor.Capacity());

          return fFile.Save();

     }
}

bool KuszkAPI::Containers::Strings::LoadFromFile(const String& sPlik, bool bMode)
{
     String sBufor;

     Clean();

     if (bMode){

          File<wchar_t> fFile(sPlik, MODE_STREAM, OPEN_EXISTING, GENERIC_READ, FILE_SHARE_READ);

          if (!fFile.Load()) return false;

          if (!fFile.Data.Contain(0)) fFile.Data.Add(0);

          sBufor = fFile.Data.GetBegin();

     } else {

          File<char> fFile(sPlik, MODE_STREAM, OPEN_EXISTING, GENERIC_READ, FILE_SHARE_READ);

          if (!fFile.Load()) return false;

          if (!fFile.Data.Contain(0)) fFile.Data.Add(0);

          sBufor = fFile.Data.GetBegin();

     }

     if (sBufor.Contain(TEXT('\n'))){

          sBufor.Delete(TEXT('\r'), true);

          Add(sBufor, TEXT('\n'), false);

     } else if (sBufor.Contain(TEXT('\r'))){

          sBufor.Delete(TEXT('\n'), true);

          Add(sBufor, TEXT('\r'), false);

     } else Add(sBufor, 0);

     return true;
}

bool KuszkAPI::Containers::Strings::AddToFile(const String& sPlik, bool bMode) const
{
     String sBufor = All();

     if (!sBufor.Capacity()) return false;

     if (bMode){

          File<wchar_t> fFile(sPlik, MODE_STREAM, OPEN_ALWAYS, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ);

          if (!fFile.Load()) return false;

          fFile.Data.Add(sBufor.Unicode(), sBufor.Capacity());

          return fFile.Save();

     } else {

          File<char> fFile(sPlik, MODE_STREAM, OPEN_ALWAYS, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ);

          if (!fFile.Load()) return false;

          fFile.Data.Add(sBufor.Ascii(), sBufor.Capacity());

          return fFile.Save();

     }
}

void KuszkAPI::Containers::Strings::DeleteFile(const String& sPlik) const
{
     DeleteFile(sPlik.Str());
}

void KuszkAPI::Containers::Strings::SetMode(unsigned uNewMode)
{
     lData.SetMode(uNewMode);
}

unsigned KuszkAPI::Containers::Strings::GetMode(void) const
{
     return lData.GetMode();
}

void KuszkAPI::Containers::Strings::Clean(void)
{
     lData.Clean();

     uIlosc = 0;
}

Containers::String& KuszkAPI::Containers::Strings::operator[] (int iNumer)
{
     return lData[iNumer];
}

Containers::String& KuszkAPI::Containers::Strings::operator[] (const String& sString)
{
     return lData[lData.Find(sString)];
}

Containers::Strings& KuszkAPI::Containers::Strings::operator<< (const String& sString)
{
     Add(sString);

     return *this;
}

Containers::Strings& KuszkAPI::Containers::Strings::operator>> (String& sString)
{
     if (!uIlosc) return *this;

     lData >> sString;

     uIlosc--;

     return *this;
}

bool KuszkAPI::Containers::Strings::operator== (const Strings& sStrings) const
{
     if (this == &sStrings) return true;

     return lData == sStrings.lData;
}

bool KuszkAPI::Containers::Strings::operator!= (const Strings& sStrings) const
{
     if (this == &sStrings) return false;

     return lData != sStrings.lData;
}

Containers::Strings KuszkAPI::Containers::Strings::operator+ (const Strings& sStrings) const
{
     Strings sTmp;

     sTmp.lData = lData + sStrings.lData;
     sTmp.uIlosc = uIlosc + sStrings.uIlosc;

     return sTmp;
}

Containers::Strings& KuszkAPI::Containers::Strings::operator+= (const Strings& sStrings)
{
     lData = lData + sStrings.lData;
     uIlosc = lData + sStrings.uIlosc;

     return *this;
}

Containers::Strings& KuszkAPI::Containers::Strings::operator= (const Strings& sStrings)
{
     if (this == &sStrings) return *this;

     lData = sStrings.lData;
     uIlosc = sStrings.uIlosc;

     return *this;
}

KuszkAPI::Containers::Strings::operator String (void) const
{
     return All();
}

KuszkAPI::Containers::Strings::operator bool (void) const
{
     return !Empty();
}
