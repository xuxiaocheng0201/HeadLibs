#ifndef HLS_SYSTEM_TIME_H
#define HLS_SYSTEM_TIME_H

#include <minwindef.h>
#include <minwinbase.h>
#include <sysinfoapi.h>

SYSTEMTIME get_system_time()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	return st;
}

#endif
