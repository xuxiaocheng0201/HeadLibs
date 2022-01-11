#ifndef HLS_STRING_IS_DIGITAL_H
#define HLS_STRING_IS_DIGITAL_H

#include "../common/string.h"

bool string_is_digital(string num)
{
	if(num=="")
		return 0;
	bool symbol_point=0;
	if(num[0]=='+' || num[0]=='-')
		symbol_point=1;
	bool point=0;
	bool negative_part=1;
	for(unsigned int i=symbol_point;i<num.size();i++)
	{
		if(negative_part && (num[i]=='+'||num[i]=='-'))
			continue;
		if(num[i]=='.')
		{
			if(point)
				return 0;
			point=1;
			continue;
		}
		if(num[i]<'0' || '9'<num[i])
			return 0;
	}
	return 1;
}

//1..1 to 1.1
//+1024.515 to 1024.515
//0010 to 10
//0.10 to 0.1
//--10 to 10
//+-5 to -5
//123.456.789 to 123456.789
//++--+-+- to 0
//--- to 0
//. to 0
//.1 to 0.1
//1. to 1
//1+1 return 0
//-10.2+1 return 0
bool string_is_digital_fix(string& num)
{
	if(num=="")
	{
		num="0";
		return 1;
	}
	bool negative=0;
	bool negative_part=1;
	if(num[0]=='-')
		negative=1;
	bool point=0;
	string new_num_integer="";
	string new_num_decimal="";
	bool front_zero_part=1;
	for(unsigned int i=negative;i<num.size();i++)
	{
		if(negative_part && num[i]=='+')
		{
			//negative=negative;
			continue;
		}
		if(negative_part && num[i]=='-')
		{
			negative=!negative;
			continue;
		}
		negative_part=0;
		if(front_zero_part && num[i]=='0')
			continue;
		front_zero_part=0;
		if(num[i]=='.')
		{
			if(point)
			{
				new_num_integer+=new_num_decimal;
				new_num_decimal="";
			}
			point=1;
			continue;
		}
		if(num[i]<'0' || '9'<num[i])
			return 0;
		if(!point)
			new_num_integer+=num[i];
		else
			new_num_decimal+=num[i];
	}
	if(negative)
		num="-";
	else
		num="";
	if(new_num_integer=="")
		num="0";
	else
		num+=new_num_integer;
	if(new_num_decimal.size())
	{
		string decimal="";
		bool back_zero_part=1;
		for(unsigned int i=new_num_decimal.size()-1;i>0;i--)
		{
			if(back_zero_part && new_num_decimal[i]=='0')
				continue;
			back_zero_part=0;
			decimal=new_num_decimal[i]+decimal;
		}
		decimal=new_num_decimal[0]+decimal;
		if(decimal!="" && decimal!="0")
			num+="."+decimal;
	}
	return 1;
}

bool string_is_pure_digital(string num)
{
	for(unsigned int i=0;i<num.size();i++)
		if(num[i]<'0' || '9'<num[i])
			return 0;
	return 1;
}

//Delete all non-digital char.
bool string_is_pure_digital_fix(string& num)
{
	string new_num="";
	for(unsigned int i=0;i<num.size();i++)
		if('0'<num[i] || num[i]<'9')
			new_num+=num[i];
	num=new_num;
	return 1;
}

#endif

