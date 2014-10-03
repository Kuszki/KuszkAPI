using namespace KuszkAPI;

KuszkAPI::DateTime::Time::Time(const Time& tTime)
{
     cSeparator = tTime.cSeparator;

     uShowFlag = tTime.uShowFlag;

     uCzas = tTime.uCzas;
}

KuszkAPI::DateTime::Time::Time(const TimeDsc& tTime)
{
     cSeparator = TEXT(':');

     uShowFlag = HOURS | MINUTES | SECONDS | ZERO;

     uCzas = tTime.Hour * 3600 + tTime.Min * 60 + tTime.Sec;

     Convert();
}

KuszkAPI::DateTime::Time::Time(unsigned uHour, unsigned uMin, unsigned uSec)
{
     cSeparator = TEXT(':');

     uShowFlag = HOURS | MINUTES | SECONDS | ZERO;

     uCzas = uHour * 3600 + uMin * 60 + uSec;

     Convert();
}

KuszkAPI::DateTime::Time::Time(bool bNow)
{
     cSeparator = TEXT(':');

     uShowFlag = HOURS | MINUTES | SECONDS | ZERO;

     if (bNow) Refresh(); else uCzas = 0;
}

KuszkAPI::DateTime::Time::~Time(void)
{
     uCzas = 0;
}

void KuszkAPI::DateTime::Time::Convert(void)
{
     while (uCzas > 86400) uCzas -= 86400;
}

void KuszkAPI::DateTime::Time::Set(unsigned uHour, unsigned uMin, unsigned uSec)
{
     uCzas = uHour * 3600 + uMin * 60 + uSec;

     Convert();
}

void KuszkAPI::DateTime::Time::Refresh(void)
{
     time_t lCzas = time(NULL);

     tm tCzas = *localtime(&lCzas);

     uCzas = tCzas.tm_hour * 3600 + tCzas.tm_min * 60 + tCzas.tm_sec;
}

KuszkAPI::DateTime::Time::TimeDsc KuszkAPI::DateTime::Time::GetTime(void) const
{
     TimeDsc tWynik;

     tWynik.Hour = uCzas / 3600;
     tWynik.Min = uCzas % 3600 / 60;
     tWynik.Sec = uCzas % 3600 % 60;

     return tWynik;
}

unsigned KuszkAPI::DateTime::Time::GetSeconds(void) const
{
     return uCzas;
}

unsigned KuszkAPI::DateTime::Time::GetMinutes(void) const
{
     return uCzas / 60;
}

unsigned KuszkAPI::DateTime::Time::GetHours(void) const
{
     return uCzas / 3600;
}

Containers::String KuszkAPI::DateTime::Time::Str(TCHAR cFormat, unsigned uFlags) const
{
     Containers::String sBufor;

     TimeDsc tTmp = GetTime();

     if (!cFormat) cFormat = cSeparator;
     if (!uFlags) uFlags = uShowFlag;

     if (uFlags & HOURS){

          if (uFlags & ZERO) if (tTmp.Hour < 10) sBufor += TEXT('0');

          sBufor += Containers::String((int) tTmp.Hour);

          if (uFlags & (MINUTES | SECONDS)) sBufor += cFormat;

     }

     if (uFlags & MINUTES){

          if (uFlags & ZERO) if (tTmp.Min < 10) sBufor += TEXT('0');

          sBufor += Containers::String((int) tTmp.Min);

          if (uFlags & SECONDS) sBufor += cFormat;

     }

     if (uFlags & SECONDS){

          if (uFlags & ZERO) if (tTmp.Sec < 10) sBufor += TEXT('0');

          sBufor += Containers::String((int) tTmp.Sec);

     }

     return sBufor;
}

void KuszkAPI::DateTime::Time::SetFormat(TCHAR cFormat, unsigned uFlags)
{
     if (cFormat) cSeparator = cFormat;
     if (uFlags) uShowFlag = uFlags;
}

TCHAR KuszkAPI::DateTime::Time::GetFormat(void) const
{
     return cSeparator;
}

bool KuszkAPI::DateTime::Time::operator== (const Time& tCzas) const
{
     return uCzas == tCzas.uCzas;
}

bool KuszkAPI::DateTime::Time::operator!= (const Time& tCzas) const
{
     return uCzas != tCzas.uCzas;
}

DateTime::Time KuszkAPI::DateTime::Time::operator+ (const Time& tCzas) const
{
     return Time(0, 0, uCzas + tCzas.uCzas);
}

DateTime::Time KuszkAPI::DateTime::Time::operator- (const Time& tCzas) const
{
     return Time(0, 0, uCzas - tCzas.uCzas);
}

DateTime::Time& KuszkAPI::DateTime::Time::operator++ (void)
{
     uCzas++;

     Convert();

     return *this;
}

DateTime::Time& KuszkAPI::DateTime::Time::operator-- (void)
{
     uCzas--;

     Convert();

     return *this;
}

DateTime::Time KuszkAPI::DateTime::Time::operator++ (int)
{
     Time tTmp(0, 0, uCzas++);

     return tTmp;
}

DateTime::Time KuszkAPI::DateTime::Time::operator-- (int)
{
     Time tTmp(0, 0, uCzas--);

     return tTmp;
}

KuszkAPI::DateTime::Time::operator TimeDsc (void) const
{
     return GetTime();
}

KuszkAPI::DateTime::Time::operator Containers::String (void) const
{
     return Str();
}
