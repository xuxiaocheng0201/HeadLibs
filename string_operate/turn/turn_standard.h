#ifndef HLS_TURN_STANDARD_H
#define HLS_TURN_STANDARD_H

#include "../../logger.h"
#include "../../max_min_null.h"

/*
bool
short
unsigned short
int
unsigned int
long long
unsigned long long

float
double
long double

char
unsigned char
*/

inline bool turn_bool(bool a1)
{
	return a1;
}

inline bool turn_bool(short a1)
{
	return a1;
}

inline bool turn_bool(unsigned short a1)
{
	return a1;
}

inline bool turn_bool(int a1)
{
	return a1;
}

inline bool turn_bool(unsigned int a1)
{
	return a1;
}

inline bool turn_bool(long long a1)
{
	return a1;
}

inline bool turn_bool(unsigned long long a1)
{
	return a1;
}

inline bool turn_bool(float a1)
{
	return a1;
}

inline bool turn_bool(double a1)
{
	return a1;
}

inline bool turn_bool(long double a1)
{
	return a1;
}

inline bool turn_bool(char a1)
{
	return a1;
}

inline bool turn_bool(unsigned char a1)
{
	return a1;
}


inline short turn_short(bool a1)
{
	return a1;
}

inline short turn_short(short a1)
{
	return a1;
}

inline short turn_short(unsigned short a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(unsigned short a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	return a1;
}

inline short turn_short(int a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(int a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	if(a1<_MIN_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(int a1)] a1 is too small.");
		return _MIN_SHORT;
	}
	return a1;
}

inline short turn_short(unsigned int a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(unsigned int a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	return a1;
}

inline short turn_short(long long a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(long long a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	if(a1<_MIN_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(long long a1)] a1 is too small.");
		return _MIN_SHORT;
	}
	return a1;
}

inline short turn_short(unsigned long long a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(unsigned long long a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	return a1;
}

inline short turn_short(float a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(float a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	if(a1<_MIN_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(float a1)] a1 is too small.");
		return _MIN_SHORT;
	}
	return a1;
}

inline short turn_short(double a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(double a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	if(a1<_MIN_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(double a1)] a1 is too small.");
		return _MIN_SHORT;
	}
	return a1;
}

inline short turn_short(long double a1)
{
	if(a1>_MAX_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(long double a1)] a1 is too big.");
		return _MAX_SHORT;
	}
	if(a1<_MIN_SHORT)
	{
		logger("WARN","[TURN.H][turn_short(long double a1)] a1 is too small.");
		return _MIN_SHORT;
	}
	return a1;
}

inline short turn_short(char a1)
{
	return a1;
}

inline short turn_short(unsigned char a1)
{
	return a1;
}


inline unsigned short turn_unsigned_short(bool a1)
{
	return a1;
}

inline unsigned short turn_unsigned_short(short a1)
{
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(short a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(unsigned short a1)
{
	return a1;
}

inline unsigned short turn_unsigned_short(int a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(int a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(int a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(unsigned int a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(unsigned int a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(long long a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(long long a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(long long a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(unsigned long long a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(unsigned long long a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(float a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(float a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(float a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(double a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(double a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(double a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(long double a1)
{
	if(a1>_MAX_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(long double a1)] a1 is too big.");
		return _MAX_UNSIGNED_SHORT;
	}
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(long double a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(char a1)
{
	if(a1<_MIN_UNSIGNED_SHORT)
	{
		logger("WARN","[TURN.H][turn_unsigned_short(char a1)] a1 is too small.");
		return _MIN_UNSIGNED_SHORT;
	}
	return a1;
}

inline unsigned short turn_unsigned_short(unsigned char a1)
{
	return a1;
}


inline int turn_int(bool a1)
{
	return a1;
}

inline int turn_int(short a1)
{
	return a1;
}

inline int turn_int(unsigned short a1)
{
	return a1;
}

inline int turn_int(int a1)
{
	return a1;
}

inline int turn_int(unsigned int a1)
{
	if(a1>_MAX_INT)
	{
		logger("ERROR","[TURN.H][turn_int(unsigned int a1)] a1 is too big.");
		return _MAX_INT;
	}
	return a1;
}

inline int turn_int(long long a1)
{
	if(a1>_MAX_INT)
	{
		logger("WARN","[TURN.H][turn_int(long long a1)] a1 is too big.");
		return _MAX_INT;
	}
	if(a1<_MIN_INT)
	{
		logger("WARN","[TURN.H][turn_int(long long a1)] a1 is too small.");
		return _MIN_INT;
	}
	return a1;
}

inline int turn_int(unsigned long long a1)
{
	if(a1>_MAX_INT)
	{
		logger("WARN","[TURN.H][turn_int(long long a1)] a1 is too big.");
		return _MAX_INT;
	}
	return a1;
}

inline int turn_int(float a1)
{
	if(a1>_MAX_INT)
	{
		logger("WARN","[TURN.H][turn_int(float a1)] a1 is too big.");
		return _MAX_INT;
	}
	return a1;
}

inline int turn_int(double a1)
{
	if(a1>_MAX_INT)
	{
		logger("WARN","[TURN.H][turn_int(double a1)] a1 is too big.");
		return _MAX_INT;
	}
	return a1;
}

inline int turn_int(long double a1)
{
	if(a1>_MAX_INT)
	{
		logger("WARN","[TURN.H][turn_int(long double a1)] a1 is too big.");
		return _MAX_INT;
	}
	return a1;
}

inline int turn_int(char a1)
{
	return a1;
}

inline int turn_int(unsigned char a1)
{
	return a1;
}


inline unsigned int turn_unsigned_int(bool a1)
{
	return a1;
}

inline unsigned int turn_unsigned_int(short a1)
{
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(short a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(unsigned short a1)
{
	return a1;
}

inline unsigned int turn_unsigned_int(int a1)
{
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(int a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(unsigned int a1)
{
	return a1;
}

inline unsigned int turn_unsigned_int(long long a1)
{
	if(a1>_MAX_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(long long a1)] a1 is too big.");
		return _MAX_UNSIGNED_INT;
	}
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(long long a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(unsigned long long a1)
{
	if(a1>_MAX_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(unsigned long long a1)] a1 is too big.");
		return _MAX_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(float a1)
{
	if(a1>_MAX_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(float a1)] a1 is too big.");
		return _MAX_UNSIGNED_INT;
	}
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(float a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(double a1)
{
	if(a1>_MAX_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(double a1)] a1 is too big.");
		return _MAX_UNSIGNED_INT;
	}
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(double a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(long double a1)
{
	if(a1>_MAX_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(long double a1)] a1 is too big.");
		return _MAX_UNSIGNED_INT;
	}
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(long double a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(char a1)
{
	if(a1<_MIN_UNSIGNED_INT)
	{
		logger("WARN","[TURN.H][turn_unsigned_int(char a1)] a1 is too small.");
		return _MIN_UNSIGNED_INT;
	}
	return a1;
}

inline unsigned int turn_unsigned_int(unsigned char a1)
{
	return a1;
}


inline long long turn_long_long(bool a1)
{
	return a1;
}

inline long long turn_long_long(short a1)
{
	return a1;
}

inline long long turn_long_long(unsigned short a1)
{
	return a1;
}

inline long long turn_long_long(int a1)
{
	return a1;
}

inline long long turn_long_long(unsigned int a1)
{
	return a1;
}

inline long long turn_long_long(long long a1)
{
	return a1;
}

inline long long turn_long_long(unsigned long long a1)
{
	if(a1>_MAX_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_long_long(unsigned long long a1)] a1 is too big.");
		return _MAX_LONG_LONG;
	}
	return a1;
}

inline long long turn_long_long(float a1)
{
	if(a1>_MAX_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_long_long(float a1)] a1 is too big.");
		return _MAX_LONG_LONG;
	}
	return a1;
}

inline long long turn_long_long(double a1)
{
	if(a1>_MAX_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_long_long(double a1)] a1 is too big.");
		return _MAX_LONG_LONG;
	}
	return a1;
}

inline long long turn_long_long(long double a1)
{
	if(a1>_MAX_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_long_long(long double a1)] a1 is too big.");
		return _MAX_LONG_LONG;
	}
	return a1;
}

inline long long turn_long_long(char a1)
{
	return a1;
}

inline long long turn_long_long(unsigned char a1)
{
	return a1;
}


inline unsigned long long turn_unsigned_long_long(bool a1)
{
	return a1;
}

inline unsigned long long turn_unsigned_long_long(short a1)
{
	if(a1<_MIN_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(short a1)] a1 is too small.");
		return _MIN_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(unsigned short a1)
{
	return a1;
}

inline unsigned long long turn_unsigned_long_long(int a1)
{
	if(a1<_MIN_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(int a1)] a1 is too small.");
		return _MIN_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(unsigned int a1)
{
	return a1;
}

inline unsigned long long turn_unsigned_long_long(long long a1)
{
	if(a1<_MIN_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(long long a1)] a1 is too small.");
		return _MIN_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(unsigned long long a1)
{
	return a1;
}

inline unsigned long long turn_unsigned_long_long(float a1)
{
	if(a1>_MAX_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(float a1)] a1 is too big.");
		return _MAX_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(double a1)
{
	if(a1>_MAX_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(double a1)] a1 is too big.");
		return _MAX_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(long double a1)
{
	if(a1>_MAX_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(long double a1)] a1 is too big.");
		return _MAX_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(char a1)
{
	if(a1<_MIN_UNSIGNED_LONG_LONG)
	{
		logger("WARN","[TURN.H][turn_unsigned_long_long(char a1)] a1 is too small.");
		return _MIN_UNSIGNED_LONG_LONG;
	}
	return a1;
}

inline unsigned long long turn_unsigned_long_long(unsigned char a1)
{
	return a1;
}


inline float turn_float(bool a1)
{
	return a1;
}

inline float turn_float(short a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(short a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(unsigned short a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(unsigned short a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(int a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(int a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(unsigned int a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(unsigned int a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(long long a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(long long a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(unsigned long long a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(unsigned long long a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(float a1)
{
	return a1;
}

inline float turn_float(double a1)
{
	if(a1>_MAX_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(double a1)] a1 is too big.");
		return _MAX_FLOAT;
	}
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(double a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(long double a1)
{
	if(a1>_MAX_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(long double a1)] a1 is too small.");
		return _MAX_FLOAT;
	}
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(long double a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(char a1)
{
	if(a1<_MIN_FLOAT)
	{
		logger("WARN","[TURN.H][turn_float(char a1)] a1 is too small.");
		return _MIN_FLOAT;
	}
	return a1;
}

inline float turn_float(unsigned char a1)
{
	return a1;
}


inline double turn_double(bool a1)
{
	return a1;
}

inline double turn_double(short a1)
{
	if(a1<_MIN_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_double(short a1)] a1 is too small.");
		return _MIN_DOUBLE;
	}
	return a1;
}

inline double turn_double(unsigned short a1)
{
	return a1;
}

inline double turn_double(int a1)
{
	if(a1<_MIN_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_double(int a1)] a1 is too small.");
		return _MIN_DOUBLE;
	}
	return a1;
}

inline double turn_double(unsigned int a1)
{
	return a1;
}

inline double turn_double(long long a1)
{
	if(a1<_MIN_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_double(long long a1)] a1 is too small.");
		return _MIN_DOUBLE;
	}
	return a1;
}

inline double turn_double(unsigned long long a1)
{
	return a1;
}

inline double turn_double(float a1)
{
	return a1;
}

inline double turn_double(double a1)
{
	return a1;
}

inline double turn_double(long double a1)
{
	if(a1>_MAX_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_double(long double a1)] a1 is too big.");
		return _MAX_DOUBLE;
	}
	return a1;
}

inline double turn_double(char a1)
{
	if(a1<_MIN_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_double(char a1)] a1 is too small.");
		return _MIN_DOUBLE;
	}
	return a1;
}

inline double turn_double(unsigned char a1)
{
	return a1;
}


inline long double turn_long_double(bool a1)
{
	return a1;
}

inline long double turn_long_double(short a1)
{
	if(a1<_MIN_LONG_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_long_double(short a1)] a1 is too small.");
		return _MIN_LONG_DOUBLE;
	}
	return a1;
}

inline long double turn_long_double(unsigned short a1)
{
	return a1;
}

inline long double turn_long_double(int a1)
{
	if(a1<_MIN_LONG_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_long_double(int a1)] a1 is too small.");
		return _MIN_LONG_DOUBLE;
	}
	return a1;
}

inline long double turn_long_double(unsigned int a1)
{
	return a1;
}

inline long double turn_long_double(long long a1)
{
	if(a1<_MIN_LONG_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_long_double(long long a1)] a1 is too small.");
		return _MIN_LONG_DOUBLE;
	}
	return a1;
}

inline long double turn_long_double(unsigned long long a1)
{
	return a1;
}

inline long double turn_long_double(float a1)
{
	return a1;
}

inline long double turn_long_double(double a1)
{
	return a1;
}

inline long double turn_long_double(long double a1)
{
	return a1;
}

inline long double turn_long_double(char a1)
{
	if(a1<_MIN_LONG_DOUBLE)
	{
		logger("WARN","[TURN.H][turn_long_double(char a1)] a1 is too small.");
		return _MIN_LONG_DOUBLE;
	}
	return a1;
}

inline long double turn_long_double(unsigned char a1)
{
	return a1;
}


inline char turn_char(bool a1)
{
	return a1;
}

inline char turn_char(short a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(short a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	if(a1<_MIN_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(short a1)] a1 is too small.");
		return _MIN_CHAR;
	}
	return a1;
}

inline char turn_char(unsigned short a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(unsigned short a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	return a1;
}

inline char turn_char(int a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(int a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	if(a1<_MIN_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(int a1)] a1 is too small.");
		return _MIN_CHAR;
	}
	return a1;
}

inline char turn_char(unsigned int a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(unsigned int a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	return a1;
}

inline char turn_char(long long a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(long long a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	if(a1<_MIN_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(long long a1)] a1 is too small.");
		return _MIN_CHAR;
	}
	return a1;
}

inline char turn_char(unsigned long long a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(unsigned long long a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	return a1;
}

inline char turn_char(float a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(float a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	if(a1<_MIN_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(float a1)] a1 is too small.");
		return _MIN_CHAR;
	}
	return a1;
}

inline char turn_char(double a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(double a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	if(a1<_MIN_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(double a1)] a1 is too small.");
		return _MIN_CHAR;
	}
	return a1;
}

inline char turn_char(long double a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(long double a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	if(a1<_MIN_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(long double a1)] a1 is too small.");
		return _MIN_CHAR;
	}
	return a1;
}

inline char turn_char(char a1)
{
	return a1;
}

inline char turn_char(unsigned char a1)
{
	if(a1>_MAX_CHAR)
	{
		logger("WARN","[TURN.H][turn_char(unsigned char a1)] a1 is too big.");
		return _MAX_CHAR;
	}
	return a1;
}


inline unsigned char turn_unsigned_char(bool a1)
{
	return a1;
}

inline unsigned char turn_unsigned_char(short a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(short a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	if(a1<_MIN_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(short a1)] a1 is too small.");
		return _MIN_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(unsigned short a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(unsigned short a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(int a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(int a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	if(a1<_MIN_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(int a1)] a1 is too small.");
		return _MIN_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(unsigned int a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(unsigned int a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(long long a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(long long a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	if(a1<_MIN_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(long long a1)] a1 is too small.");
		return _MIN_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(unsigned long long a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(unsigned long long a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(float a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(float a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(double a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(double a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(long double a1)
{
	if(a1>_MAX_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(long double a1)] a1 is too big.");
		return _MAX_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(char a1)
{
	if(a1<_MIN_UNSIGNED_CHAR)
	{
		logger("WARN","[TURN.H][turn_unsigned_char(char a1)] a1 is too small.");
		return _MIN_UNSIGNED_CHAR;
	}
	return a1;
}

inline unsigned char turn_unsigned_char(unsigned char a1)
{
	return a1;
}

#endif

