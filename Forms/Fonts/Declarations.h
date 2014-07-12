using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Forms)

// --- TEMPLATES DECLARATIONS ---
template<typename tnKey> class Font;
// ------------------------------

// ----- FONT DECLARATIONS ------
template<typename tnKey = unsigned> class Font
{
      private:
              struct ItemData
              {
                       HFONT hFont;
                       LOGFONT lFont;
                       COLORREF cColor;
              };
              const HWND& hOwner;
              static HFONT hDef;
              Containers::Map<ItemData, tnKey> mFont;
      public:
              Font(const HWND& hOwn);
              ~Font(void);
              HFONT Add(const tnKey& tKey,
                        const Containers::String& sFont,
                        unsigned short uSize,
                        COLORREF cColor = 0,
                        unsigned uStyle = 0,
                        unsigned short uBold = FW_DONTCARE);
              HFONT Add(const tnKey& tKey,
                        HWND hOwn = NULL);
              void Delete(const tnKey& tKey);
              HFONT Set(const tnKey& tKey,
                        HWND hOwn = NULL);
              void SetColor(const tnKey& tKey,
                            HWND hOwn = NULL);
              COLORREF GetColor(const tnKey& tKey) const;
              LOGFONT GetData(const tnKey& tKey) const;
              HFONT GetHandle(const tnKey& tKey) const;
              void Clean(void);
              HFONT operator[] (const tnKey& tKey) const;
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
