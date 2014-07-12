/*! \file
    \brief Deklaracje dla pliku Container.cpp.

Plik zawiera jedynie deklaracje z protoypami klasy Container włącznie z jej polami i metodami.
*/

using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Containers)

// --- ABSTRACTS DECLARATIONS ----
class Container;
// ------------------------------

// --- CONTANIER DECLARATIONS ---
class Container
{
      protected:
              unsigned uIlosc;
              unsigned uMode;
      public:
              Container(void);
              virtual ~Container(void);
              unsigned Capacity(void) const;
              bool Empty(void) const;
              void SetMode(unsigned uNewMode);
              unsigned GetMode(void) const;
              operator bool (void) const;
              virtual bool Delete(int iNumer) = 0;
              virtual void Clean(void) = 0;
              template<typename tnData> static bool Change(tnData& tOne,
                                                            tnData& tTwo);
              template<typename tnData> static void Copy(const tnData& tSource,
                                                          tnData& tDestonation);
};
// ------------------------------

KUSZKAPI_NAMESPACE_END
