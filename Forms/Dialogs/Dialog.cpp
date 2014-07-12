using namespace KuszkAPI;

KuszkAPI::Forms::Dialog::Dialog(const HWND& hOwn) : hOwner(hOwn), User(hOwner), Common(hOwner) {}

KuszkAPI::Forms::Dialog::~Dialog() {}

void KuszkAPI::Forms::Dialog::Clean(void)
{
      User.Close();
}
