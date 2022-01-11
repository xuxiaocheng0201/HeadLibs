#ifndef HLS_BIG_NUM_BASE_OPERATOR_H
#define HLS_BIG_NUM_BASE_OPERATOR_H

#include "big_num_define.h"
#include "compare_digital_string.h"
#include "turn_string.h"

big_num& big_num::operator=(big_num num)
{
	this->negative=num.negative;
	this->integer=num.integer;
	this->integer_string=num.integer_string;
	this->integer_string_need_updata=num.integer_string_need_updata;
	this->integer_string_no_fix_zero=num.integer_string_no_fix_zero;
	this->integer_string_no_fix_zero_need_updata=num.integer_string_no_fix_zero_need_updata;
	this->decimal=num.decimal;
	this->decimal_string=num.decimal_string;
	this->decimal_string_need_updata=num.decimal_string_need_updata;
	this->decimal_string_no_fix_zero=num.decimal_string_no_fix_zero;
	this->decimal_string_no_fix_zero_need_updata=num.decimal_string_no_fix_zero_need_updata;
	this->all_string=num.all_string;
	this->all_string_need_updata=num.all_string_need_updata;
	this->all_string_no_fix_zero=num.all_string_no_fix_zero;
	this->all_string_no_fix_zero_need_updata=num.all_string_no_fix_zero_need_updata;
	return *this;
}

big_num& big_num::operator=(bool num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(short num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(unsigned short num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(int num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(unsigned int num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(long long num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(unsigned long long num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(float num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(double num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(long double num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(char num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(unsigned char num)
{
	set(num);
	return *this;
}

big_num& big_num::operator=(string num)
{
	set(num);
	return *this;
}

bool big_num::operator==(big_num num)
{
#ifdef BIG_NUM_STRICTLY_EQUAL
# ifndef BIG_NUM_QUICK_EQUAL
	if(this->integer_string!=num.integer_string)
		return 0;
	if(this->integer_string_need_updata!=num.integer_string_need_updata)
		return 0;
	if(this->integer_string_no_fix_zero!=num.integer_string_no_fix_zero)
		return 0;
	if(this->integer_string_no_fix_zero_need_updata!=num.integer_string_no_fix_zero_need_updata)
		return 0;
	if(this->decimal_string!=num.decimal_string)
		return 0;
	if(this->decimal_string_need_updata!=num.decimal_string_need_updata)
		return 0;
	if(this->decimal_string_no_fix_zero!=num.decimal_string_no_fix_zero)
		return 0;
	if(this->decimal_string_no_fix_zero_need_updata!=num.decimal_string_no_fix_zero_need_updata)
		return 0;
	if(this->all_string_need_updata!=num.all_string_need_updata)
		return 0;
	if(this->all_string_no_fix_zero!=num.all_string_no_fix_zero)
		return 0;
	if(this->all_string_no_fix_zero_need_updata!=num.all_string_no_fix_zero_need_updata)
		return 0;
# endif
	if(this->negative!=num.negative)
		return 0;
	if(this->integer!=num.integer)
		return 0;
	if(this->decimal!=num.decimal)
		return 0;
	if(this->all_string!=num.all_string)
		return 0;
	return 1;
#else
# ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
	num.integer_string_need_updata=1;
	num.integer_string_no_fix_zero_need_updata=1;
	num.decimal_string_need_updata=1;
	num.decimal_string_no_fix_zero_need_updata=1;
	num.all_string_need_updata=1;
	num.all_string_no_fix_zero_need_updata=1;
# endif
	return (this->get_string()==num.get_string());
#endif
}

bool big_num::operator==(bool num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(short num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(unsigned short num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(int num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(unsigned int num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(long long num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(unsigned long long num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(float num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(double num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(long double num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator==(string num)
{
	big_num temp;
	temp=num;
	return *this==temp;
}

bool big_num::operator!=(big_num num)
{
	return !(*this==num);
}

bool big_num::operator!=(bool num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(short num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(unsigned short num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(int num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(unsigned int num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(long long num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(unsigned long long num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(float num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(double num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(long double num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator!=(string num)
{
	big_num temp;
	temp=num;
	return *this!=temp;
}

bool big_num::operator>(big_num num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
	num.integer_string_need_updata=1;
	num.integer_string_no_fix_zero_need_updata=1;
	num.decimal_string_need_updata=1;
	num.decimal_string_no_fix_zero_need_updata=1;
	num.all_string_need_updata=1;
	num.all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),num.get_string())==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(bool num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),(num?"1":"0")/*turn_string(num)*/)==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(unsigned short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(unsigned int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(unsigned long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(float num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(long double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(unsigned char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>(string num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),num)==COMPARE_DIGITAL_STRING_BIGGER)
		return 1;
	return 0;
}

bool big_num::operator>=(big_num num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
	num.integer_string_need_updata=1;
	num.integer_string_no_fix_zero_need_updata=1;
	num.decimal_string_need_updata=1;
	num.decimal_string_no_fix_zero_need_updata=1;
	num.all_string_need_updata=1;
	num.all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),num.get_string());
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(bool num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),(num?"1":"0")/*turn_string(num)*/);
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(unsigned short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(unsigned int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(unsigned long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(float num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(long double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(unsigned char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator>=(string num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),num);
	if(temp==COMPARE_DIGITAL_STRING_BIGGER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<(big_num num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
	num.integer_string_need_updata=1;
	num.integer_string_no_fix_zero_need_updata=1;
	num.decimal_string_need_updata=1;
	num.decimal_string_no_fix_zero_need_updata=1;
	num.all_string_need_updata=1;
	num.all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),num.get_string())==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(bool num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),(num?"1":"0")/*turn_string(num)*/)==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(unsigned short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(unsigned int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(unsigned long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(float num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(long double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(unsigned char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),turn_string(num))==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<(string num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	if(compare_digital_string(this->get_string(),num)==COMPARE_DIGITAL_STRING_SMALLER)
		return 1;
	return 0;
}

bool big_num::operator<=(big_num num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
	num.integer_string_need_updata=1;
	num.integer_string_no_fix_zero_need_updata=1;
	num.decimal_string_need_updata=1;
	num.decimal_string_no_fix_zero_need_updata=1;
	num.all_string_need_updata=1;
	num.all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),num.get_string());
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(bool num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),(num?"1":"0")/*turn_string(num)*/);
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(unsigned short num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(unsigned int num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(unsigned long long num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(float num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(long double num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(unsigned char num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),turn_string(num));
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator<=(string num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	this->integer_string_need_updata=1;
	this->integer_string_no_fix_zero_need_updata=1;
	this->decimal_string_need_updata=1;
	this->decimal_string_no_fix_zero_need_updata=1;
	this->all_string_need_updata=1;
	this->all_string_no_fix_zero_need_updata=1;
#endif
	int temp=compare_digital_string(this->get_string(),num);
	if(temp==COMPARE_DIGITAL_STRING_SMALLER || temp==COMPARE_DIGITAL_STRING_EQUAL)
		return 1;
	return 0;
}

bool big_num::operator!()
{
	if(*this==0)
		return 1;
	return 0;
}

istream& operator>>(istream& is,big_num& num)
{
	string temp;
	temp.clear();
	is>>temp;
	num.set(temp);
	return is;
}

ostream& operator<<(ostream& os,big_num num)
{
#ifndef BIG_NUM_QUICK_EQUAL
	num.integer_string_need_updata=1;
	num.integer_string_no_fix_zero_need_updata=1;
	num.decimal_string_need_updata=1;
	num.decimal_string_no_fix_zero_need_updata=1;
	num.all_string_need_updata=1;
	num.all_string_no_fix_zero_need_updata=1;
#endif
	os<<num.get_string();
	return os;
}

#endif

