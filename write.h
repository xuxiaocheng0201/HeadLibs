#ifndef HLS_WRITE_H
#define HLS_WRITE_H

#include <stdio.h>

inline short write(int x)
{
	if(x==0)
	{
		putchar('0');
		return 1;
	}
	int num=x;
	if(num<0)
	{
		putchar('-');
		num=-num;
	}
	short cnt=0;
	char F[20+5];
	while(num)
	{
		F[cnt++]=num%10+'0';
		num/=10;
	}
	short len=cnt;
	while(cnt)
		putchar(F[--cnt]);
	return len;
}

#endif

