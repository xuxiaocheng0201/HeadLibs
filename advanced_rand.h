#ifndef HLS_ADVANCED_RAND_H
#define HLS_ADVANCED_RAND_H

#include <stdlib.h>
#include <time.h>

//NOTE: Before running a programme with rand(), please call set_rand_time() at the beginning.
inline void set_rand_time()
{
	srand(time(NULL));
	return;
}

inline int optional_rand(int rand_min,int rand_max)
{
	return rand()%(rand_max-rand_min+1)+rand_min;
}

inline unsigned long long int bigger_rand()
{
	return (((unsigned long long int)rand()<<24)&0xFF000000ul)|(((unsigned long long int)rand()<<12)&0x00FFF000ul)|(((unsigned long long int)rand())&0x00000FFFul);
}

inline int optional_bigger_rand(int rand_min,int rand_max)
{
	return bigger_rand()%(rand_max-rand_min+1)+rand_min;
}

#endif

