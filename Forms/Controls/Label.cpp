using namespace KuszkAPI;

KuszkAPI::Forms::Label::Label(const HWND& hOwn, unsigned uCrtId)
: TextControl(hOwn, uCrtId)
{
     hImage = NULL;

     uImgType = 0;
}

Forms::Label& KuszkAPI::Forms::Label::Create(const Containers::String& sTekst, int iXPos, int iYPos, int iSzerokosc, int iWysokosc, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
     Destroy();

     hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), sTekst.Str(), uStyl | WS_VISIBLE | WS_CHILD, iXPos, iYPos, iSzerokosc, iWysokosc, hOwner, (HMENU) uId, hInstance, NULL);

     SetFont();

     return *this;
}

Forms::Label& KuszkAPI::Forms::Label::Create(const Containers::String& sResName, int iXPos, int iYPos, unsigned uStyl, unsigned uExStyl, const Containers::String& sClass)
{
     Destroy();

     if (uStyl & SS_ICON) uImgType = IMAGE_ICON;
     if (uStyl & SS_BITMAP) uImgType = IMAGE_BITMAP;

     hUchwyt = CreateWindowEx(uExStyl, sClass.Str(), sResName.Str(), uStyl | WS_VISIBLE | WS_CHILD, iXPos, iYPos, 0, 0, hOwner, (HMENU) uId, hInstance, NULL);

     return *this;
}

void KuszkAPI::Forms::Label::SetImage(HGDIOBJ hImg)
{
     Clean();

     hImage = CopyImage(hImg, uImgType, 0, 0, 0);

     SendMessage(hUchwyt, STM_SETIMAGE, (WPARAM) uImgType, (LPARAM) hImage);
}

void KuszkAPI::Forms::Label::Clean(void)
{
     if (hImage){

          DeleteObject(hImage);
          hImage = NULL;

     }

     SetText(Containers::String());
}
