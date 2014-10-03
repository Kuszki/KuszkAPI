using namespace KuszkAPI;

KuszkAPI::DateTime::Date::Date(const Date& dDate)
{
     memcpy(&tData, &dDate.tData, sizeof(tm));

     cSeparator = dDate.cSeparator;

     uShowFlag = dDate.uShowFlag;

     uOrderFlag = dDate.uOrderFlag;
}

KuszkAPI::DateTime::Date::Date(const DateDsc& tDate)
{
     memset(&tData, 0, sizeof(tm));

     tData.tm_mday = tDate.Day;
     tData.tm_mon = tDate.Month - 1;
     tData.tm_year = tDate.Year - 1900;

     cSeparator = TEXT('-');

     uShowFlag = DAY | MONTH | YEAR | ZERO;

     uOrderFlag = WDMY;

     mktime(&tData);
}

KuszkAPI::DateTime::Date::Date(unsigned uDay, unsigned uMonth, unsigned uYear)
{
     memset(&tData, 0, sizeof(tm));

     tData.tm_mday = uDay;
     tData.tm_mon = uMonth - 1;
     tData.tm_year = uYear - 1900;

     cSeparator = TEXT('-');

     uShowFlag = DAY | MONTH | YEAR | ZERO;

     uOrderFlag = WDMY;

     mktime(&tData);
}

KuszkAPI::DateTime::Date::Date(bool bNow)
{
     memset(&tData, 0, sizeof(tm));

     cSeparator = TEXT('-');

     uShowFlag = DAY | MONTH | YEAR | ZERO;

     uOrderFlag = WDMY;

     if (bNow) Refresh();
}

KuszkAPI::DateTime::Date::~Date(void)
{
     memset(&tData, 0, sizeof(tm));
}

void KuszkAPI::DateTime::Date::Set(unsigned uDay, unsigned uMonth, unsigned uYear)
{
     memset(&tData, 0, sizeof(tm));

     tData.tm_mday = uDay;
     tData.tm_mon = uMonth - 1;
     tData.tm_year = uYear - 1900;

     mktime(&tData);
}

void KuszkAPI::DateTime::Date::Refresh(void)
{
     time_t tTime = time(NULL);

     tData = *localtime(&tTime);

     tData.tm_hour = 0;
     tData.tm_min = 0;
     tData.tm_sec = 0;
}

DateTime::Date::DateDsc KuszkAPI::DateTime::Date::GetDate(void) const
{
     DateDsc tBufor;

     tBufor.Day = tData.tm_mday;
     tBufor.Month = tData.tm_mon + 1;
     tBufor.Year = tData.tm_year + 1900;
     tBufor.DayName = GetDayName(tData.tm_wday + 1);
     tBufor.MonthName = GetMonthName(tData.tm_mon + 1);

     return tBufor;
}

unsigned KuszkAPI::DateTime::Date::GetDays(void) const
{
     return tData.tm_yday;
}

Containers::String KuszkAPI::DateTime::Date::Str(TCHAR cFormat, unsigned uShow, unsigned uOrder) const
{
     Containers::String sBufor;

     if (!cFormat) cFormat = cSeparator;
     if (!uShow) uShow = uShowFlag;
     if (!uOrder) uOrder = uOrderFlag;

     if (uOrder == WDMY){

          if (uShow & WEEKDAY){

               sBufor += GetDayName((int) tData.tm_wday + 1);

               if (uShow & (DAY | MONTH | YEAR)) sBufor += TEXT(' ');

          }

          if (uShow & DAY){

               if (uShow & ZERO) if (tData.tm_mday < 10) sBufor += TEXT('0');

               sBufor += Containers::String((int) tData.tm_mday);

               if (uShow & (MONTH | YEAR)) if (uShow & WORDS) sBufor += TEXT(' '); else sBufor += cFormat;

          }

          if (uShow & MONTH){

               if (uShow & ZERO) if (tData.tm_mon < 10) sBufor += TEXT('0');
               if (uShow & WORDS) sBufor += GetMonthName(tData.tm_mon + 1); else sBufor += Containers::String((int) tData.tm_mon + 1);
               if (uShow & YEAR) if (uShow & WORDS) sBufor += TEXT(' '); else sBufor += cFormat;

          }

          if (uShow & YEAR) sBufor += Containers::String((int) tData.tm_year + 1900);

     } else if (uOrder == WYMD) {

          if (uShow & WEEKDAY){

               sBufor += GetDayName(tData.tm_wday + 1);

               if (uShow & (DAY | MONTH | YEAR)) sBufor += TEXT(' ');

          }

          if (uShow & YEAR){

               sBufor += Containers::String((int) tData.tm_year + 1900);

               if (uShow & (MONTH | DAY)) if (uShow & WORDS) sBufor += TEXT(' '); else sBufor += cFormat;

          }

          if (uShow & MONTH){

               if (uShow & ZERO) if (tData.tm_mon < 10) sBufor += TEXT('0');
               if (uShow & WORDS) sBufor += GetMonthName(tData.tm_mon + 1); else sBufor += Containers::String((int) tData.tm_mon + 1);
               if (uShow & DAY) if (uShow & WORDS) sBufor += TEXT(' '); else sBufor += cFormat;

          }

          if (uShow & DAY){

               if (uShow & ZERO) if (tData.tm_mday < 10) sBufor += TEXT('0');

               sBufor += Containers::String((int) tData.tm_mday);

          }

     }

     return sBufor;
}

void KuszkAPI::DateTime::Date::SetFormat(TCHAR cFormat, unsigned uShow, unsigned uOrder)
{
     if (cFormat) cSeparator = cFormat;
     if (uShow) uShowFlag = uShow;
     if (uOrder) uOrderFlag = uOrder;
}

bool KuszkAPI::DateTime::Date::operator== (const Date& dData) const
{
     return (dData.tData.tm_mday == tData.tm_mday && dData.tData.tm_mon == tData.tm_mon && dData.tData.tm_year == tData.tm_year);
}

bool KuszkAPI::DateTime::Date::operator!= (const Date& dData) const
{
     return (dData.tData.tm_mday != tData.tm_mday || dData.tData.tm_mon != tData.tm_mon || dData.tData.tm_year != tData.tm_year);
}

bool KuszkAPI::DateTime::Date::operator> (const Date& dData) const
{
     tm tBufOne = tData;
     tm tBufTwo = dData.tData;

     unsigned uBufOne = mktime(&tBufOne);
     unsigned uBufTwo = mktime(&tBufTwo);

     int iBufor = uBufOne / 86400 - uBufTwo / 86400;

     return iBufor > 0;
}

bool KuszkAPI::DateTime::Date::operator< (const Date& dData) const
{
     tm tBufOne = tData;
     tm tBufTwo = dData.tData;

     unsigned uBufOne = mktime(&tBufOne);
     unsigned uBufTwo = mktime(&tBufTwo);

     int iBufor = uBufOne / 86400 - uBufTwo / 86400;

     return iBufor < 0;
}

DateTime::Date KuszkAPI::DateTime::Date::operator+ (const Date& dData) const
{
     tm tBufor = tData;

     time_t tCzas = mktime(&tBufor);

     tBufor = dData.tData;

     tCzas += mktime(&tBufor);

     tm tTmp = *localtime(&tCzas);

     return Date(tTmp.tm_mday, tTmp.tm_mon, tTmp.tm_year + 1900);
}

DateTime::Date KuszkAPI::DateTime::Date::operator+ (unsigned uDays) const
{
     tm tBufor = tData;

     time_t tCzas = mktime(&tBufor);

     tCzas += uDays * 86400;

     tm tTmp = *localtime(&tCzas);

     return Date(tTmp.tm_mday, tTmp.tm_mon, tTmp.tm_year + 1900);
}

int KuszkAPI::DateTime::Date::operator- (const Date& dData) const
{
     tm tBufOne = tData;
     tm tBufTwo = dData.tData;

     unsigned uBufOne = mktime(&tBufOne);
     unsigned uBufTwo = mktime(&tBufTwo);

     int iBufor = uBufOne / 86400 - uBufTwo / 86400;

     return iBufor;
}

DateTime::Date KuszkAPI::DateTime::Date::operator- (unsigned uDays) const
{
     tm tBufor = tData;

     time_t tCzas = mktime(&tBufor);

     tCzas -= uDays * 86400;

     tm tTmp = *localtime(&tCzas);

     return Date(tTmp.tm_mday, tTmp.tm_mon, tTmp.tm_year + 1900);
}

KuszkAPI::DateTime::Date::operator DateDsc (void) const
{
     return GetDate();
}

KuszkAPI::DateTime::Date::operator Containers::String (void) const
{
     return Str();
}

Containers::String KuszkAPI::DateTime::Date::GetMonthName(unsigned uNumer)
{
     if (uNumer > 12 || uNumer < 1) return Containers::String();

     char ppcMonth[][15] = {"Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec", "Lipiec", "Sierpień", "Wrzesień", "Październik", "Listopad", "Grudzień"};

     return Containers::String(ppcMonth[uNumer - 1]);
}

Containers::String KuszkAPI::DateTime::Date::GetDayName(unsigned uNumer)
{
     if (uNumer > 7 || uNumer < 1) return Containers::String();

     char ppcDay[][15] = {"Niedziela", "Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota"};

     return Containers::String(ppcDay[uNumer - 1]);
}
