#ifndef HLS_COMPARE_SYSTEMTIME_H
#define HLS_COMPARE_SYSTEMTIME_H

#include <minwindef.h>
#include <minwinbase.h>

bool operator==(SYSTEMTIME a,SYSTEMTIME b)
{
	if(a.wYear!=b.wYear)
		return 0;
	if(a.wMonth!=b.wMonth)
		return 0;
	if(a.wDay!=b.wDay)
		return 0;
	if(a.wDayOfWeek!=b.wDayOfWeek)
		return 0;
	if(a.wHour!=b.wHour)
		return 0;
	if(a.wMinute!=b.wMinute)
		return 0;
	if(a.wSecond!=b.wSecond)
		return 0;
	if(a.wMilliseconds!=b.wMilliseconds)
		return 0;
	return 1;
}

bool operator>(SYSTEMTIME a,SYSTEMTIME b)
{
	if(a.wYear<=b.wYear)
		return 0;
	if(a.wMonth<=b.wMonth)
		return 0;
	if(a.wDay<=b.wDay)
		return 0;
	if(a.wDayOfWeek<=b.wDayOfWeek)
		return 0;
	if(a.wHour<=b.wHour)
		return 0;
	if(a.wMinute<=b.wMinute)
		return 0;
	if(a.wSecond<=b.wSecond)
		return 0;
	if(a.wMilliseconds<=b.wMilliseconds)
		return 0;
	return 1;
}

bool operator<(SYSTEMTIME a,SYSTEMTIME b)
{
	if(a.wYear>=b.wYear)
		return 0;
	if(a.wMonth>=b.wMonth)
		return 0;
	if(a.wDay>=b.wDay)
		return 0;
	if(a.wDayOfWeek>=b.wDayOfWeek)
		return 0;
	if(a.wHour>=b.wHour)
		return 0;
	if(a.wMinute>=b.wMinute)
		return 0;
	if(a.wSecond>=b.wSecond)
		return 0;
	if(a.wMilliseconds>=b.wMilliseconds)
		return 0;
	return 1;
}

bool operator>=(SYSTEMTIME a,SYSTEMTIME b)
{
	if(a.wYear<b.wYear)
		return 0;
	if(a.wMonth<b.wMonth)
		return 0;
	if(a.wDay<b.wDay)
		return 0;
	if(a.wDayOfWeek<b.wDayOfWeek)
		return 0;
	if(a.wHour<b.wHour)
		return 0;
	if(a.wMinute<b.wMinute)
		return 0;
	if(a.wSecond<b.wSecond)
		return 0;
	if(a.wMilliseconds<b.wMilliseconds)
		return 0;
	return 1;
}

bool operator<=(SYSTEMTIME a,SYSTEMTIME b)
{
	if(a.wYear>b.wYear)
		return 0;
	if(a.wMonth>b.wMonth)
		return 0;
	if(a.wDay>b.wDay)
		return 0;
	if(a.wDayOfWeek>b.wDayOfWeek)
		return 0;
	if(a.wHour>b.wHour)
		return 0;
	if(a.wMinute>b.wMinute)
		return 0;
	if(a.wSecond>b.wSecond)
		return 0;
	if(a.wMilliseconds>b.wMilliseconds)
		return 0;
	return 1;
}

bool operator!=(SYSTEMTIME a,SYSTEMTIME b)
{
	return !(a==b);
}

#endif
