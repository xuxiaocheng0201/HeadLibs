#ifndef HLS_TURN_STRING_H
#define HLS_TURN_STRING_H

#include "../../max_min_null.h"
#include "../../common/string.h"
#include "../../common/stringstream.h"

stringstream turn_string_stream;

inline bool turn_bool(string a1)
{
	if(a1=="1" || a1=="true")
		return 1;
	if(a1=="0" || a1=="false")
		return 0;
	return _NULL_BOOL;
}

inline short turn_short(string a1)
{
	short a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline unsigned short turn_unsigned_short(string a1)
{
	unsigned short a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline int turn_int(string a1)
{
	int a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline unsigned int turn_unsigned_int(string a1)
{
	unsigned int a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline long long turn_long_long(string a1)
{
	long long a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline unsigned long long turn_unsigned_long_long(string a1)
{
	unsigned long long a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline float turn_float(string a1)
{
	float a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline double turn_double(string a1)
{
	double a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline long double turn_long_double(string a1)
{
	long double a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline char turn_char(string a1)
{
	char a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline unsigned char turn_unsigned_char(string a1)
{
	char a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}


inline string turn_string(bool a1)
{
	if(a1)
		return "true";
	return "false";
}

inline string turn_string(short a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(unsigned short a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(int a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(unsigned int a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(long long a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(unsigned long long a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(float a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(double a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(long double a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(char a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

inline string turn_string(unsigned char a1)
{
	string a2;
	a2.clear();
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

#endif

