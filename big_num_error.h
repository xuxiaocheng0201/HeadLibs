#ifndef HLS_BIG_NUM_ERROR_H
#define HLS_BIG_NUM_ERROR_H

#include "big_num_define.h"

void big_num::size_error_fix()
{
	if(integer.size()==0)
		integer.push_back(0);
	if(decimal.size()==0)
		decimal.push_back(0);
	return;
}

void big_num::error_set()
{
	static bool run_once=0;
	if(run_once)
		return;
	run_once=1;
	
	
	
	return;
}

#endif

