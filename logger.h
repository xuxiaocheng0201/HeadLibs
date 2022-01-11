#ifndef HLS_LOGGER_H
#define HLS_LOGGER_H

#include <stdio.h>
#include "system_time.h"
#include "common/string.h"

#define logger normal_logger

bool LOGGER_SHOW_DATE=1;
bool LOGGER_SHOW_TIME=1;
bool LOGGER_SHOW_MILLISECOND=1;
string log_path="log.txt";

//Success returns 1. Failure returns 0.
bool normal_logger(string level,string strlog)
{
	FILE *fp=fopen(log_path.c_str(),"at");
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

inline bool special_logger(string level,string strlog,string new_log_path)
{
	string old_log_path=log_path;
	log_path=new_log_path;
	bool return_value=logger(level,strlog);
	log_path=old_log_path;
	return return_value;
}

inline bool special_logger(string level,string strlog,bool new_LOGGER_SHOW_DATE,bool new_LOGGER_SHOW_TIME,bool new_LOGGER_SHOW_MILLISECOND)
{
	bool old_LOGGER_SHOW_DATE=LOGGER_SHOW_DATE;
	bool old_LOGGER_SHOW_TIME=LOGGER_SHOW_TIME;
	bool old_LOGGER_SHOW_MILLISECOND=LOGGER_SHOW_MILLISECOND;
	
	LOGGER_SHOW_DATE=new_LOGGER_SHOW_DATE;
	LOGGER_SHOW_TIME=new_LOGGER_SHOW_TIME;
	LOGGER_SHOW_MILLISECOND=new_LOGGER_SHOW_MILLISECOND;
	
	bool return_value=logger(level,strlog);
	
	LOGGER_SHOW_DATE=old_LOGGER_SHOW_DATE;
	LOGGER_SHOW_TIME=old_LOGGER_SHOW_TIME;
	LOGGER_SHOW_MILLISECOND=old_LOGGER_SHOW_MILLISECOND;
	
	return return_value;
}

inline bool special_logger(string level,string strlog,string new_log_path,bool new_LOGGER_SHOW_DATE,bool new_LOGGER_SHOW_TIME,bool new_LOGGER_SHOW_MILLISECOND)
{
	bool old_LOGGER_SHOW_DATE=LOGGER_SHOW_DATE;
	bool old_LOGGER_SHOW_TIME=LOGGER_SHOW_TIME;
	bool old_LOGGER_SHOW_MILLISECOND=LOGGER_SHOW_MILLISECOND;
	string old_log_path=log_path;
	
	LOGGER_SHOW_DATE=new_LOGGER_SHOW_DATE;
	LOGGER_SHOW_TIME=new_LOGGER_SHOW_TIME;
	LOGGER_SHOW_MILLISECOND=new_LOGGER_SHOW_MILLISECOND;
	log_path=new_log_path;
	
	bool return_value=logger(level,strlog);
	
	LOGGER_SHOW_DATE=old_LOGGER_SHOW_DATE;
	LOGGER_SHOW_TIME=old_LOGGER_SHOW_TIME;
	LOGGER_SHOW_MILLISECOND=old_LOGGER_SHOW_MILLISECOND;
	log_path=old_log_path;
	
	return return_value;
}

#endif

