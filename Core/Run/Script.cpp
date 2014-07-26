using namespace KuszkAPI;

template<typename tnResult, typename tnParam>
KuszkAPI::Core::Script<tnResult, tnParam>::Script(ExecuteProc fExeFun, PrepareProc fPreFun)
{
     fExe = fExeFun;
     fPre = fPreFun;
}

template<typename tnResult, typename tnParam>
KuszkAPI::Core::Script<tnResult, tnParam>::~Script(void) {}

template<typename tnResult, typename tnParam>
void KuszkAPI::Core::Script<tnResult, tnParam>::SetAction(ExecuteProc fExeFun, PrepareProc fPreFun)
{
     if (fExeFun) fExe = fExeFun;
     if (fPreFun) fPre = fPreFun;
}

template<typename tnResult, typename tnParam>
tnResult KuszkAPI::Core::Script<tnResult, tnParam>::GetValue(void) const
{
     return tLast;
}

template<typename tnResult, typename tnParam>
tnResult KuszkAPI::Core::Script<tnResult, tnParam>::operator() (Containers::Strings sCommand, tnParam tParam) const
{
     if (!fExe || !sCommand) return tnResult();

     unsigned uCode = 0;

     if (fPre){
          Containers::String sTmp(sCommand[1]);
          sCommand.Delete(1);
          uCode = fPre(sTmp, sCommand, tParam);
     }

     if (!GetQuotes(sCommand)) uCode = SCRIPT_ERROR;

     return tLast = fExe(uCode, sCommand, tParam);
}

template<typename tnResult, typename tnParam>
tnResult KuszkAPI::Core::Script<tnResult, tnParam>::operator() (Console& cConsole, tnParam tParam) const
{
     if (!fExe) return tnResult();

     Containers::String sTmp;

     cConsole.Write(TEXT(":> "), false);
     cConsole.Read(sTmp);

     if (!sTmp) return tnResult();

     Containers::Strings sCommand(sTmp, TEXT(' '), true);

     unsigned uCode = 0;

     if (fPre){
          Containers::String sTmp(sCommand[1]);
          sCommand.Delete(1);
          uCode = fPre(sTmp, sCommand, tParam);
     }

     if (!GetQuotes(sCommand)) uCode = SCRIPT_ERROR;

     return tLast = fExe(uCode, sCommand, tParam);
}

template<typename tnResult, typename tnParam>
bool KuszkAPI::Core::Script<tnResult, tnParam>::GetQuotes(Containers::Strings& sParams)
{
     if (sParams.All().Count(TEXT('\"')) % 2) return false;

     for (int i = 1; i <= sParams.Capacity(); i++) switch (sParams[i].Count(TEXT('\"'))){
          case 1:
               for (int j = i++; i <= sParams.Capacity() && j; i++){
                    sParams[j] += TEXT(" ");
                    sParams[j] += sParams[i];

                    if (sParams[i].Contain(TEXT('\"'))){
                         sParams[j].Delete(TEXT('\"'), true);
                         j = 0;
                    }

                    sParams.Delete(i--);
               }
               i = 1;
          break;
          case 2:
               sParams[i].Delete(TEXT('\"'), true);
          break;
     }

     return true;
}
