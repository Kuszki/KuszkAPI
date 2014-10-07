using namespace KuszkAPI;

KuszkAPI::Forms::CheckControl::CheckControl(const HWND& hOwn, unsigned uCtrId) : TextControl(hOwn, uCtrId) {}

bool KuszkAPI::Forms::CheckControl::GetCheck(void) const
{
     return Button_GetCheck(hUchwyt) == BST_CHECKED;
}

KuszkAPI::Forms::CheckControl::operator bool (void) const
{
     return GetCheck();
}
