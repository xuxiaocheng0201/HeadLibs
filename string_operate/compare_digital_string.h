#ifndef HLS_COMPARE_DIGITAL_STRING_H
#define HLS_COMPARE_DIGITAL_STRING_H

#include "../common/string.h"
#include "string_is_digital.h"

#define COMPARE_DIGITAL_STRING_BIGGER 2
#define COMPARE_DIGITAL_STRING_EQUAL 0
#define COMPARE_DIGITAL_STRING_SMALLER 1
#define COMPARE_DIGITAL_STRING_ERROR -1

int compare_digital_string(string a1,string a2)
{
	if(!string_is_digital_fix(a1))
		return COMPARE_DIGITAL_STRING_ERROR;
	if(!string_is_digital_fix(a2))
		return COMPARE_DIGITAL_STRING_ERROR;
	bool negative_part_a1=((a1[0]=='-')?1:0),negative_part_a2=((a2[0]=='-')?1:0);
	if(negative_part_a1!=negative_part_a2)
	{
		if(negative_part_a1)
			return COMPARE_DIGITAL_STRING_BIGGER;
		return COMPARE_DIGITAL_STRING_SMALLER;
	}
	string integer_part_a1="",integer_part_a2="";
	string decimal_part_a1="",decimal_part_a2="";
	unsigned int point_a1=a1.size(),point_a2=a2.size();
	for(unsigned int i=negative_part_a1;i<a1.size();i++)
		if(a1[i]=='.')
		{
			point_a1=i;
			break;
		}
	for(unsigned int i=negative_part_a2;i<a2.size();i++)
		if(a2[i]=='.')
		{
			point_a2=i;
			break;
		}
	for(unsigned int i=0;i<point_a1;i++)
		integer_part_a1+=a1[i];
	for(unsigned int i=0;i<point_a2;i++)
		integer_part_a2+=a2[i];
	for(unsigned int i=point_a1+1;i<a1.size();i++)
		decimal_part_a1+=a1[i];
	for(unsigned int i=point_a2+1;i<a2.size();i++)
		decimal_part_a2+=a2[i];
	if(integer_part_a1==integer_part_a2 && decimal_part_a1==decimal_part_a2)
		return COMPARE_DIGITAL_STRING_EQUAL;
	if(integer_part_a1.size()>integer_part_a2.size())
	{
		if(negative_part_a1)
			return COMPARE_DIGITAL_STRING_SMALLER;
		return COMPARE_DIGITAL_STRING_BIGGER;
	}
	if(integer_part_a1.size()<integer_part_a2.size())
	{
		if(negative_part_a1)
			return COMPARE_DIGITAL_STRING_BIGGER;
		return COMPARE_DIGITAL_STRING_SMALLER;
	}
	for(unsigned int i=0;i<integer_part_a1.size();i++)
	{
		if(integer_part_a1[i]>integer_part_a2[i])
		{
			if(negative_part_a1)
				return COMPARE_DIGITAL_STRING_SMALLER;
			return COMPARE_DIGITAL_STRING_BIGGER;
		}
		if(integer_part_a1[i]<integer_part_a2[i])
		{
			if(negative_part_a1)
				return COMPARE_DIGITAL_STRING_BIGGER;
			return COMPARE_DIGITAL_STRING_SMALLER;
		}
	}
	for(unsigned int i=0;i<((decimal_part_a1.size()>decimal_part_a2.size())?decimal_part_a2.size():decimal_part_a1.size());i++)
	{
		if(decimal_part_a1[i]>decimal_part_a2[i])
		{
			if(negative_part_a1)
				return COMPARE_DIGITAL_STRING_SMALLER;
			return COMPARE_DIGITAL_STRING_BIGGER;
		}
		if(decimal_part_a1[i]<decimal_part_a2[i])
		{
			if(negative_part_a1)
				return COMPARE_DIGITAL_STRING_BIGGER;
			return COMPARE_DIGITAL_STRING_SMALLER;
		}
	}
	if(decimal_part_a1.size()>decimal_part_a2.size())
	{
		if(negative_part_a1)
			return COMPARE_DIGITAL_STRING_SMALLER;
		return COMPARE_DIGITAL_STRING_BIGGER;
	}
	if(decimal_part_a1.size()<decimal_part_a2.size())
	{
		if(negative_part_a1)
			return COMPARE_DIGITAL_STRING_BIGGER;
		return COMPARE_DIGITAL_STRING_SMALLER;
	}
	return COMPARE_DIGITAL_STRING_EQUAL;
}

#endif

