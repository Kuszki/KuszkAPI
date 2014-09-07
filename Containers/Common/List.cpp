using namespace KuszkAPI;

template<typename tnData>
KuszkAPI::Containers::List<tnData>::List(const KuszkAPI::Containers::List<tnData>& lList)
{
      ptBegin = NULL;
      ptLast = NULL;
      uMode = lList.GetMode();
      for (int i = 1; i <= lList.uIlosc; i++) Add(lList.GetData(i));
}

template<typename tnData>
KuszkAPI::Containers::List<tnData>::List(const Vector<tnData>& vVector)
{
      ptBegin = NULL;
      ptLast = NULL;
      uMode = vVector.GetMode();
      for (int i = 1; i <= vVector.Capacity(); i++) Add(vVector.GetData(i));
}

template<typename tnData>
KuszkAPI::Containers::List<tnData>::List(const Array<tnData>& aArray)
{
      ptBegin = NULL;
      ptLast = NULL;
      uMode = aArray.GetMode();
      for (int i = 1; i <= aArray.Capacity(); i++) Add(aArray.GetData(i));
}

template<typename tnData>
KuszkAPI::Containers::List<tnData>::List(const tnData ptData[], unsigned uCount)
{
      ptBegin = NULL;
      ptLast = NULL;
      for (int i = 0; i < uCount; i++) Add(ptData[i]);
}

template<typename tnData>
KuszkAPI::Containers::List<tnData>::List(void)
{
      ptBegin = NULL;
      ptLast = NULL;
}

template<typename tnData>
KuszkAPI::Containers::List<tnData>::~List(void)
{
      Clean();
}

template<typename tnData>
unsigned KuszkAPI::Containers::List<tnData>::Add(const tnData& tData, int iPos, bool bMode)
{
      if (iPos < 1) iPos += uIlosc;
      if (iPos > uIlosc || iPos < 0) return uIlosc;
      ItemData* ptNowy = new ItemData;
      ptNowy->ptData = new tnData(tData);
      if (!bMode) iPos--;
      if (iPos == uIlosc){
              ptNowy->ptNext = NULL;
              if (ptLast) ptLast->ptNext = ptNowy;
              if (!ptBegin) ptBegin = ptNowy;
              ptLast = ptNowy;
      } else if (iPos == 0){
              ptNowy->ptNext = ptBegin;
              ptBegin = ptNowy;
      } else {
              ItemData* ptTmp = ptBegin;
              for (int i = 1; i < iPos; i++) ptTmp = ptTmp->ptNext;
              ptNowy->ptNext = ptTmp->ptNext;
              ptTmp->ptNext = ptNowy;
      }

      return ++uIlosc;
}

template<typename tnData>
unsigned KuszkAPI::Containers::List<tnData>::Add(const tnData ptData[], unsigned uCount, int iPos, bool bMode)
{
      if (iPos < 1) iPos += uIlosc;
      if (iPos > uIlosc || iPos < 0) return uIlosc;
      for (int i = 0; i < uCount; i++) Add(ptData[i], iPos ? iPos + i : 0, bMode);
      return uIlosc;
}

template<typename tnData>
bool KuszkAPI::Containers::List<tnData>::Delete(int iNumer)
{
      ItemData* ptBufor = ptBegin;
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer < 0) return false; else if (iNumer > 1){
                 for (unsigned i = 1; i < iNumer - 1; i++){
                       ptBufor = ptBufor->ptNext;
                       if (!ptBufor->ptNext) return false;
                 }
                 ItemData* ptTmp = ptBufor->ptNext;
                 ptBufor->ptNext = ptTmp->ptNext;
                 delete ptTmp;
      } else {
                 if (!ptBegin) return false;
                 ItemData* ptTmp = ptBegin;
                 ptBegin = ptTmp->ptNext;
                 delete ptTmp;
      }
      uIlosc--;
      return true;
}

template<typename tnData>
const tnData& KuszkAPI::Containers::List<tnData>::GetData(int iNumer) const
{
      ItemData* ptBufor = ptBegin;
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer <= 0) return tAbstract; else if (ptBufor){
                 for (unsigned i = 1; i < iNumer; i++){
                       ptBufor = ptBufor->ptNext;
                       if (!ptBufor) return tAbstract;
                 }
                 return *ptBufor->ptData;
      }
      return tAbstract;
}

template<typename tnData>
unsigned KuszkAPI::Containers::List<tnData>::Find(const tnData& tData) const
{
      for (int i = 1; i <= uIlosc; i++) if (GetData(i) == tData) return i;
      return 0;
}

template<typename tnData>
bool KuszkAPI::Containers::List<tnData>::Contain(const tnData& tData) const
{
      for (int i = 1; i <= uIlosc; i++) if (GetData(i) == tData) return true;
      return false;
}

template<typename tnData>
bool KuszkAPI::Containers::List<tnData>::Change(int uOne, int uTwo)
{
      if (uOne < 1) uOne += uIlosc;
      if (uTwo < 1) uTwo += uIlosc;
      if (uOne == uTwo || uOne > uIlosc || uTwo > uIlosc || !uIlosc) return false;
      return Container::Change((*this)[uOne], (*this)[uTwo]);
}

template<typename tnData>
unsigned KuszkAPI::Containers::List<tnData>::Change(const tnData& tOld, const tnData& tNew, bool bAll)
{
      unsigned uTmp = Find(tOld);
      if (uTmp) if (bAll){
              unsigned uCount = NULL;
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
bool KuszkAPI::Containers::List<tnData>::Sort(bool bGrow)
{
      if (!uIlosc) return false;
      for (int i = 1; i < uIlosc ; i++){
              int iMax = i;
              for (int j = i + 1; j <= uIlosc; j++) if (GetData(j) < GetData(iMax)) iMax = j;
              Change(iMax, i);
      }
      if (!bGrow) Reverse();
      return true;
}

template<typename tnData>
bool KuszkAPI::Containers::List<tnData>::Sort(KuszkAPI::Containers::List<tnData>* pptData[], unsigned uCount, bool bGrow)
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
void KuszkAPI::Containers::List<tnData>::Reverse(void)
{
      for (int i = 1; i <= uIlosc / 2; i++) Container::Change((*this)[i], (*this)[uIlosc - i + 1]);
}

template<typename tnData>
void KuszkAPI::Containers::List<tnData>::Clean(void)
{
      while (ptBegin){
                 ptLast = ptBegin->ptNext;
                 delete ptBegin->ptData;
                 delete ptBegin;
                 ptBegin = ptLast;
      }
      ptBegin = NULL;
      ptLast = NULL;
      uIlosc = 0;
}

template<typename tnData>
tnData& KuszkAPI::Containers::List<tnData>::operator[] (int iNumer)
{
      ItemData* ptBufor = ptBegin;
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer <= 0) return tAbstract; else if (ptBufor){
                 for (unsigned i = 1; i < iNumer; i++){
                       ptBufor = ptBufor->ptNext;
                       if (!ptBufor) return tAbstract;
                 }
                 return *ptBufor->ptData;
      }
      return tAbstract;
}

template<typename tnData>
const tnData& KuszkAPI::Containers::List<tnData>::operator[] (int iNumer) const
{
      ItemData* ptBufor = ptBegin;
      if (iNumer < 1) iNumer += uIlosc;
      if (iNumer > uIlosc || iNumer <= 0) return tAbstract; else if (ptBufor){
                 for (unsigned i = 1; i < iNumer; i++){
                       ptBufor = ptBufor->ptNext;
                       if (!ptBufor) return tAbstract;
                 }
                 return *ptBufor->ptData;
      }
      return tAbstract;
}

template<typename tnData>
Containers::List<tnData>& KuszkAPI::Containers::List<tnData>::operator<< (const tnData& tData)
{
      Add(tData);
      return *this;
}

template<typename tnData>
Containers::List<tnData>& KuszkAPI::Containers::List<tnData>::operator>> (tnData& tData)
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
bool KuszkAPI::Containers::List<tnData>::operator== (const KuszkAPI::Containers::List<tnData>& lList) const
{
      if (this == &lList) return true;
      if (uIlosc != lList.uIlosc) return false;
      else for (int i = 0; i < uIlosc; i++) if (GetData(i) != lList.GetData(i)) return false;
      return true;
}

template<typename tnData>
bool KuszkAPI::Containers::List<tnData>::operator!= (const KuszkAPI::Containers::List<tnData>& lList) const
{
      if (this == &lList) return false;
      if (uIlosc != lList.uIlosc) return true;
      else for (int i = 0; i < uIlosc; i++) if (GetData(i) != lList.GetData(i)) return true;
      return false;
}

template<typename tnData>
Containers::List<tnData> KuszkAPI::Containers::List<tnData>::operator+ (const KuszkAPI::Containers::List<tnData>& lList) const
{
      KuszkAPI::Containers::List<tnData> lTmp;
      for (int i = 1; i <= uIlosc; i++) lTmp.Add(GetData(i));
      for (int i = 1; i <= lList.uIlosc; i++) lTmp.Add(lList.GetData(i));
      return lTmp;
}

template<typename tnData>
Containers::List<tnData>& KuszkAPI::Containers::List<tnData>::operator+= (const KuszkAPI::Containers::List<tnData>& lList)
{
      for (int i = 1; i <= lList.uIlosc; i++) Add(lList.GetData(i));
      return *this;
}

template<typename tnData>
Containers::List<tnData>& KuszkAPI::Containers::List<tnData>::operator= (const KuszkAPI::Containers::List<tnData>& lList)
{
      if (this == &lList) return *this;
      Clean();
      for (int i = 1; i <= lList.uIlosc; i++) Add(lList.GetData(i));
      return *this;
}
