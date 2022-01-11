#ifndef HLS_PROCESS_EXISTS_H
#define HLS_PROCESS_EXISTS_H

#include <windows.h>
#include <tlhelp32.h>
#include "common/string.h"

DWORD process_exists(string name)
{
	PROCESSENTRY32 pe;
	DWORD id=0;
	HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if(!Process32First(hSnapshot,&pe))
		return 0;
	while(1)
	{
		pe.dwSize=sizeof(PROCESSENTRY32);
		if(!Process32Next(hSnapshot,&pe))
			break;
		if(!strcmp(pe.szExeFile,name.c_str()))
		{
			id=pe.th32ProcessID;
			break;
		}
	}
	CloseHandle(hSnapshot);
	return id;
}

#endif
