#ifndef HLS_GET_FILES_H
#define HLS_GET_FILES_H

#include <time.h>
#include "common/fstream.h"
#include "common/string.h"
#include "common/vector.h"
#include "file_or_folder.h"

bool get_files(string path,vector<string>& files,clock_t call_time=clock(),clock_t offset=0)/*return overtime*/
{
	if(offset && clock()>=call_time+offset)
		return 0;
	long hFile=0;
	struct _finddata_t fileinfo;
	string p;
	if((hFile=_findfirst(p.assign(path).append("\\*").c_str(),&fileinfo))==-1)
		return 0;
	do
	{
		if(!(fileinfo.attrib & _A_SUBDIR))
			files.push_back(p.assign(path).append("\\").append(fileinfo.name));
		else
			if(strcmp(fileinfo.name,".")!=0 && strcmp(fileinfo.name,"..")!=0)
				if(!get_files(p.assign(path).append("\\").append(fileinfo.name),files,call_time,offset))
					return 0;
	}while(!_findnext(hFile,&fileinfo));
	_findclose(hFile);
	return 1;
}

bool get_files(string path,vector<string>& files,string temp_path)
{
	if(_access(path.c_str(),0)!=EOF)
	{
		#ifdef HLS_LOGGER_H
		logger("CMD","[GETFILES.H][get_files(EX)]dir \""+path+"\" /b /s >\""+temp_path+"\"");
		#endif
		system(("dir \""+path+"\" /b /s >\""+temp_path+"\"").c_str());
	}
	else
		return 0;
	ifstream in(temp_path.c_str());
	string temp;
	while(getline(in,temp))
		if(file_or_folder(temp)==FILE_OR_FOLDER_FILE)
			files.push_back(temp);
	in.close();
	return 1;
}

#endif
