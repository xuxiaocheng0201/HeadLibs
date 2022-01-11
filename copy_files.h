#ifndef HLS_COPY_FILES_H
#define HLS_COPY_FILES_H

#include "file_or_folder.h"
#include "get_files.h"
#include "copy_file.h"

string copy_files_temp_path="copy_files_temp.txt";

bool copy_files(string source,string target)
{
	if(file_or_folder(source)==FILE_OR_FOLDER_ERROR)
	{
		logger("ERROR","[COPY_FILES.H][COPY_FILES]source file error.");
		logger("DEBUG","[COPY_FILES.H][COPY_FILES]source is \""+source+"\". target is \""+target+"\".");
		return 0;
	}
	if(file_or_folder(source)==FILE_OR_FOLDER_FILE)
		return copy_file(source,target);
	vector<string> files;files.clear();
	get_files(source,files,copy_files_temp_path);
	for(unsigned int i=0;i<files.size();i++)
	{
		string outpath;
		copy_file(files[i],outpath);
	}
	
	return 1;
}

#ifdef COPY_FILES_INCLUDE_SYSTEM
#include <windef.h>
#include <winbase.h> 
#include <winnt.h>
#include <Shellapi.h>
#include <tchar.h>
int copy_files_system(string source,string target,bool undo)
{
	SHFILEOPSTRUCT file;
	file.wFunc=FO_COPY;
	file.pFrom=source.c_str();
	file.pTo=target.c_str();
	file.fFlags=FOF_SILENT|FOF_NOCONFIRMATION|FOF_NOERRORUI|FOF_NOCONFIRMMKDIR;
	if(undo)
		file.fFlags|=FOF_ALLOWUNDO;
	return SHFileOperation(&file);
}
//https://blog.csdn.net/tiandyoin/article/details/82255183
//https://blog.csdn.net/xd_code/article/details/1417016
#endif

#endif

