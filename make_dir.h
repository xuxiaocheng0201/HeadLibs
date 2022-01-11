#ifndef HLS_MAKE_DIR_H
#define HLS_MAKE_DIR_H

#include <direct.h>
#include "common/string.h"
#include "logger.h"

bool make_dir(string dir_path)
{
	if(access(dir_path.c_str(),0))
		if(mkdir(dir_path.c_str())==0)
			return 1;
		else
			logger("ERROR","[MAKE_DIR.H][MAKE_DIR]mkdir failed. [dir_path]=\""+dir_path+"\".");
	else
		logger("ERROR","[MAKE_DIR.H][MAKE_DIR]dir_path error. [dir_path]=\""+dir_path+"\".");
	return 0;
}

#endif
//https://blog.csdn.net/sinat_41104353/article/details/83149441
