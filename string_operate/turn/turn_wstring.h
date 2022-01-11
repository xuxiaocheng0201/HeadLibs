#ifndef HLS_TURN_WSTRING_H
#define HLS_TURN_WSTRING_H

#include <minwindef.h>
#include <winnt.h>
#include <winnls.h>
#include "../../common/string.h"

wstring turn_wstring(string a1)
{
	wstring a2;
	int nLen=a1.length();
	a2.resize(nLen,L' ');
	int nResult=MultiByteToWideChar(CP_ACP,0,(LPCSTR)a1.c_str(),nLen,(LPWSTR)a2.c_str(),nLen);
    if(!nResult)
    	return L"";
    return a2;
}
//https://blog.csdn.net/wangshubo1989/article/details/49210385
//https://blog.csdn.net/Nilianfei/article/details/76893686

string turn_string(wstring/*LPCWSTR*/ a1)
{
	string a2;
	int len=WideCharToMultiByte(CP_ACP,0,a1.c_str(),a1.size(),NULL,0,NULL,NULL);
	char* buffer=new char[len+1];
	WideCharToMultiByte(CP_ACP,0,a1.c_str(),a1.size(),buffer,len,NULL,NULL);
	buffer[len]='\0';
	a2.append(buffer);
	delete[] buffer;
	return a2;
}
//https://blog.csdn.net/guhaoxin/article/details/83526876

LPCWSTR turn_LPCWSTR(wstring a1)
{
	return a1.c_str();
}

LPCWSTR turn_LPCWSTR(string a1)
{
	return turn_wstring(a1).c_str();
}

#endif

