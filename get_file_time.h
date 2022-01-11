#ifndef HLS_GET_FILE_TIME_H
#define HLS_GET_FILE_TIME_H

#include <time.h>
#include <minwindef.h>
#include <minwinbase.h>
#include "common/string.h"
#include "string_operate/turn/turn_wstring.h"

SYSTEMTIME get_file_time(string file_path)
{
	SYSTEMTIME stLocal;
	struct _stat64i32 statbuf;
	_wstat64i32(turn_wstring(file_path).c_str(),&statbuf);
	struct tm *temptm=_localtime64(&statbuf.st_mtime);
	stLocal.wYear=temptm->tm_year+1900;
	stLocal.wMonth=temptm->tm_mon+1;
	stLocal.wDay=temptm->tm_mday;
	stLocal.wDayOfWeek=temptm->tm_wday;
	stLocal.wHour=temptm->tm_hour;
	stLocal.wMinute=temptm->tm_min;
	stLocal.wSecond=temptm->tm_sec;
	stLocal.wMilliseconds=0;
	return stLocal;
}

#endif
