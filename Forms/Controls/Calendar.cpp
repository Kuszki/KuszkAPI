using namespace KuszkAPI;

KuszkAPI::Forms::Calendar::Calendar(const HWND& hOwn, unsigned uCtrId) : DateControl(hOwn, uCtrId) {}

const HWND& KuszkAPI::Forms::Calendar::Create(int iXPos, int iYPos, const DateTime::Date& dDate, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
      Destroy();
      hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), TEXT("Calendar"), uStyl | WS_VISIBLE | WS_CHILD | MCS_DAYSTATE, iXPos, iYPos, 0, 0, hOwner, (HMENU) uId, hInstance, NULL);
      SetFont();
      SetDate(dDate);
      RECT rObszar;
      MonthCal_GetMinReqRect(hUchwyt, &rObszar);
      SetSize(rObszar.right, rObszar.bottom);
      return hUchwyt;
}

void KuszkAPI::Forms::Calendar::SetDate(const DateTime::Date& dDate)
{
      SYSTEMTIME tCzas;
      DateTime::Date::DateDsc tBufor = dDate.GetDate();
      tCzas.wYear = tBufor.Year;
      tCzas.wMonth = tBufor.Month;
      tCzas.wDay = tBufor.Day;
      MonthCal_SetCurSel(hUchwyt, &tCzas);
}

DateTime::Date KuszkAPI::Forms::Calendar::GetDate(void) const
{
      SYSTEMTIME tCzas;
      MonthCal_GetCurSel(hUchwyt, &tCzas);
      return DateTime::Date(tCzas.wDay, tCzas.wMonth, tCzas.wYear);
}
