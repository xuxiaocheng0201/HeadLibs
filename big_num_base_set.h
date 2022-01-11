#ifndef HLS_BIG_NUM_BASE_SET_H
#define HLS_BIG_NUM_BASE_SET_H

#include "big_num_define.h"
#include "turn_string.h"
#include "string_is_digital.h"
#include "max_min_null.h"

big_num big_num::clear()
{
	clear_negative();
	clear_integer();
	clear_decimal();
	all_string.clear();
	all_string_need_updata=0;
	all_string_no_fix_zero.clear();
	all_string_no_fix_zero_need_updata=0;
	last_error.clear();
	last_operation="clear()";
	return *this;
}

big_num big_num::clear_negative()
{
	negative=0;
	last_error.clear();
	last_operation="clear_negative()";
	return *this;
}

big_num big_num::clear_integer()
{
	integer.clear();
	integer_string.clear();
	integer_string_need_updata=0;
	integer_string_no_fix_zero.clear();
	integer_string_no_fix_zero_need_updata=0;
	last_error.clear();
	last_operation="clear_integer()";
	return *this;
}

big_num big_num::clear_decimal()
{
	decimal.clear();
	decimal_string.clear();
	decimal_string_need_updata=0;
	decimal_string_no_fix_zero.clear();
	decimal_string_no_fix_zero_need_updata=0;
	last_error.clear();
	last_operation="clear_decimal()";
	return *this;
}

big_num big_num::set_zero()
{
	clear();
	integer.push_back(0);
	decimal.push_back(0);
	integer_string="0";
	integer_string_no_fix_zero="0";
	decimal_string="0";
	decimal_string_no_fix_zero="0";
	all_string="0";
	all_string_no_fix_zero="0";
	last_error.clear();
	last_operation="set_zero()";
	return *this;
}

big_num big_num::set_negative(bool negative_part)
{
	negative=negative_part;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set_negative(bool negative_part)";
	return *this;
}

big_num big_num::set_integer(vector<BIG_NUM_VECROR_TYPE> integer_part)
{
	integer=integer_part;
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set_integer(vector<BIG_NUM_VECROR_TYPE> integer_part)";
	return *this;
}

big_num big_num::set_integer(string integer_part)
{
	string_is_pure_digital_fix(integer_part);
	clear_integer();
	unsigned int extra_point=integer_part.size()%BIG_NUM_VECROR_TYPE_WIDE;
	for(unsigned int i=integer_part.size()-1;i>=BIG_NUM_VECROR_TYPE_WIDE-1+extra_point;i-=BIG_NUM_VECROR_TYPE_WIDE)
	{
		string temp="";
		for(unsigned int j=i+1-BIG_NUM_VECROR_TYPE_WIDE;j<=i;j++)
			temp+=integer_part[j];
		integer.push_back(turn_BIG_NUM_VECROR_TYPE(temp));
		if(i<BIG_NUM_VECROR_TYPE_WIDE)
			break;
	}
	string extra="";
	for(unsigned int i=0;i<extra_point;i++)
		extra+=integer_part[i];
	if(extra!="")
		integer.push_back(turn_BIG_NUM_VECROR_TYPE(extra));
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set_integer(string integer_part)";
	return *this;
}

big_num big_num::set_decimal(vector<BIG_NUM_VECROR_TYPE> decimal_part)
{
	decimal=decimal_part;
	decimal_string_need_updata=1;
	decimal_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set_decimal(vector<BIG_NUM_VECROR_TYPE> decimal_part)";
	return *this;
}

big_num big_num::set_decimal(string decimal_part)
{
	string_is_pure_digital_fix(decimal_part);
	clear_decimal();
	unsigned int extra_point=decimal_part.size()-decimal_part.size()%BIG_NUM_VECROR_TYPE_WIDE;
	for(unsigned int i=0;i<extra_point;i+=BIG_NUM_VECROR_TYPE_WIDE)
	{
		string temp="";
		for(unsigned int j=i;j<i+BIG_NUM_VECROR_TYPE_WIDE;j++)
			temp+=decimal_part[j];
		decimal.push_back(turn_BIG_NUM_VECROR_TYPE(temp));
	}
	string extra="";
	for(unsigned int i=extra_point;i<decimal_part.size();i++)
		extra+=decimal_part[i];
	if(extra!="")
	{
		for(unsigned int i=extra.size();i<BIG_NUM_VECROR_TYPE_WIDE;i++)
			extra+="0";
		decimal.push_back(turn_BIG_NUM_VECROR_TYPE(extra));
	} 
	decimal_string_need_updata=1;
	decimal_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set_decimal(string decimal_part)";
	return *this;
}

big_num big_num::set(vector<BIG_NUM_VECROR_TYPE> integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)
{
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(vector<BIG_NUM_VECROR_TYPE> integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)";
	return *this;
}

big_num big_num::set(string integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)
{
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(string integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)";
	return *this;
}

big_num big_num::set(vector<BIG_NUM_VECROR_TYPE> integer_part,string decimal_part)
{
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(vector<BIG_NUM_VECROR_TYPE> integer_part,string decimal_part)";
	return *this;
}

big_num big_num::set(string integer_part,string decimal_part)
{
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(string integer_part,string decimal_part)";
	return *this;
}

big_num big_num::set(pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > _pair)
{
	set_integer(_pair.first);
	set_decimal(_pair.second);
	last_error.clear();
	last_operation="set(pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > _pair)";
	return *this;
}

big_num big_num::set(bool negative_part,vector<BIG_NUM_VECROR_TYPE> integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)
{
	set_negative(negative_part);
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(bool negative_part,vector<BIG_NUM_VECROR_TYPE> integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)";
	return *this;
}

big_num big_num::set(bool negative_part,string integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)
{
	set_negative(negative_part);
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(bool negative_part,string integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part)";
	return *this;
}

big_num big_num::set(bool negative_part,vector<BIG_NUM_VECROR_TYPE> integer_part,string decimal_part)
{
	set_negative(negative_part);
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(bool negative_part,vector<BIG_NUM_VECROR_TYPE> integer_part,string decimal_part)";
	return *this;
}

big_num big_num::set(bool negative_part,string integer_part,string decimal_part)
{
	set_negative(negative_part);
	set_integer(integer_part);
	set_decimal(decimal_part);
	last_error.clear();
	last_operation="set(bool negative_part,string integer_part,string decimal_part)";
	return *this;
}

big_num big_num::set(pair<bool,pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > > _class)
{
	set_negative(_class.first);
	set_integer(_class.second.first);
	set_decimal(_class.second.second);
	last_error.clear();
	last_operation="set(pair<bool,pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > > _class)";
	return *this;
}

big_num big_num::set(bool num)
{
	set_zero();
	if(num)
	{
		integer[0]=1;
		integer_string="1";
		integer_string_no_fix_zero="1";
		all_string="1";
		all_string_no_fix_zero="1";
	}
	last_error.clear();
	last_operation="set(bool num)";
	return;
}

big_num big_num::set(short num)
{
	set_zero();
	if(num==0)
		return;
	if(num<0)
	{
		set(1);
		if(num==_MIN_SHORT)
			return set("-32768"/*turn_string(_MIN_SHORT)*/);
		num=-num;
	}
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(short num)";
	return *this;
}

big_num big_num::set(unsigned short num)
{
	set_zero();
	if(num==0)
		return;
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(unsigned short num)";
	return *this;
}

big_num big_num::set(int num)
{
	set_zero();
	if(num==0)
		return;
	if(num<0)
	{
		set(1);
		if(num==_MIN_INT)
			return set("-2147483648"/*turn_string(_MIN_INT)*/);
		num=-num;
	}
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(short num)";
	return *this;
}

big_num big_num::set(unsigned int num)
{
	set_zero();
	if(num==0)
		return;
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(unsigned int num)";
	return *this;
}

big_num big_num::set(long long num)
{
	set_zero();
	if(num==0)
		return;
	if(num<0)
	{
		set(1);
		if(num==_MIN_LONG_LONG)
			return set("-9223372036854775808"/*turn_string(_MIN_LONG_LONG)*/);
		num=-num;
	}
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(long long num)";
	return *this;
}

big_num big_num::set(unsigned long long num)
{
	set_zero();
	if(num==0)
		return;
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(unsigned long long num)";
	return *this;
}

big_num big_num::set(float num)
{
	set(turn_string(num));
	return *this;
}

big_num big_num::set(double num)
{
	set(turn_string(num));
	return *this;
}

big_num big_num::set(long double num)
{
	set(turn_string(num));
	return *this;
}

big_num big_num::set(char num)
{
	set_zero();
	if(num==0)
		return;
	if(num<0)
	{
		set(1);
		if(num==_MIN_CHAR)
			return set("-128"/*turn_string(_MIN_CHAR)*/);
		num=-num;
	}
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(char num)";
	return *this;
}

big_num big_num::set(unsigned char num)
{
	set_zero();
	if(num==0)
		return;
	clear_integer();
	while(num)
	{
		BIG_NUM_VECROR_TYPE temp=num%power_10_BIG_NUM_VECROR_TYPE_WIDE;
		num/=power_10_BIG_NUM_VECROR_TYPE_WIDE;
		integer.push_back(temp);
	}
	integer_string_need_updata=1;
	integer_string_no_fix_zero_need_updata=1;
	all_string_need_updata=1;
	all_string_no_fix_zero_need_updata=1;
	last_error.clear();
	last_operation="set(unsigned char num)";
	return *this;
}

big_num big_num::set(string num)
{
	if(!string_is_digital_fix(num))
	{
		last_error.set()
		return *this;
	}
	set_zero();
	if(num[0]=='-')
		negative=1;
	unsigned int point_point=num.size();
	for(unsigned int i=negative;i<num.size();i++)
		if(num[i]=='.')
		{
			point_point=i;
			break;
		}
	string integer_part="";
	for(unsigned int i=0;i<point_point;i++)
		integer_part+=num[i];
	string decimal_part="";
	for(unsigned int i=point_point+1;i<num.size();i++)
		decimal_part+=num[i];
	set(integer_part,decimal_part);
	last_error.clear();
	last_operation="set(string num)";
	return *this;
}

#endif

