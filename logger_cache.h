#ifndef HLS_LOGGER_CACHE_H
#define HLS_LOGGER_CACHE_H

#include <minwindef.h>
#include <minwinbase.h>
#include <sysinfoapi.h>
#include <synchapi.h>

#include "logger.h"
#include "string_operate/turn/turn_string.h"
#include "get_files.h"

#undef logger
#define logger logger_cache_write

string log_cache_temp_path="logs_temp";

bool logger_cache_write(string level,string strlog)
{
	if(file_or_folder(log_cache_temp_path)!=FILE_OR_FOLDER_FOLDER)
		system(("md "+log_cache_temp_path).c_str());
	
	SYSTEMTIME LogTempTime=get_system_time();
	string new_log_path=log_cache_temp_path+"\\"+turn_string(LogTempTime.wYear)
					+"_"+turn_string(LogTempTime.wMonth)
					+"_"+turn_string(LogTempTime.wDay)
					+"_"+turn_string(LogTempTime.wHour)
					+"_"+turn_string(LogTempTime.wMinute)
					+"_"+turn_string(LogTempTime.wSecond)
					+"_"+turn_string(LogTempTime.wMilliseconds)
					+".txt";
	FILE *fp=fopen(new_log_path.c_str(),"at");
	if(fp==NULL)
		return 0;
	if(LOGGER_SHOW_DATE || LOGGER_SHOW_TIME || LOGGER_SHOW_MILLISECOND)
	{
		SYSTEMTIME st=get_system_time();
		if(LOGGER_SHOW_DATE && !LOGGER_SHOW_TIME && !LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Year:%d Month:%d Day:%d Week:%d]",st.wYear,st.wMonth,st.wDay,st.wDayOfWeek);
		if(!LOGGER_SHOW_DATE && LOGGER_SHOW_TIME && !LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Hour:%d Minute:%d Second:%d]",st.wHour,st.wMinute,st.wSecond);
		if(!LOGGER_SHOW_DATE && !LOGGER_SHOW_TIME && LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Milliseconds:%d]",st.wMilliseconds);
		
		if(LOGGER_SHOW_DATE && LOGGER_SHOW_TIME && !LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Year:%d Month:%d Day:%d Week:%d Hour:%d Minute:%d Second:%d]",st.wYear,st.wMonth,st.wDay,st.wDayOfWeek,st.wHour,st.wMinute,st.wSecond);
		if(LOGGER_SHOW_DATE && !LOGGER_SHOW_TIME && LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Year:%d Month:%d Day:%d Week:%d Milliseconds:%d]",st.wYear,st.wMonth,st.wDay,st.wDayOfWeek,st.wMilliseconds);
		if(!LOGGER_SHOW_DATE && LOGGER_SHOW_TIME && LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Hour:%d Minute:%d Second:%d Milliseconds:%d]",st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);
		
		if(LOGGER_SHOW_DATE && LOGGER_SHOW_TIME && LOGGER_SHOW_MILLISECOND)
			fprintf(fp,"[Year:%d Month:%d Day:%d Week:%d Hour:%d Minute:%d Second:%d Milliseconds:%d]",st.wYear,st.wMonth,st.wDay,st.wDayOfWeek,st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);
	}
	if(level!="")
		fprintf(fp,"[%s]",level.c_str());
	fprintf(fp,strlog.c_str());
	fprintf(fp,"\n");
	fclose(fp);
	return 1;
}

bool logger_cache_arrange()
{
	static bool used=0;
	while(used)
		Sleep(1);
	used=1;
	
	vector<string> paths;
	paths.clear();
	get_files(log_cache_temp_path,paths,log_cache_temp_path+"\\temp.txt");
	for(unsigned int i=0;i<paths.size();i++)
	{
		if(paths[i][paths[i].size()-9]=='\\' &&
		   paths[i][paths[i].size()-8]=='t' &&
		   paths[i][paths[i].size()-7]=='e' &&
		   paths[i][paths[i].size()-6]=='m' &&
		   paths[i][paths[i].size()-5]=='p' &&
		   paths[i][paths[i].size()-4]=='.' &&
		   paths[i][paths[i].size()-3]=='t' &&
		   paths[i][paths[i].size()-2]=='x' &&
		   paths[i][paths[i].size()-1]=='t')
			continue;
		string log="";
		ifstream in(paths[i].c_str());
		if(!in)
		{
			used=0;
			return 0;
		}
		getline(in,log);
		in.close();
		FILE *out=fopen(log_path.c_str(),"at");
		if(out==NULL)
			return 0;
		fprintf(out,log.c_str());
		fprintf(out,"\n");
		fclose(out);
		system(("del \""+paths[i]+"\"").c_str());
	}
	system(("del \""+log_cache_temp_path+"\\temp.txt\"").c_str());
	
	used=0;
	return 1;
}

#endif

