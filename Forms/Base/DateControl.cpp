using namespace KuszkAPI;

KuszkAPI::Forms::DateControl::DateControl(const HWND& hOwn, unsigned uCtrId) : Control(hOwn, uCtrId) {};

KuszkAPI::Forms::DateControl::operator DateTime::Date (void) const
{
     return GetDate();
}
