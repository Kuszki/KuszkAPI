using namespace KuszkAPI;

KuszkAPI::Forms::CheckBoxControl::CheckBoxControl(const HWND& hOwn, unsigned uCtrId) : TextControl(hOwn, uCtrId) {}

bool KuszkAPI::Forms::CheckBoxControl::GetCheck(void) const
{
     return Button_GetCheck(hUchwyt) == BST_CHECKED;
}

KuszkAPI::Forms::CheckBoxControl::operator bool (void) const
{
     return GetCheck();
}
