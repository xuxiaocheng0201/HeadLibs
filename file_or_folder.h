#ifndef HLS_FILE_OR_FOLDER_H
#define HLS_FILE_OR_FOLDER_H

#include <sys/stat.h>
#include "common/string.h"

#define FILE_OR_FOLDER_ERROR 0
#define FILE_OR_FOLDER_FILE 1
#define FILE_OR_FOLDER_FOLDER 2

struct _stat file_or_folder_buffer;
int file_or_folder(string path)
{
	_stat(path.c_str(),&file_or_folder_buffer);
	if(file_or_folder_buffer.st_mode & _S_IFREG)
		return FILE_OR_FOLDER_FILE;
	if(file_or_folder_buffer.st_mode & _S_IFDIR)
		return FILE_OR_FOLDER_FOLDER;
	return FILE_OR_FOLDER_ERROR;
}

#endif

