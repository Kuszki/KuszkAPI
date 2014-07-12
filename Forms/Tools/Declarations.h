using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Forms)

// ---- CLASES DECLARATIONS -----
class Bitmap;
class Images;
class Icon;
class Cursor;
class Brush;
// ------------------------------

// --- TEMPLATES DECLARATIONS ---
template<typename tnData> class GdiObject;
// ------------------------------

// ---- OBJECT DECLARATIONS -----
template<typename tnData>
class GdiObject
{
      protected:
              Containers::Box<tnData> bObject;
      public:
              GdiObject(void);
              virtual ~GdiObject(void);
              tnData GetHandle(unsigned uNumer) const;
              tnData operator[] (unsigned uNumer) const;
              virtual void Clean(void);
};
// ------------------------------

// ---- BITMAP DECLARATIONS -----
class Bitmap : public GdiObject<HBITMAP>
{
      public:
              struct Size
              {
                       unsigned short X;
                       unsigned short Y;
              };
              Bitmap(const Containers::Strings& sImages = Containers::Strings());
              ~Bitmap(void);
              HBITMAP Load(const Containers::String& sImage);
              HBITMAP Load(HBITMAP hBitmap);
              void Free(unsigned uNumer);
              Size GetSize(unsigned uNumer) const;
              static Size GetBitmapSize(HBITMAP hImage);
};
// ------------------------------

// ----- ICON DECLARATIONS ------
class Icon : public GdiObject<HICON>
{
      public:
              Icon(const Containers::Strings& sImages = Containers::Strings());
              ~Icon(void);
              HICON Load(const Containers::String& sImage);
              void Free(unsigned uNumer);
              void Clean(void);
};
// ------------------------------

// ---- CURSOR DECLARATIONS -----
class Cursor : public GdiObject<HCURSOR>
{
      public:
              Cursor(const Containers::Strings& sImages = Containers::Strings());
              ~Cursor(void);
              HICON Load(const Containers::String& sImage);
              void Free(unsigned uNumer);
              void Clean(void);
};
// ------------------------------

// ----- BRUSH DECLARATIONS -----
class Brush : public GdiObject<HBRUSH>
{
      public:
              Brush(void);
              ~Brush(void);
              HBRUSH Create(COLORREF cColor);
              HBRUSH Create(HBITMAP hImage);
              HBRUSH Create(COLORREF cColor,
                            unsigned uStyle);
              void Delete(unsigned uNumer);
};
// ------------------------------

// ---- REGION DECLARATIONS -----
class Region : public GdiObject<HRGN>
{
      public:
              Region(const Containers::Strings& sRegions = Containers::Strings());
              ~Region(void);
              HRGN Create(HBITMAP hBitmap,
                          COLORREF cMask = RGB(255, 255, 255));
              HRGN Load(const Containers::String& sRegion);
              void Free(unsigned uNumer);
              bool Save(const Containers::String& sRegion,
                        unsigned uNumer) const;
};
// ------------------------------

// ---- IMAGES DECLARATIONS -----
class Images
{
      private:
              HIMAGELIST hUchwyt;
      public:
              Images(unsigned uXSize,
                      unsigned uYSize);
              Images(const Containers::Strings& sImages);
              Images(void);
              ~Images(void);
              HIMAGELIST Create(const Containers::Strings& sImages);
              HIMAGELIST Create(unsigned uXSize,
                                unsigned uYSize);
              void Add(HBITMAP hImage);
              void Delete(unsigned uNumer);
              const HIMAGELIST& GetHandle(void) const;
              void Destroy(void);
              void Clean(void);
              operator const HIMAGELIST& (void) const;
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
