using namespace KuszkAPI;

template<typename tnData> template<typename tnPrev>
KuszkAPI::Containers::Array<tnData>::Array(const Array<tnPrev>& aArray)
{
     unsigned uOldSize = sizeof(tnPrev);
     unsigned uOldCount = aArray.Capacity();

     uDataSize = sizeof(tnData);

     ptBegin = new tnData[uOldCount * uOldSize / uDataSize];

     uIlosc = uOldCount * uOldSize / uDataSize;

     uMode = MODE_QUEUE;

     memcpy(ptBegin, aArray.GetBegin(), uOldCount * uOldSize);
     memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Array<tnData>::Array(const Array<tnData>& aArray)
{
     uDataSize = sizeof(tnData);

     uIlosc = aArray.uIlosc;

     uMode = aArray.uMode;

     ptBegin = new tnData[uIlosc];

     memcpy(ptBegin, aArray.ptBegin, aArray.uIlosc * uDataSize);
     memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Array<tnData>::Array(const Vector<tnData>& vVector)
{
     uDataSize = sizeof(tnData);

     uIlosc = vVector.Capacity();

     uMode = vVector.GetMode();

     memcpy(ptBegin, vVector.GetBegin(), vVector.Capacity() * uDataSize);
     memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Array<tnData>::Array(const List<tnData>& lList)
{
     uDataSize = sizeof(tnData);

     uIlosc = lList.Capacity();

     uMode = lList.GetMode();

     ptBegin = new tnData[uIlosc];

     for (int i = 0; i < uIlosc; i++) ptBegin[i] = lList.GetData(i + 1);

     memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Array<tnData>::Array(const tnData pptBegin[], unsigned uCount)
{
     uDataSize = sizeof(tnData);

     ptBegin = new tnData[uCount];

     uIlosc = uCount;

     uMode = MODE_QUEUE;

     memcpy(ptBegin, pptBegin, uCount * uDataSize);
     memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Array<tnData>::Array(void)
{
     uDataSize = sizeof(tnData);

     ptBegin = NULL;

     memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Array<tnData>::~Array(void)
{
     if (ptBegin) delete [] ptBegin;
}

template<typename tnData>
unsigned KuszkAPI::Containers::Array<tnData>::Add(const tnData& tData, int iPos, bool bMode)
{
     if (iPos < 1) iPos += uIlosc;
     if (iPos > uIlosc || iPos < 0) return uIlosc; else if (ptBegin){

          tnData* ptTmp = new tnData[uIlosc + 1];

          if (!bMode) iPos--;

          if (iPos == uIlosc){

               memcpy(ptTmp, ptBegin, uDataSize * uIlosc);

               ptTmp[uIlosc] = tData;

          } else {

               memcpy(ptTmp, ptBegin, uDataSize * iPos);
               memcpy(ptTmp + iPos, ptBegin + iPos - 1, uDataSize * (uIlosc - iPos + 1));

               ptTmp[iPos] = tData;

          }

          delete [] ptBegin;

          ptBegin = ptTmp;

          uIlosc++;

     } else {

          uIlosc = 1;

          ptBegin = new tnData[1];

          ptBegin[0] = tData;

     }

     return uIlosc;
}

template<typename tnData>
unsigned KuszkAPI::Containers::Array<tnData>::Add(const tnData ptData[], unsigned uCount, int iPos, bool bMode)
{
     if (!ptData) return uIlosc;

     if (iPos < 1) iPos += uIlosc;
     if (iPos > uIlosc || iPos < 0) return uIlosc; else if (ptBegin){

          tnData* ptTmp = new tnData[uIlosc + uCount];

          if (!bMode) iPos--;

          if (iPos == uIlosc){

               memcpy(ptTmp, ptBegin, uDataSize * uIlosc);
               memcpy(ptTmp + uIlosc, ptData, uDataSize * uCount);

          } else {

               memcpy(ptTmp, ptBegin, uDataSize * iPos);
               memcpy(ptTmp + iPos, ptData, uDataSize * uCount);
               memcpy(ptTmp + uCount + iPos, ptBegin + iPos, uDataSize * (uIlosc - iPos + 1));

          }

          delete [] ptBegin;

          ptBegin = ptTmp;

          uIlosc += uCount;

     } else {

          ptBegin = new tnData[uCount + 1];

          memcpy(ptBegin, ptData, uDataSize * uCount);

          uIlosc = uCount;

     }

     return uIlosc;
}

template<typename tnData>
bool KuszkAPI::Containers::Array<tnData>::Delete(int iNumer)
{
     if (iNumer < 1) iNumer += uIlosc;
     if (iNumer > uIlosc || iNumer <= 0) return false;

     tnData* pBufor = NULL;

     uIlosc--;
     iNumer--;

     if (uIlosc){

          pBufor = new tnData[uIlosc];

          memcpy(pBufor, ptBegin, uDataSize * iNumer);
          memcpy(pBufor + iNumer, ptBegin + iNumer + 1, uDataSize * (uIlosc - iNumer));

     }

     delete [] ptBegin;

     ptBegin = pBufor;

     return true;
}

template<typename tnData>
const tnData& KuszkAPI::Containers::Array<tnData>::GetData(int iNumer) const
{
     if (iNumer < 1) iNumer += uIlosc;
     if (iNumer > uIlosc || iNumer <= 0) return tAbstract; else return ptBegin[iNumer - 1];
}

template<typename tnData>
const tnData* KuszkAPI::Containers::Array<tnData>::GetBegin(void) const
{
     return ptBegin;
}

template<typename tnData>
const tnData* KuszkAPI::Containers::Array<tnData>::GetEnd(void) const
{
     if (uIlosc) return ptBegin + uIlosc - 1; else return NULL;
}

template<typename tnData>
void KuszkAPI::Containers::Array<tnData>::Clean(void)
{
     if (ptBegin) delete [] ptBegin;

     ptBegin = NULL;

     uIlosc = 0;
}

template<typename tnData>
tnData& KuszkAPI::Containers::Array<tnData>::operator[] (int iNumer)
{
     if (iNumer < 1) iNumer += uIlosc;
     if (iNumer > uIlosc || iNumer <= 0) return tAbstract; else return ptBegin[iNumer - 1];
}

template<typename tnData>
const tnData& KuszkAPI::Containers::Array<tnData>::operator[] (int iNumer) const
{
     if (iNumer < 1) iNumer += uIlosc;
     if (iNumer > uIlosc || iNumer <= 0) return tAbstract; else return ptBegin[iNumer - 1];
}

template<typename tnData>
Containers::Array<tnData>& KuszkAPI::Containers::Array<tnData>::operator<< (const tnData& ptBegin)
{
     Add(ptBegin);

     return *this;
}

template<typename tnData>
Containers::Array<tnData>& KuszkAPI::Containers::Array<tnData>::operator>> (tnData& ptBegin)
{
     if (!uIlosc) return *this;

     if (uMode){

          ptBegin = (*this)[uIlosc];

          Delete(uIlosc);

     } else {

          ptBegin = (*this)[1];

          Delete(1);

     }

     return *this;
}

template<typename tnData>
Containers::Array<tnData> KuszkAPI::Containers::Array<tnData>::operator+ (const Array<tnData>& aArray) const
{
     KuszkAPI::Containers::Array<tnData> vTmp;

     vTmp.Add(ptBegin, uIlosc);
     vTmp.Add(aArray.ptBegin, aArray.uIlosc);

     return vTmp;
}

template<typename tnData>
Containers::Array<tnData>& KuszkAPI::Containers::Array<tnData>::operator+= (const Array<tnData>& aArray)
{
     Add(aArray.ptBegin, aArray.uIlosc);

     return *this;
}

template<typename tnData>
Containers::Array<tnData>& KuszkAPI::Containers::Array<tnData>::operator= (const Array<tnData>& aArray)
{
     if (this == &aArray) return *this;

     Clean();

     uIlosc = aArray.uIlosc;

     ptBegin = new tnData[uIlosc];

     memcpy(ptBegin, aArray.ptBegin, uIlosc * uDataSize);

     return *this;
}
