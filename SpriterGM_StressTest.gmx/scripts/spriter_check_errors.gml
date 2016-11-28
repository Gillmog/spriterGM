///spriter_check_errors()
if spriter_GetErrorsCount() > 0
{
    var Error = "";
    
    while(spriter_GetErrorsCount() > 0)
    {
        Error += spriter_GetLastError();
      
        Error +=" ";
    }
    
    show_error(Error, true);
    spriter_ForceGarbageCollection();
}
