#ifndef HLS_GET_FILE_SIZE_H
#define HLS_GET_FILE_SIZE_H

#include <sys/stat.h>
#include <io.h>
#include "common/string.h"

struct _stat get_file_size_quick_stat;
/*long*/_off_t get_file_size_quick(string file_path)
{
	_stat(file_path.c_str(),&get_file_size_quick_stat);
	return get_file_size_quick_stat.st_size;
}

/*long long*/__int64 get_file_size_common(string file_path)
{
	_finddatai64_t filefind;
	int handle=_findfirsti64(file_path.c_str(),&filefind);
	if(handle==-1)
		return -1;
	__int64 size=-1;
	if(!(_A_SUBDIR==(_A_SUBDIR & filefind.attrib)))
		size=filefind.size;
	_findclose(handle);
	return size;
}

#ifdef _WINDOWS_
/*unsigned __LONG32*/DWORD get_file_size_windows(string file_path)
{
	HANDLE fhandle=CreateFile(file_path.c_str(),0,0,0,OPEN_EXISTING,0,0);
	DWORD size=GetFileSize(fhandle,0);
	CloseHandle(fhandle);
	return size;
}
#endif

#define get_file_size get_file_size_common

#endif

