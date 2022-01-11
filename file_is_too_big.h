#ifndef HLS_FILE_IS_TOO_BIG_H
#define HLS_FILE_IS_TOO_BIG_H

#include "common/vector.h"
#include "turn_string.h"
#include "copy_file.h"

#ifndef B
#define B *1
#endif

#ifndef KB
#define KB *1024 B
#endif

#ifndef MB
#define MB *1024 KB
#endif

#ifndef GB
#define GB *1024 MB
#endif

#ifndef TB
#define TB *1024 GB
#endif

#ifndef PB
#define PB *1024 TB
#endif

#ifndef FILE_IS_TOO_BIG_DEFAULT_BUFFER_SIZE
#define FILE_IS_TOO_BIG_DEFAULT_BUFFER_SIZE 1024
#endif

#ifdef FILE_IS_TOO_BIG_USE_GLOBAL_BUFFER
const size_t file_is_too_big_buffer_size=FILE_IS_TOO_BIG_DEFAULT_BUFFER_SIZE;
char* file_is_too_big_buffer[file_is_too_big_buffer_size];
#else
size_t file_is_too_big_buffer_size=FILE_IS_TOO_BIG_DEFAULT_BUFFER_SIZE;
#endif

bool need_copy_file=1;
/*When file_size<=split_file_size, copy in_file_path to out_file_path+"_1.splited"*/
/*When in_files_path.size()==1 ,copy in_file_path to out_file_path*/

vector<string> split_file(string in_file_path,string out_file_path,size_t split_file_size/*1MB equals 1*1024*1024*/)
{
	vector<string> list;list.clear();
	size_t file_size=get_file_size(in_file_path);
	#ifdef HLS_LOGGER
	logger("DEBUG","[FILE_IS_TOO_BIG.H][SPLIT_FILE]file_size="+turn_string(file_size));
	if(file_size<=split_file_size)
	{
		if(need_copy_file)
		{
			string outpath=out_file_path+"_1.splited";
			copy_file(in_file_path,outpath);
			list.push_back(outpath);
		}
		else
			list.push_back(in_file_path);
		return list;
	}
	
	FILE* fin=fopen(in_file_path.c_str(),"rb");
	if(fin==NULL)
	{
		logger("ERROR","[FILE_IS_TOO_BIG.H][SPLIT_FILE]fin open failed.");
		logger("DEBUG","[FILE_IS_TOO_BIG.H][SPLIT_FILE]in_file_path is \""+in_file_path+"\". out_file_path is \""+out_file_path+"\".");
		return list;
	}
	#ifndef FILE_IS_TOO_BIG_USE_GLOBAL_BUFFER
	char* file_is_too_big_buffer[file_is_too_big_buffer_size];
	#endif
	unsigned int couter=1;
	while(1)
	{
		string outpath=out_file_path+"_"+turn_string(couter)+".splited";
		FILE* fout=fopen(outpath.c_str(),"wb");
		if(fout==NULL)
		{
			fclose(fin);
			logger("ERROR","[FILE_IS_TOO_BIG.H][SPLIT_FILE]fout open failed. couter is "+turn_string(couter)+".");
			logger("DEBUG","[FILE_IS_TOO_BIG.H][SPLIT_FILE]in_file_path is \""+in_file_path+"\". out_file_path is \""+out_file_path+"\".");
			return list;
		}
		size_t i=0;
		for(;i+file_is_too_big_buffer_size<=split_file_size;i+=file_is_too_big_buffer_size)
		{
			fread(file_is_too_big_buffer,sizeof(char),file_is_too_big_buffer_size,fin);
			fwrite(file_is_too_big_buffer,sizeof(char),file_is_too_big_buffer_size,fout);
		}
		size_t rest_split_size=split_file_size%file_is_too_big_buffer_size;
		if(rest_split_size)
		{
			fread(file_is_too_big_buffer,sizeof(char),rest_split_size,fin);
			fwrite(file_is_too_big_buffer,sizeof(char),rest_split_size,fout);
		}
		fclose(fout);
		couter++;
		list.push_back(outpath);
		
		if(couter*split_file_size>file_size)
			break;
	}
	string outpath=out_file_path+"_"+turn_string(couter)+".splited";
	FILE* fout=fopen(outpath.c_str(),"wb");
	if(fout==NULL)
	{
		fclose(fin);
		logger("ERROR","[FILE_IS_TOO_BIG.H][SPLIT_FILE]fout open failed. couter is "+turn_string(couter)+".");
		logger("DEBUG","[FILE_IS_TOO_BIG.H][SPLIT_FILE]in_file_path is \""+in_file_path+"\". out_file_path is \""+out_file_path+"\".");
		return list;
	}
	size_t rest_split_size=file_size-(couter-1)*split_file_size;
	size_t i=0;
	for(;i+file_is_too_big_buffer_size<=rest_split_size;i+=file_is_too_big_buffer_size)
	{
		fread(file_is_too_big_buffer,sizeof(char),file_is_too_big_buffer_size,fin);
		fwrite(file_is_too_big_buffer,sizeof(char),file_is_too_big_buffer_size,fout);
	}
	size_t rest_rest_split_size=rest_split_size%file_is_too_big_buffer_size;
	if(rest_rest_split_size)
	{
		fread(file_is_too_big_buffer,sizeof(char),rest_rest_split_size,fin);
		fwrite(file_is_too_big_buffer,sizeof(char),rest_rest_split_size,fout);
	}
	fclose(fout);
	list.push_back(outpath);
	fclose(fin);
	return list;
}

size_t merge_files(vector<string> in_files_path,string out_file_path)
{
	if(in_files_path.size()<=1)
	{
		if(need_copy_file && in_files_path.size()==1)
			copy_file(in_files_path[0],out_file_path);
		return get_file_size(out_file_path);
	}
	
	size_t all_files_size=0;
	FILE* fout=fopen(out_file_path.c_str(),"wb");
	if(fout==NULL)
	{
		logger("ERROR","[FILE_IS_TOO_BIG.H][MERGE_FILES]fout open failed.");
		logger("DEBUG","[FILE_IS_TOO_BIG.H][MERGE_FILES]in_file_path has "+turn_string(in_files_path.size())+" members. out_file_path is \""+out_file_path+"\".");
		return all_files_size;
	}
	#ifndef FILE_IS_TOO_BIG_USE_GLOBAL_BUFFER
	char* file_is_too_big_buffer[file_is_too_big_buffer_size];
	#endif
	for(unsigned int i=0;i<in_files_path.size();i++)
	{
		if(!file_exists(in_files_path[i]))
		{
			logger("WARN","[FILE_IS_TOO_BIG.H][MERGE_FILES]File in_files_path["+turn_string(i)+"] \""+in_files_path[i]+"\" does not exist.");
			continue;
		}
		size_t current_file_size=get_file_size(in_files_path[i]);
		FILE* fin=fopen(in_files_path[i].c_str(),"rb");
		if(fin==NULL)
		{
			logger("ERROR","[FILE_IS_TOO_BIG.H][MERGE_FILES]fin open failed.");
			logger("DEBUG","[FILE_IS_TOO_BIG.H][MERGE_FILES]in_file_path has "+turn_string(in_files_path.size())+" members. out_file_path is \""+out_file_path+"\". i is "+turn_string(i)+".");
			return all_files_size;
		}
		size_t j=0;
		for(;j+file_is_too_big_buffer_size<=current_file_size;j+=file_is_too_big_buffer_size)
		{
			fread(file_is_too_big_buffer,sizeof(char),file_is_too_big_buffer_size,fin);
			fwrite(file_is_too_big_buffer,sizeof(char),file_is_too_big_buffer_size,fout);
		}
		size_t rest_merge_size=current_file_size%file_is_too_big_buffer_size;
		if(rest_merge_size)
		{
			fread(file_is_too_big_buffer,sizeof(char),rest_merge_size,fin);
			fwrite(file_is_too_big_buffer,sizeof(char),rest_merge_size,fout);
		}
		fclose(fin);
		all_files_size+=current_file_size;
	}
	fclose(fout);
	return all_files_size;
}

size_t merge_files(string in_file_path,unsigned int files_count/*split_file().size()*/,string out_file_path)
{
	vector<string>files;files.clear();
	for(unsigned int i=1;i<=files_count;i++)
		files.push_back(in_file_path+"_"+turn_string(i)+".splited");
	return merge_files(files,out_file_path);
}

#endif

