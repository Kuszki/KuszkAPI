using namespace KuszkAPI;

KuszkAPI::Forms::ListControl::ListControl(const HWND& hOwn, unsigned uCtrId) : Control(hOwn, uCtrId){}

bool KuszkAPI::Forms::ListControl::Empty(void) const
{
      return !(bool) Capacity();
}

KuszkAPI::Forms::ListControl::operator Containers::Strings (void) const
{
      return GetItems();
}

KuszkAPI::Forms::ListControl::operator bool (void) const
{
      return !Empty();
}
