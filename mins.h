#ifndef HLS_MINS_H
#define HLS_MINS_H

#if __cplusplus >= 201103L

//#include <stdlib.h>
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

template<typename num>
num mins(num a1,num a2)
{
	return min(a1,a2);
}

template<typename num,typename... nums>
num mins(num a1,nums... a2)
{
	return min(a1,mins(a2...));
}

#else

#warning Should use --std=c++11 option for compile.

#endif

#endif

