#ifndef HLS_COPY_FILE_H
#define HLS_COPY_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include "common/string.h"
#include "common/fstream.h"
#include "logger.h"
#include "file_exists.h"
#include "get_file_size.h"

#ifndef COPY_FILE_DEFAULT_BUFFER_SIZE
#define COPY_FILE_DEFAULT_BUFFER_SIZE 1024
#endif

#ifdef COPY_FILE_USE_GLOBAL_BUFFER
const size_t copy_file_buffer_size=COPY_FILE_DEFAULT_BUFFER_SIZE;
char* buffer[copy_file_buffer_size];
#else
size_t copy_file_buffer_size=COPY_FILE_DEFAULT_BUFFER_SIZE;
#endif

bool copy_file(string source,string target)
{
	if(!file_exists(source))
	{
		logger("ERROR","[COPY_FILE.H][COPY_FILE]source file does not exist.");
		logger("DEBUG","[COPY_FILE.H][COPY_FILE]source is \""+source+"\". target is \""+target+"\".");
		return 0;
	}
	FILE* fin=fopen(source.c_str(),"rb");
	if(fin==NULL)
	{
		logger("ERROR","[COPY_FILE.H][COPY_FILE]fin open failed.");
		logger("DEBUG","[COPY_FILE.H][COPY_FILE]source is \""+source+"\". target is \""+target+"\".");
		return 0;
	}
	FILE* fout=fopen(target.c_str(),"wb");
	if(fout==NULL)
	{
		fclose(fin);
		logger("ERROR","[COPY_FILE.H][COPY_FILE]fout open failed.");
		logger("DEBUG","[COPY_FILE.H][COPY_FILE]source is \""+source+"\". target is \""+target+"\".");
		return 0;
	}
	size_t file_size=get_file_size(source);
	#ifndef COPY_FILE_USE_GLOBAL_BUFFER
	char* buffer[copy_file_buffer_size];
	#endif
	for(size_t i=0;i+copy_file_buffer_size<=file_size;i+=copy_file_buffer_size)
	{
		fread(buffer,sizeof(char),copy_file_buffer_size,fin);
		fwrite(buffer,sizeof(char),copy_file_buffer_size,fout);
	}
	size_t rest_copy_size=file_size%copy_file_buffer_size;
	if(rest_copy_size)
	{
		fread(buffer,sizeof(char),rest_copy_size,fin);
		fwrite(buffer,sizeof(char),rest_copy_size,fout);
	}
	fclose(fin);
	fclose(fout);
	return 1;
}

#endif

