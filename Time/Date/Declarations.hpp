using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(DateTime)

// ---- CLASES DECLARATIONS -----
class Date;
// ------------------------------

// ----- DATE DECLARATIONS ------
class Date
{
     protected:

          tm tData;

          TCHAR cSeparator;

          unsigned uShowFlag;
          unsigned uOrderFlag;

     public:

          struct DateDsc
          {

               unsigned Day;
               unsigned Month;
               unsigned Year;

               Containers::String DayName;
               Containers::String MonthName;

          };

		Date(const Date& dDate);
          Date(const DateDsc& tDate);
          Date(unsigned uDay,
               unsigned uMonth,
               unsigned uYear);
          Date(bool bNow = true);
          ~Date(void);

          void Set(unsigned uDay,
                   unsigned uMonth,
                   unsigned uYear);
          void Refresh(void);
          DateDsc GetDate(void) const;
          unsigned GetDays(void) const;
          Containers::String Str(TCHAR cFormat = 0,
                                 unsigned uShow = 0,
                                 unsigned uOrder = 0) const;
          void SetFormat(TCHAR cFormat = 0,
                         unsigned uShow = 0,
                         unsigned uOrder = 0);
          TCHAR GetFormat(void) const;

          bool operator== (const Date& dData) const;
          bool operator!= (const Date& dData) const;
          bool operator> (const Date& dData) const;
          bool operator< (const Date& dData) const;
          Date operator+ (const Date& dData) const;
          Date operator+ (unsigned uDays) const;
          int operator- (const Date& dData) const;
          Date operator- (unsigned uDays) const;

          operator DateDsc (void) const;
          operator Containers::String (void) const;

          static Containers::String GetMonthName(unsigned uNumer);
          static Containers::String GetDayName(unsigned uNumer);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
