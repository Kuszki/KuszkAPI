using namespace KuszkAPI;

template<typename tnData>
KuszkAPI::Forms::Controls::Group<tnData>::Group(const HWND& hOwn) : hOwner(hOwn) {}

template<typename tnData>
KuszkAPI::Forms::Controls::Group<tnData>::~Group(void) {}

template<typename tnData>
void KuszkAPI::Forms::Controls::Group<tnData>::Add(unsigned uId)
{
     if (mControl.Allow(uId)) mControl.Add(new tnData(hOwner, uId), uId);
}

template<typename tnData>
void KuszkAPI::Forms::Controls::Group<tnData>::Delete(unsigned uId)
{
     mControl.Delete(uId);
}

template<typename tnData>
void KuszkAPI::Forms::Controls::Group<tnData>::Clean(void)
{
     mControl.Clean();
}

template<typename tnData>
tnData& KuszkAPI::Forms::Controls::Group<tnData>::operator[] (unsigned uNumer)
{
     return mControl[uNumer];
}

KuszkAPI::Forms::Controls::Controls(const HWND& hOwn) : hOwner(hOwn), Buttons(hOwner), Radios(hOwner), Checks(hOwner), Labels(hOwner), Edits(hOwner), Lists(hOwner), Combos(hOwner), Tables(hOwner), Calendars(hOwner), Tabs(hOwner), Tracks(hOwner), Bars(hOwner) {}

KuszkAPI::Forms::Controls::~Controls(void) {}

void KuszkAPI::Forms::Controls::Clean(void)
{
     Buttons.Clean();
     Radios.Clean();
     Checks.Clean();
     Labels.Clean();
     Edits.Clean();
     Lists.Clean();
     Combos.Clean();
     Tables.Clean();
     Calendars.Clean();
     Tabs.Clean();
     Tracks.Clean();
     Bars.Clean();
}
