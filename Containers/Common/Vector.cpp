using namespace KuszkAPI;

template<typename tnData> template<typename tnPrev>
KuszkAPI::Containers::Vector<tnData>::Vector(const Vector<tnPrev>& vVector)
{
      unsigned uOldSize = sizeof(tnPrev);
      unsigned uOldCount = vVector.Capacity();
      uDataSize = sizeof(tnData);
      ptBegin = new tnData[uOldCount * uOldSize / uDataSize];
      uIlosc = uOldCount * uOldSize / uDataSize;
      uMode = MODE_QUEUE;
      memcpy(ptBegin, vVector.GetBegin(), uOldCount * uOldSize);
      memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Vector<tnData>::Vector(const Vector<tnData>& vVector)
{
      uDataSize = sizeof(tnData);
      ptBegin = new tnData[vVector.uIlosc];
      uIlosc = vVector.uIlosc;
      uMode = vVector.uMode;
      memcpy(ptBegin, vVector.ptBegin, vVector.uIlosc * uDataSize);
      memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Vector<tnData>::Vector(const Array<tnData>& aArray)
{
      uDataSize = sizeof(tnData);
      ptBegin = new tnData[aArray.Capacity()];
      uIlosc = aArray.Capacity();
      uMode = aArray.GetMode();
      memcpy(ptBegin, aArray.GetBegin(), aArray.Capacity() * uDataSize);
      memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Vector<tnData>::Vector(const List<tnData>& lList)
{
      uDataSize = sizeof(tnData);
      uIlosc = lList.Capacity();
      uMode = lList.GetMode();
      ptBegin = new tnData[uIlosc];
      for (int i = 0; i < uIlosc; i++) ptBegin[i] = lList.GetData(i + 1);
      memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Vector<tnData>::Vector(const tnData ptData[], unsigned uCount)
{
      uDataSize = sizeof(tnData);
      ptBegin = new tnData[uCount];
      uIlosc = uCount;
      uMode = MODE_QUEUE;
      memcpy(ptBegin, ptData, uCount * uDataSize);
      memset(&tAbstract, 0, uDataSize);
}

template<typename tnData>
KuszkAPI::Containers::Vector<tnData>::Vector(void)
{
      memset(&tAbstract, 0, sizeof(tnData));
      uDataSize = sizeof(tnData);
      ptBegin = NULL;
}

template<typename tnData>
KuszkAPI::Containers::Vector<tnData>::~Vector(void)
{
      if (ptBegin) delete [] ptBegin;
}

template<typename tnData>
unsigned KuszkAPI::Containers::Vector<tnData>::Add(const tnData& tData, int iPos, bool bMode)
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
unsigned KuszkAPI::Containers::Vector<tnData>::Add(const tnData ptData[], unsigned uCount, int iPos, bool bMode)
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
bool KuszkAPI::Containers::Vector<tnData>::Delete(int iNumer)
{
      if (iNumer > uIlosc) return false;
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
const tnData& KuszkAPI::Containers::Vector<tnData>::GetData(int iNumer) const
{
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer < 0) return tAbstract; else return ptBegin[iNumer - 1];
}

template<typename tnData>
const tnData* KuszkAPI::Containers::Vector<tnData>::GetBegin(void) const
{
      return ptBegin;
}

template<typename tnData>
const tnData* KuszkAPI::Containers::Vector<tnData>::GetEnd(void) const
{
      if (uIlosc) return ptBegin + uIlosc - 1; else return NULL;
}

template<typename tnData>
unsigned KuszkAPI::Containers::Vector<tnData>::Find(const tnData& tData) const
{
      for (int i = 0; i < uIlosc; i++) if (ptBegin[i] == tData) return ++i;
      return 0;
}

template<typename tnData>
bool KuszkAPI::Containers::Vector<tnData>::Contain(const tnData& tData) const
{
      for (int i = 0; i < uIlosc; i++) if (ptBegin[i] == tData) return true;
      return false;
}

template<typename tnData>
bool KuszkAPI::Containers::Vector<tnData>::Change(unsigned uOne, unsigned uTwo)
{
      if (uOne == uTwo || uOne > uIlosc || uTwo > uIlosc || !uIlosc) return false;
      return Container::Change((*this)[uOne], (*this)[uTwo]);
}

template<typename tnData>
unsigned KuszkAPI::Containers::Vector<tnData>::Change(const tnData& tOld, const tnData& tNew, bool bAll)
{
      unsigned uTmp = Find(tOld);
      if (uTmp) if (bAll){
              unsigned uCount = 0;
              while (uTmp){
                        (*this)[uTmp] = tNew;
                        uTmp = Find(tOld);
                        uCount++;
              }
              return uCount;
      } else {
              (*this)[uTmp] = tNew;
              return true;
      } else return false;
}

template<typename tnData>
bool KuszkAPI::Containers::Vector<tnData>::Sort(bool bGrow)
{
      if (!uIlosc) return false;
      KuszkAPI::Containers::Vector<tnData>::Sort(ptBegin, uIlosc, bGrow);
      return true;
}

template<typename tnData>
bool KuszkAPI::Containers::Vector<tnData>::Sort(Vector<tnData>* pptData[], unsigned uCount, bool bGrow)
{
      if (!uIlosc) return false;
      for (int i = 0; i < uCount; i++) if (uIlosc != pptData[i]->uIlosc) return false;
      for (int i = 1; i < uIlosc; i++){
              int iMax = i;
              for (int j = i + 1; j <= uIlosc; j++) if (GetData(j) < GetData(iMax)) iMax = j;
              for (int j = 0; j < uCount; j++) if (pptData[j] != this) pptData[j]->Change(iMax, i);
              Change(iMax, i);
      }
      if (!bGrow){
              Reverse();
              for (int j = 0; j < uCount; j++) if (pptData[j] != this) pptData[j]->Reverse();
      }
      return true;
}

template<typename tnData>
void KuszkAPI::Containers::Vector<tnData>::Reverse(void)
{
      KuszkAPI::Containers::Vector<tnData>::Reverse(ptBegin, uIlosc);
}

template<typename tnData>
void KuszkAPI::Containers::Vector<tnData>::Clean(void)
{
      if (ptBegin) delete [] ptBegin;
      ptBegin = NULL;
      uIlosc = 0;
}

template<typename tnData>
tnData& KuszkAPI::Containers::Vector<tnData>::operator[] (int iNumer)
{
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer < 0) return tAbstract; else return ptBegin[iNumer - 1];
}

template<typename tnData>
const tnData& KuszkAPI::Containers::Vector<tnData>::operator[] (int iNumer) const
{
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer < 0) return tAbstract; else return ptBegin[iNumer - 1];
}

template<typename tnData>
Containers::Vector<tnData>& KuszkAPI::Containers::Vector<tnData>::operator<< (const tnData& tData)
{
      Add(tData);
      return *this;
}

template<typename tnData>
Containers::Vector<tnData>& KuszkAPI::Containers::Vector<tnData>::operator>> (tnData& tData)
{
      if (!uIlosc) return *this;
      if (uMode){
              tData = (*this)[uIlosc];
              Delete(uIlosc);
      } else {
              tData = (*this)[1];
              Delete(1);
      }
      return *this;
}

template<typename tnData>
bool KuszkAPI::Containers::Vector<tnData>::operator== (const Vector<tnData>& vVector) const
{
      if (this == &vVector) return true;
      if (uIlosc != vVector.uIlosc) return false;
      else for (int i = 0; i < uIlosc; i++) if (GetData(i) != vVector.GetData(i)) return false;
      return true;
}

template<typename tnData>
bool KuszkAPI::Containers::Vector<tnData>::operator!= (const Vector<tnData>& vVector) const
{
      if (this == &vVector) return false;
      if (uIlosc != vVector.uIlosc) return true;
      else for (int i = 0; i < uIlosc; i++) if (GetData(i) != vVector.GetData(i)) return true;
      return false;
}

template<typename tnData>
Containers::Vector<tnData> KuszkAPI::Containers::Vector<tnData>::operator+ (const Vector<tnData>& vVector) const
{
      KuszkAPI::Containers::Vector<tnData> vTmp;
      vTmp.Add(ptBegin, uIlosc);
      vTmp.Add(vVector.ptBegin, vVector.uIlosc);
      return vTmp;
}

template<typename tnData>
Containers::Vector<tnData>& KuszkAPI::Containers::Vector<tnData>::operator+= (const Vector<tnData>& vVector)
{
      Add(vVector.ptBegin, vVector.uIlosc);
      return *this;
}

template<typename tnData>
Containers::Vector<tnData>& KuszkAPI::Containers::Vector<tnData>::operator= (const Vector<tnData>& vVector)
{
      if (this == &vVector) return *this;
      Clean();
      uIlosc = vVector.uIlosc;
      ptBegin = new tnData[uIlosc];
      memcpy(ptBegin, vVector.ptBegin, uIlosc * uDataSize);
      return *this;
}

template<typename tnData>
void KuszkAPI::Containers::Vector<tnData>::Sort(tnData ptData[], unsigned uCount, bool bGrow = true)
{
      for (int i = 0; i < uCount - 1; i++){
              int iMax = i;
              for (int j = i + 1; j < uCount; j++) if (ptData[j] < ptData[iMax]) iMax = j;
              Container::Change(ptData[iMax], ptData[i]);
      }
      if (!bGrow) KuszkAPI::Containers::Vector<tnData>::Reverse(ptData, uCount);
}

template<typename tnData>
void KuszkAPI::Containers::Vector<tnData>::Reverse(tnData ptData[], unsigned uCount)
{
      for (int i = 0; i < uCount / 2; i++) Container::Change(ptData[i], ptData[uCount - i - 1]);
}
