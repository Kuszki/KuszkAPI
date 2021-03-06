using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Forms)

// ---- CLASES DECLARATIONS -----
class Button;
class RadioBox;
class CheckBox;
class Label;
class EditBox;
class ListBox;
class ComboBox;
class TableBox;
class TabBox;
class Calendar;
class TrackBar;
class Controls;
// ------------------------------

// ---- BUTTON DECLARATIONS -----
class Button : public TextControl
{

     public:

          Button(const HWND& hOwn,
                 unsigned uCrtId);

          Button& Create(const Containers::String& sTekst,
                         int iXPos,
                         int iYPos,
                         int iSzerokosc,
                         int iWysokosc,
                         unsigned uStyl = 0,
                         unsigned uExStyl = 0,
                         const Containers::String& sClass = Containers::String(WC_BUTTON));

};
// ------------------------------

// ----- RADIO DECLARATIONS -----
class RadioBox : public CheckControl
{

     private:

          struct ItemData
          {

                  HWND hUchwyt;
                  HWND hOwner;

                  unsigned uGroupId;

          };

          static Containers::Box<ItemData> bData;

          unsigned uGroupId;

     public:

          RadioBox(const HWND& hOwn,
                  unsigned uCrtId);
          ~RadioBox(void);

          RadioBox& Create(const Containers::String& sTekst,
                           unsigned uCrtId,
                           int iXPos,
                           int iYPos,
                           int iSzerokosc,
                           int iWysokosc,
                           unsigned uStyl = 0,
                           unsigned uExStyl = 0,
                           const Containers::String& sClass = Containers::String(WC_BUTTON));
          unsigned GetGroupId(void) const;

          virtual void SetCheck(bool bZaznacz = true) override;

};
// ------------------------------

// ----- CHECK DECLARATIONS -----
class CheckBox : public CheckControl
{

     public:

          CheckBox(const HWND& hOwn,
                  unsigned uCrtId);

          CheckBox& Create(const Containers::String& sTekst,
                           int iXPos,
                           int iYPos,
                           int iSzerokosc,
                           int iWysokosc,
                           unsigned uExStyl = 0,
                           unsigned uStyl = 0,
                           const Containers::String& sClass = Containers::String(WC_BUTTON));

          virtual void SetCheck(bool bZaznacz = true) override;

};
// ------------------------------

// ----- LABEL DECLARATIONS -----
class Label : public TextControl
{

     private:

          HGDIOBJ hImage;

          unsigned uImgType;

     public:

          Label(const HWND& hOwn,
                unsigned uCrtId);

          Label& Create(const Containers::String& sTekst,
                        int iXPos,
                        int iYPos,
                        int iSzerokosc,
                        int iWysokosc,
                        unsigned uStyl = SS_LEFT,
                        unsigned uExStyl = 0,
                        const Containers::String& sClass = Containers::String(WC_STATIC));
          Label& Create(const Containers::String& sResName,
                        int iXPos,
                        int iYPos,
                        unsigned uStyl = SS_ICON,
                        unsigned uExStyl = 0,
                        const Containers::String& sClass = Containers::String(WC_STATIC));
          void SetImage(HGDIOBJ hImg);

		virtual void Clean(void) override;

};
// ------------------------------

// ----- EDIT DECLARATIONS ------
class EditBox : public TextControl
{

     public:

          EditBox(const HWND& hOwn,
                  unsigned uCrtId);

          EditBox& Create(int iXPos,
                          int iYPos,
                          int iSzerokosc,
                          int iWysokosc,
                          const Containers::String& sTekst = Containers::String(),
                          unsigned uStyl = 0,
                          unsigned uExStyl = 0,
                          const Containers::String& sClass = Containers::String(WC_EDIT));
          void AddLine(const Containers::String& sTekst,
                              bool bScrool = true);
          void AddLines(const Containers::Strings& sTekst,
                               bool bScrool = true);
          void SetLine(const Containers::String& sTekst,
                              unsigned uNumer);
          void SetLines(const Containers::Strings& sLines,
                               bool bScrool = true);
          Containers::String GetLine(unsigned uNumer) const;
          Containers::Strings GetLines(void) const;
          void SetPass(TCHAR cZnak);
          void Scrool(bool bPos = true);
          unsigned Capacity(void) const;

          operator Containers::Strings (void) const;

          virtual void Clean(void) override;
};
// ------------------------------

// ---- LISTBOX DECLARATIONS ----
class ListBox : public ListControl
{

     public:

          ListBox(const HWND& hOwn,
                  unsigned uCrtId);

          ListBox& Create(int iXPos,
                          int iYPos,
                          int iSzerokosc,
                          int iWysokosc,
                          const Containers::Strings& sLista = Containers::Strings(),
                          unsigned uStyl = 0,
                          unsigned uExStyl = 0,
                          const Containers::String& sClass = Containers::String(WC_LISTBOX));
          void AddItem(const Containers::String& sTekst);
          void AddItems(const Containers::Strings& sLista);
          void SetItems(const Containers::Strings& sLista);

          void Sort(bool bGrow = true);

          virtual void DeleteItem(unsigned uNumer = 0) override;
          virtual Containers::String GetItem(unsigned uNumer = 0) const override;
          virtual Containers::Strings GetItems(void) const override;
          virtual unsigned GetIndex(void) const override;
          virtual unsigned Capacity(void) const override;
          virtual void Clean(void) override;

};
// ------------------------------

// --- COMBOBOX DECLARATIONS ----
class ComboBox : public ListControl
{

     private:

          struct ItemData
          {

                  Containers::String Name;

                  int Icon;

          };

     public:

          Images Icons;

          ComboBox(const HWND& hOwn,
                   unsigned uCrtId);

          ComboBox& Create(int iXPos,
                           int iYPos,
                           int iSzerokosc,
                           int iWysokosc,
                           const Containers::Strings& sLista = Containers::Strings(),
                           unsigned uStyl = CBS_DROPDOWNLIST,
                           unsigned uExStyl = 0,
                           const Containers::String& sClass = Containers::String(WC_COMBOBOXEX));
          void AddItem(const Containers::String& sTekst,
                              unsigned uIkona = 0);
          void AddItems(const Containers::Strings& sLista,
                               unsigned uIkona = 0);
          void SetItem(const Containers::String& sTekst,
                              unsigned uNumer = 0);
          void SetItems(const Containers::Strings& sLista,
                               unsigned uIkona = 0);
          ItemData GetItemStruct(unsigned uNumer = 0) const;
          void SetItemIcon(unsigned uIkona = 0,
                                  unsigned uNumer = 0);
          unsigned GetItemIcon(unsigned uNumer = 0) const;
          void SetImages(bool bEnable);
          void Sort(bool bGrow = true);

		virtual void DeleteItem(unsigned uNumer = 0) override;
          virtual Containers::String GetItem(unsigned uNumer = 0) const override;
          virtual Containers::Strings GetItems(void) const override;
          virtual unsigned GetIndex(void) const override;
          virtual unsigned Capacity(void) const override;
          virtual void Clean(void) override;

};
// ------------------------------

// ----- TABLE DECLARATIONS -----
class TableBox : public ListControl
{

     private:

          struct ItemData
          {

               Containers::String Name;
               Containers::Strings Data;

               int Group;
               int Icon;

          };

          unsigned uColumnCount;
          unsigned uGroupCount;

          bool bGroups;

     public:

          Images Imgs;
          Images Icos;

          TableBox(const HWND& hOwn,
                unsigned uCrtId);
          ~TableBox(void);

          TableBox& Create(int iXPos,
                           int iYPos,
                           int iSzerokosc,
                           int iWysokosc,
                           const Containers::Strings& sHeader = Containers::Strings(),
                           unsigned uStyl = LVS_REPORT | LVS_SINGLESEL,
                           unsigned uExStyl = 0,
                           const Containers::String& sClass = Containers::String(WC_LISTVIEW));
          void AddItem(const Containers::String& sTekst,
                              const Containers::Strings& sData = Containers::Strings(),
                              unsigned uGroup = 0,
                              unsigned uIkona = 0);
          void AddItem(const Containers::Strings& sData,
                              unsigned uGroup = 0,
                              unsigned uIkona = 0);
          void AddItems(const Containers::Strings& sData,
                               unsigned uGroup = 0,
                               unsigned uIcon = 0);
          ItemData GetItemStruct(unsigned uNumer = 0) const;
          void SetItemData(const Containers::String& sTekst,
                                  unsigned uXPos,
                                  unsigned uYPos = 0);
          void SetItemData(const Containers::Strings& sData,
                                  unsigned uNumer = 0);
          Containers::Strings GetItemData(unsigned uNumer = 0) const;
          void SetItemIcon(unsigned uIkona,
                                  unsigned uNumer = 0);
          unsigned GetItemIcon(unsigned uNumer = 0) const;
          void SetItemGroup(unsigned uGroup,
                                   unsigned uNumer = 0);
          unsigned GetItemGroup(unsigned uNumer = 0) const;
          void Select(unsigned uNumer);
          void AddGroup(const Containers::String& sGroup);
          void AddGroups(const Containers::Strings& sGroups);
          void DeleteGroup(unsigned uNumer);
          void SetGroup(const Containers::String& sGroup,
                               unsigned uNumer);
          void SetColumn(const Containers::Strings& sLista,
                                unsigned uNumer);
          Containers::Strings GetColumn(unsigned uNumer = 0) const;
          void SetHeader(const Containers::Strings& sHeader,
                                const Containers::Vector<unsigned> vSizes = Containers::Vector<unsigned>(),
                                const Containers::Vector<unsigned> vIcons = Containers::Vector<unsigned>());
          void SetImages(bool bSmallEnable,
                                bool bLargeEnable);
          unsigned GetColumnCount(void) const;
          void Sort(unsigned uNumer = 1,
                    bool bGrow = true);
          void CleanItems(void);
          void CleanGroups(void);
          void CleanHeader(void);

          virtual void DeleteItem(unsigned uNumer = 0) override;
          virtual Containers::String GetItem(unsigned uNumer = 0) const override;
          virtual Containers::Strings GetItems(void) const override;
          virtual unsigned GetIndex(void) const override;
          virtual unsigned Capacity(void) const override;
          virtual void Clean(void) override;

};
// ------------------------------

// ------ TAB DECLARATIONS ------
class TabBox : public ListControl
{

     protected:

		Containers::Map<unsigned, HWND> mWindows;

     public:

          TabBox(const HWND& hOwn,
                 unsigned uCrtId);

          TabBox& Create(int iXPos,
                         int iYPos,
                         int iSzerokosc,
                         int iWysokosc,
                         const Containers::Strings& sLista = Containers::Strings(),
                         unsigned uStyl = TCS_MULTILINE,
                         unsigned uExStyl = 0,
                         const Containers::String& sClass = Containers::String(WC_TABCONTROL));
          void AddItem(const Containers::String& sTekst);
          void AddItems(const Containers::Strings& sLista);
          void SetItems(const Containers::Strings& sLista);
          void AddControl(HWND hWnd,
                                 unsigned uTab);
          void DeleteControl(HWND hWnd);
          void SetTab(unsigned uNumer = 0);
          unsigned GetTab(void) const;

		virtual void DeleteItem(unsigned uNumer = 0) override;
          virtual Containers::String GetItem(unsigned uNumer = 0) const override;
          virtual Containers::Strings GetItems(void) const override;
          virtual unsigned GetIndex(void) const override;
          virtual unsigned Capacity(void) const override;
          virtual void Clean(void) override;

};
// ------------------------------

// --- CALENDAR DECLARATIONS ----
class Calendar : public DateControl
{

     public:

          Calendar(const HWND& hOwn,
                   unsigned uCtrId);

          Calendar& Create(int iXPos,
                           int iYPos,
                           const DateTime::Date& dDate = DateTime::Date(true),
                           unsigned uStyl = 0,
                           unsigned uExStyl = 0,
                           const Containers::String& sClass = Containers::String(MONTHCAL_CLASS));
          void SetDate(const DateTime::Date& dDate);
          DateTime::Date GetDate(void) const;

};
// ------------------------------

// -- PROGRESSBAR DECLARATIONS --
class ProgressBar : public BarControl
{

     public:

          ProgressBar(const HWND& hOwn,
                             unsigned uCrtId);

          ProgressBar& Create(int iXPos,
                              int iYPos,
                              int iSzerokosc,
                              int iWysokosc,
                              short iStart = 0,
                              short iStop = 100,
                              unsigned uStep = 1,
                              unsigned uStyl = 0,
                              unsigned uExStyl = 0,
                              const Containers::String& sClass = Containers::String(PROGRESS_CLASS));
          void SetValue(unsigned uValue);
          unsigned GetValue(void) const;
          void SetProgress(float fProgress);
          float GetProgress(void) const;
          void Increment(int iValue = 0);


};
// ------------------------------

// --- TRACKBAR DECLARATIONS ----
class TrackBar : public BarControl
{

     public:

          TrackBar(const HWND& hOwn,
                   unsigned uCrtId);

          TrackBar& Create(int iXPos,
                           int iYPos,
                           int iSzerokosc,
                           int iWysokosc,
                           short iStart = 0,
                           short iStop = 10,
                           unsigned uStep = 1,
                           unsigned uStyl = 0,
                           unsigned uExStyl = 0,
                           const Containers::String& sClass = Containers::String(TRACKBAR_CLASS));
          void SetValue(unsigned uValue);
          unsigned GetValue(void) const;


};
// ------------------------------

// --- CONTROLS DECLARATIONS ----
class Controls
{

     private:

          template<typename tnData>
          class Group
          {

			private:

				const HWND& hOwner;

				Containers::Map<tnData, unsigned> mControl;

			public:

				Group(const HWND& hOwn);
				~Group(void);

				tnData& Add(unsigned uId);
				void Delete(unsigned uId);
				void Clean(void);

				tnData& operator[] (unsigned uNumer);

          };

          const HWND& hOwner;

     public:

          Group<Button> Buttons;
          Group<RadioBox> Radios;
          Group<CheckBox> Checks;
          Group<Label> Labels;
          Group<EditBox> Edits;
          Group<ListBox> Lists;
          Group<ComboBox> Combos;
          Group<TableBox> Tables;
          Group<Calendar> Calendars;
          Group<TabBox> Tabs;
          Group<TrackBar> Tracks;
          Group<ProgressBar> Bars;

          Controls(const HWND& hOwn);
          ~Controls(void);

          void Clean(void);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
