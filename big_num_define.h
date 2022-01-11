#ifndef HLS_BIG_NUM_DEFINE_H
#define HLS_BIG_NUM_DEFINE_H

#include "common/vector.h"
#include "common/string.h"
#include "common/pair.h"
#include "common/fstream.h"
#include "error_handle.h"

/*
	Choose only one of below!
	* BIG_NUM_VECROR_TYPE_CHOOSE_SHORT
	* BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT
	* BIG_NUM_VECROR_TYPE_CHOOSE_INT
	* BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT
	* BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG
	* BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG
	* BIG_NUM_VECROR_TYPE_CHOOSE_CHAR
	* BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR
*/
#if defined(BIG_NUM_VECROR_TYPE) || defined(turn_BIG_NUM_VECROR_TYPE)
#	error You can not define them before including big_num.h!
#endif
//#include "max_min_null.h"
#if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 4
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 4
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 4
#	endif
#	define BIG_NUM_VECROR_TYPE short
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_short(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 4
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 4
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 4
#	endif
#	define BIG_NUM_VECROR_TYPE unsigned short
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_unsigned_short(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 9
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 9
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 9
#	endif
#	define BIG_NUM_VECROR_TYPE int
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_int(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 9
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 9
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 9
#	endif
#	define BIG_NUM_VECROR_TYPE unsigned int
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_unsigned_int(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 18
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 18
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 18
#	endif
#	define BIG_NUM_VECROR_TYPE long long
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_long_long(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 18
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 18
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 18
#	endif
#	define BIG_NUM_VECROR_TYPE unsigned long long
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_unsigned_long_long(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 1
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 1
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 1
#	endif
#	define BIG_NUM_VECROR_TYPE char
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_char(a1)
#elif defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_CHAR)
#	 if defined(BIG_NUM_VECROR_TYPE_CHOOSE_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_INT) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_LONG_LONG) || \
		defined(BIG_NUM_VECROR_TYPE_CHOOSE_CHAR)
#		 error You choose too many types!
#	 endif
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 2
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 2
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 2
#	endif
#	define BIG_NUM_VECROR_TYPE unsigned char
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_unsigned_char(a1)
#else
#	define BIG_NUM_VECROR_TYPE_CHOOSE_UNSIGNED_SHORT
#	define BIG_NUM_VECROR_TYPE unsigned short
#	define turn_BIG_NUM_VECROR_TYPE(a1) turn_unsigned_short(a1)
#	ifdef BIG_NUM_VECROR_TYPE_WIDE
#		if BIG_NUM_VECROR_TYPE_WIDE > 4
#			warning The defination BIG_NUM_VECROR_TYPE_WIDE is too big!
#			undef BIG_NUM_VECROR_TYPE_WIDE
#			define BIG_NUM_VECROR_TYPE_WIDE 4
#		endif
#	else
#		define BIG_NUM_VECROR_TYPE_WIDE 4
#	endif
#endif
#if BIG_NUM_VECROR_TYPE_WIDE < 1
#	warning The defination BIG_NUM_VECROR_TYPE_WIDE is too small!
#	undef BIG_NUM_VECROR_TYPE_WIDE
#	define BIG_NUM_VECROR_TYPE_WIDE 1
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 1
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 10
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 2
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 100
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 3
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 1000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 4
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 10000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 5
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 100000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 6
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 1000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 7
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 10000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 8
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 100000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 9
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 1000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 10
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 10000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 11
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 100000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 12
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 1000000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 13
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 10000000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 14
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 100000000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 15
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 1000000000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 16
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 10000000000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 17
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 100000000000000000
#endif
#if BIG_NUM_VECROR_TYPE_WIDE == 18
#	define power_10_BIG_NUM_VECROR_TYPE_WIDE 1000000000000000000
#endif

class big_num
{
	public:
		//in error
		void size_error_fix();
		error_handle last_error;
		string last_operation;
		
		//in base_init
		big_num();
		big_num(string integer_part,string decimal_part);
		big_num(bool negative_part,string integer_part,string decimal_part);
		big_num(bool num);
		big_num(short num);
		big_num(unsigned short num);
		big_num(int num);
		big_num(unsigned int num);
		big_num(long long num);
		big_num(unsigned long long num);
		big_num(float num);
		big_num(double num);
		big_num(long double num);
		big_num(char num);
		big_num(unsigned char num);
		big_num(string num);
		~big_num();
		//in base_set
		big_num clear();
		big_num clear_negative();
		big_num clear_integer();
		big_num clear_decimal();
		big_num set_zero();
		big_num set_negative(bool negative_part);
		big_num set_integer(vector<BIG_NUM_VECROR_TYPE> integer_part);
		big_num set_integer(string integer_part);
		big_num set_decimal(vector<BIG_NUM_VECROR_TYPE> decimal_part);
		big_num set_decimal(string decimal_part);
		big_num set(vector<BIG_NUM_VECROR_TYPE> integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part);
		big_num set(string integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part);
		big_num set(vector<BIG_NUM_VECROR_TYPE> integer_part,string decimal_part);
		big_num set(string integer_part,string decimal_part);
		big_num set(pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > _pair);
		big_num set(bool negative_part,vector<BIG_NUM_VECROR_TYPE> integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part);
		big_num set(bool negative_part,string integer_part,vector<BIG_NUM_VECROR_TYPE> decimal_part);
		big_num set(bool negative_part,vector<BIG_NUM_VECROR_TYPE> integer_part,string decimal_part);
		big_num set(bool negative_part,string integer_part,string decimal_part);
		big_num set(pair<bool,pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > > _class);
		big_num set(bool num);
		big_num set(short num);
		big_num set(unsigned short num);
		big_num set(int num);
		big_num set(unsigned int num);
		big_num set(long long num);
		big_num set(unsigned long long num);
		big_num set(float num);
		big_num set(double num);
		big_num set(long double num);
		big_num set(char num);
		big_num set(unsigned char num);
		big_num set(string num);
		//in base_get
		string get_string();
		string get_string_no_fix_zero();
		string get_string_negative();
		string get_string_integer();
		string get_string_integer_no_fix_zero();
		string get_string_decimal();
		string get_string_decimal_no_fix_zero();
		pair<bool,pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > > get_class();
		bool get_bool_negative();
		pair<vector<BIG_NUM_VECROR_TYPE>,vector<BIG_NUM_VECROR_TYPE> > get_pair();
		vector<BIG_NUM_VECROR_TYPE> get_vector_integer();
		vector<BIG_NUM_VECROR_TYPE> get_vector_decimal();
		//in base_operator
		big_num& operator=(big_num num);
		big_num& operator=(bool num);
		big_num& operator=(short num);
		big_num& operator=(unsigned short num);
		big_num& operator=(int num);
		big_num& operator=(unsigned int num);
		big_num& operator=(long long num);
		big_num& operator=(unsigned long long num);
		big_num& operator=(float num);
		big_num& operator=(double num);
		big_num& operator=(long double num);
		big_num& operator=(char num);
		big_num& operator=(unsigned char num);
		big_num& operator=(string num);
		bool operator==(big_num num);
		bool operator==(bool num);
		bool operator==(short num);
		bool operator==(unsigned short num);
		bool operator==(int num);
		bool operator==(unsigned int num);
		bool operator==(long long num);
		bool operator==(unsigned long long num);
		bool operator==(float num);
		bool operator==(double num);
		bool operator==(long double num);
		bool operator==(char num);
		bool operator==(unsigned char num);
		bool operator==(string num);
		bool operator!=(big_num num);
		bool operator!=(bool num);
		bool operator!=(short num);
		bool operator!=(unsigned short num);
		bool operator!=(int num);
		bool operator!=(unsigned int num);
		bool operator!=(long long num);
		bool operator!=(unsigned long long num);
		bool operator!=(float num);
		bool operator!=(double num);
		bool operator!=(long double num);
		bool operator!=(char num);
		bool operator!=(unsigned char num);
		bool operator!=(string num);
		bool operator>(big_num num);
		bool operator>(bool num);
		bool operator>(short num);
		bool operator>(unsigned short num);
		bool operator>(int num);
		bool operator>(unsigned int num);
		bool operator>(long long num);
		bool operator>(unsigned long long num);
		bool operator>(float num);
		bool operator>(double num);
		bool operator>(long double num);
		bool operator>(char num);
		bool operator>(unsigned char num);
		bool operator>(string num);
		bool operator>=(big_num num);
		bool operator>=(bool num);
		bool operator>=(short num);
		bool operator>=(unsigned short num);
		bool operator>=(int num);
		bool operator>=(unsigned int num);
		bool operator>=(long long num);
		bool operator>=(unsigned long long num);
		bool operator>=(float num);
		bool operator>=(double num);
		bool operator>=(long double num);
		bool operator>=(char num);
		bool operator>=(unsigned char num);
		bool operator>=(string num);
		bool operator<(big_num num);
		bool operator<(bool num);
		bool operator<(short num);
		bool operator<(unsigned short num);
		bool operator<(int num);
		bool operator<(unsigned int num);
		bool operator<(long long num);
		bool operator<(unsigned long long num);
		bool operator<(float num);
		bool operator<(double num);
		bool operator<(long double num);
		bool operator<(char num);
		bool operator<(unsigned char num);
		bool operator<(string num);
		bool operator<=(big_num num);
		bool operator<=(bool num);
		bool operator<=(short num);
		bool operator<=(unsigned short num);
		bool operator<=(int num);
		bool operator<=(unsigned int num);
		bool operator<=(long long num);
		bool operator<=(unsigned long long num);
		bool operator<=(float num);
		bool operator<=(double num);
		bool operator<=(long double num);
		bool operator<=(char num);
		bool operator<=(unsigned char num);
		bool operator<=(string num);
		bool operator!();
		friend istream& operator>>(istream& is,big_num& num);
		friend ostream& operator<<(ostream& os,big_num num);
		//in calculate
		big_num add(big_num num);
		//in operate
		
#ifdef BIG_NUM_OPEN_MODE
	public:
#else
	private:
#endif
		//正负数 
		bool negative;
		/*
			negative为0时为正，negative为1时为负 
		*/
		
		//整数部分
		vector<BIG_NUM_VECROR_TYPE> integer;
		string integer_string;
		bool integer_string_need_updata;
		string integer_string_no_fix_zero;
		bool integer_string_no_fix_zero_need_updata;
		/*
			integer数组中，越在前面，越属于低位
			当integer[0]==5678, integer[1]==1234时，get_string_integer==1234,5678
		*/
		
		//小数部分
		vector<BIG_NUM_VECROR_TYPE> decimal;
		string decimal_string;
		bool decimal_string_need_updata;
		string decimal_string_no_fix_zero;
		bool decimal_string_no_fix_zero_need_updata;
		/*
			decimal数组中，越在前面，越属于高位
			decimal[0]==1234, decimal[1]==5678时，get_string_decimal==1234,5678
		*/
		
		//数
		string all_string;
		bool all_string_need_updata;
		string all_string_no_fix_zero;
		bool all_string_no_fix_zero_need_updata;
};

#endif

