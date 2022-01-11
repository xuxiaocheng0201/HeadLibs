#ifndef HLS_BIG_NUM_BASE_GET_H
#define HLS_BIG_NUM_BASE_GET_H

#include "big_num_define.h"
#include "turn_string.h"

string big_num::get_string()
{
	if(!all_string_need_updata)
		return all_string;
	get_string_integer();
	get_string_decimal();
	if(negative)
		all_string="-";
	else
		all_string="";
	all_string+=integer_string;
	if(decimal_string!="0")
		all_string+="."+decimal_string;
	all_string_need_updata=0;
	return all_string;
}

string big_num::get_string_no_fix_zero()
{
	if(!all_string_no_fix_zero_need_updata)
		return all_string_no_fix_zero;
	get_string_integer_no_fix_zero();
	get_string_decimal_no_fix_zero();
	if(negative)
		all_string_no_fix_zero="-";
	else
		all_string_no_fix_zero="";
	all_string_no_fix_zero+=integer_string_no_fix_zero+"."+decimal_string_no_fix_zero;
	return all_string_no_fix_zero;
}

string big_num::get_string_negative()
{
	if(negative)
		return "-";
	return "+";
}

string big_num::get_string_integer()
{
	if(!integer_string_need_updata)
		return integer_string;
	string integer_string_temp=get_string_integer_no_fix_zero();
	unsigned int point=integer_string_temp.size()-1;
	for(unsigned int i=0;i<integer_string_temp.size();i++)
		if(integer_string_temp[i]!='0')
		{
			point=i;
			break;
		}
	integer_string="";
	for(unsigned int i=point;i<integer_string_temp.size();i++)
		integer_string+=integer_string_temp[i];
	integer_string_need_updata=0;
	return integer_string;
}

string big_num::get_string_integer_no_fix_zero()
{
	if(!integer_string_no_fix_zero_need_updata)
		return integer_string_no_fix_zero;
	if(integer.size()==0)
	{
		integer.push_back(0);
		integer_string_no_fix_zero="0";
		integer_string_no_fix_zero_need_updata=0;
		return integer_string_no_fix_zero;
	}
	if(integer.size()==1)
	{
		integer_string_no_fix_zero=turn_string(integer[integer.size()-1]);
		integer_string_no_fix_zero_need_updata=0;
		return integer_string_no_fix_zero;
	}
	integer_string_no_fix_zero=turn_string(integer[integer.size()-1]);
	for(unsigned int i=integer.size()-2;i>0;i--)
	{
		string integer_string_no_fix_zero_part=turn_string(integer[i]);
		for(unsigned int i=integer_string_no_fix_zero_part.size();i<BIG_NUM_VECROR_TYPE_WIDE;i++)
			integer_string_no_fix_zero+="0";
		integer_string_no_fix_zero+=integer_string_no_fix_zero_part;
	}
	string integer_string_no_fix_zero_part=turn_string(integer[0]);
	for(unsigned int i=integer_string_no_fix_zero_part.size();i<BIG_NUM_VECROR_TYPE_WIDE;i++)
		integer_string_no_fix_zero+="0";
	integer_string_no_fix_zero+=integer_string_no_fix_zero_part;
	integer_string_no_fix_zero_need_updata=0;
	return integer_string_no_fix_zero;
}

string big_num::get_string_decimal()
{
	if(!decimal_string_need_updata)
		return decimal_string;
	string decimal_string_temp=get_string_decimal_no_fix_zero();
	unsigned int point=0;
	for(unsigned int i=decimal_string_temp.size()-1;i>0;i--)
		if(decimal_string_temp[i]!='0')
		{
			point=i;
			break;
		}
	decimal_string="";
	for(unsigned int i=0;i<=point;i++)
		decimal_string+=decimal_string_temp[i];
	return decimal_string;
}

string big_num::get_string_decimal_no_fix_zero()
{
	if(!decimal_string_no_fix_zero_need_updata)
		return decimal_string_no_fix_zero;
	if(decimal.size()==0)
	{
		decimal.push_back(0);
		decimal_string_no_fix_zero="0";
		decimal_string_no_fix_zero_need_updata=0;
		return decimal_string_no_fix_zero;
	}
	if(decimal.size()==1)
	{
		decimal_string_no_fix_zero=turn_string(decimal[0]);
		decimal_string_no_fix_zero_need_updata=0;
		return decimal_string_no_fix_zero;
	}
	decimal_string_no_fix_zero="";
	for(unsigned int i=0;i<decimal.size();i++)
	{
		string decimal_string_no_fix_zero_part=turn_string(decimal[i]);
		for(unsigned int i=decimal_string_no_fix_zero_part.size();i<BIG_NUM_VECROR_TYPE_WIDE;i++)
			decimal_string_no_fix_zero+="0";
		decimal_string_no_fix_zero+=decimal_string_no_fix_zero_part;
	}
	decimal_string_no_fix_zero_need_updata=0;
	return decimal_string_no_fix_zero;
}
 
pair<bool,pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > > big_num::get_class()
{
	return make_pair(negative,make_pair(integer,decimal));
}

bool big_num::get_bool_negative()
{
	return negative;
}

pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > big_num::get_pair()
{
	return make_pair(integer,decimal);
}

vector<BIG_NUM_VECROR_TYPE> big_num::get_vector_integer()
{
	return integer;
}

vector<BIG_NUM_VECROR_TYPE> big_num::get_vector_decimal()
{
	return decimal;
}

#endif

