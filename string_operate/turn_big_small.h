#ifndef HLS_TURN_BIG_SMALL_H
#define HLS_TURN_BIG_SMALL_H

#include "../common/string.h"

string turn_small(string a)
{
	for(unsigned int i=0;i<a.size();i++)
		if('A'<=a[i] && a[i]<='Z')
			a[i]+='a'-'A';
	return a;
}

string turn_big(string a)
{
	for(unsigned int i=0;i<a.size();i++)
		if('a'<=a[i] && a[i]<='z')
			a[i]+='A'-'a';
	return a;
}

#endif

