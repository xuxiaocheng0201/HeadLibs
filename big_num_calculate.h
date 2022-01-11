#ifndef HLS_BIG_NUM_CALCULATE_H
#define HLS_BIG_NUM_CALCULATE_H

#include "big_num_define.h"

big_num big_num::add(big_num num)
{
	size_error_fix();
	num.size_error_fix();
	//if(negative==num.negative)
	unsigned int decimal_min_len=(decimal.size()<num.decimal.size())?decimal.size():num.decimal.size();
	for(unsigned int i=decimal.size();i<num.decimal.size();i++)
	{
		decimal.push_back(num.decimal[i]);
		if(decimal[i]>=power_10_BIG_NUM_VECROR_TYPE_WIDE)
		{
			if(i==0)
				integer[0]+=decimal[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
			else
				decimal[i-1]+=decimal[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
			decimal[i]%=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		}
	}
	for(unsigned int i=decimal_min_len-1;i>0;i--)
	{
		decimal[i]+=num.decimal[i];
		if(decimal[i]>=power_10_BIG_NUM_VECROR_TYPE_WIDE)
		{
			if(i==0)
				integer[0]+=decimal[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
			else
				decimal[i-1]+=decimal[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
			decimal[i]%=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		}
	}
	decimal[0]+=num.decimal[0];
	if(decimal[0]>=power_10_BIG_NUM_VECROR_TYPE_WIDE)
	{
		integer[0]+=decimal[0]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
		decimal[0]%=power_10_BIG_NUM_VECROR_TYPE_WIDE;
	}
	unsigned int integer_min_len=(integer.size()<num.integer.size())?integer.size():num.integer.size();
	for(unsigned int i=0;i<integer_min_len;i++)
	{
		integer[i]+=num.integer[i];
		if(integer[i]>=power_10_BIG_NUM_VECROR_TYPE_WIDE)
		{
			if(i==integer.size()-1)
				integer.push_back(0);
			integer[i+1]+=integer[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
			integer[i]%=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		}
	}
	if(integer_min_len!=num.integer.size())
		for(unsigned int i=integer_min_len;i<num.integer.size();i++)
			if(i>=integer.size())
				integer.push_back(num.integer[i]);
			else
			{
				if(i==integer.size()-1)
					integer.push_back(0);
				if(integer[i]>=power_10_BIG_NUM_VECROR_TYPE_WIDE)
				{
					integer[i+1]+=integer[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
					integer[i]%=power_10_BIG_NUM_VECROR_TYPE_WIDE;
				}
				integer[i]+=num.integer[i];
				if(integer[i]>=power_10_BIG_NUM_VECROR_TYPE_WIDE)
				{
					integer[i+1]+=integer[i]/power_10_BIG_NUM_VECROR_TYPE_WIDE;
					integer[i]%=power_10_BIG_NUM_VECROR_TYPE_WIDE;
				}
			}
	return *this;
}

#endif

