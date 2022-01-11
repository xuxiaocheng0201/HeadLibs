#ifndef HLS_BIG_NUM_H
#define HLS_BIG_NUM_H

/*
	UNKNOWN BUG WARNING
	
	When use big_num.set(string num) and num is a char*-string
	//for example, num.set("1");
	you must add (string) before char*-string.
	//for example, num.set((string)"1");
	Or it will be considered as a char and it won't work!!
	
	Also, operator = has the same problem.
*/

#include "big_num_define.h"
#include "big_num_error.h"
#include "big_num_base.h"
#include "big_num_calculate.h"
//#include "big_num_operator.h"

#endif

