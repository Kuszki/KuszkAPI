using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(DateTime)

// ---- CLASES DECLARATIONS -----
class Time;
// ------------------------------

// ----- TIME DECLARATIONS ------
class Time
{
      private:
              unsigned uCzas;
              char cSeparator;
              unsigned uShowFlag;
              void Convert(void);
      public:
              struct TTime
              {
                       unsigned Hour;
                       unsigned Min;
                       unsigned Sec;
              };
              Time(const TTime& tTime);
              Time(unsigned uHour,
                    unsigned uMin,
                    unsigned uSec);
              Time(bool bNow = true);
              ~Time(void);
              void Set(unsigned uHour,
                       unsigned uMin,
                       unsigned uSec);
              void Refresh(void);
              TTime GetTime(void) const;
              unsigned GetSeconds(void) const;
              unsigned GetMinutes(void) const;
              unsigned GetHours(void) const;
              Containers::String Str(TCHAR cFormat = 0,
                          unsigned uFlags = 0) const;
              void SetFormat(TCHAR cFormat = 0,
                             unsigned uFlags = 0);
              TCHAR GetFormat(void) const;
              bool operator== (const Time& tCzas) const;
              bool operator!= (const Time& tCzas) const;
              bool operator> (const Time& tCzas) const;
              bool operator< (const Time& tCzas) const;
              Time operator+ (const Time& tCzas) const;
              Time operator- (const Time& tCzas) const;
              Time& operator++ (void);
              Time& operator-- (void);
              Time operator++ (int);
              Time operator-- (int);
              operator TTime (void) const;
              operator Containers::String (void) const;
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
