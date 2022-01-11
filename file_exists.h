#ifndef HLS_FILE_EXIST_H
#define HLS_FILE_EXIST_H

#include <sys/stat.h>
#include "common/string.h"

struct stat file_exists_buffer;
bool file_exists(string name)
{
	return !stat(name.c_str(),&file_exists_buffer);
}

#endif

