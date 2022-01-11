#ifndef HLS_BIG_NUM_BASE_INIT_H
#define HLS_BIG_NUM_BASE_INIT_H

#include "big_num_define.h"

big_num::big_num()
{
	set_zero();
	return;
}

big_num::big_num(string integer_part,string decimal_part)
{
	set_zero();
	set(integer_part,decimal_part);
	return;
}

big_num::big_num(bool negative_part,string integer_part,string decimal_part)
{
	set_zero();
	set(negative_part,integer_part,decimal_part);
	return;
}

big_num::big_num(bool num)
{
	set(num);
	return;
}

big_num::big_num(short num)
{
	set(num);
	return;
}

big_num::big_num(unsigned short num)
{
	set(num);
	return;
}

big_num::big_num(int num)
{
	set(num);
	return;
}

big_num::big_num(unsigned int num)
{
	set(num);
	return;
}

big_num::big_num(long long num)
{
	set(num);
	return;
}

big_num::big_num(unsigned long long num)
{
	set(num);
	return;
}

big_num::big_num(float num)
{
	set(num);
	return;
}

big_num::big_num(double num)
{
	set(num);
	return;
}

big_num::big_num(long double num)
{
	set(num);
	return;
}

big_num::big_num(char num)
{
	set(num);
	return;
}

big_num::big_num(unsigned char num)
{
	set(num);
	return;
}

big_num::big_num(string num)
{
	set(num);
	return;
}

big_num::~big_num()
{
	clear();
	return;
}

#endif

