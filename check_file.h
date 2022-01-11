#ifndef HLS_CHECK_FILE_H
#define HLS_CHECK_FILE_H

#if !defined(CHECK_FILE_CHOOSE_MD5)\
 && !defined(CHECK_FILE_CHOOSE_SHA1)\
 && !defined(CHECK_FILE_CHOOSE_CRC8)\
 && !defined(CHECK_FILE_CHOOSE_CRC16)\
 && !defined(CHECK_FILE_CHOOSE_CRC32)\
 && !defined(CHECK_FILE_CHOOSE_SIZE)\
 && !defined(CHECK_FILE_CHOOSE_TIME)
#error You must choose at lease one CHECK_FILE_CHOOSE_ mode above.
#endif

#ifdef CHECK_FILE_CHOOSE_MD5
#include "check_file/check_file_MD5.h"
string getMD5(string path)
{
	ifstream in(path.c_str(),std::ios::in | std::ios::binary);
	if(!in)
		return "error";
	MD5 md5(in);
	return md5.result();
}
int check_file_MD5(string file1,string file2)
{
	string a=getMD5(file1);
	if(a=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_MD5]Open file1=\""+file1+"\" fail.");
		#endif
		return -1;
	}
	string b=getMD5(file2);
	if(b=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_MD5]Open file2=\""+file2+"\" fail.");
		#endif
		return -1;
	}
	return a==b;
}
#endif

#ifdef CHECK_FILE_CHOOSE_SHA1
#include "check_file/check_file_SHA1.h"
string getSHA1(string path)
{
	ifstream in(path.c_str(),std::ios::in | std::ios::binary);
	if(!in)
		return "error";
	SHA1 sha1(in);
	return sha1.result();
}
int check_file_SHA1(string file1,string file2)
{
	string a=getSHA1(file1);
	if(a=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_SHA1]Open file1=\""+file1+"\" fail.");
		#endif
		return -1;
	}
	string b=getSHA1(file2);
	if(b=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_SHA1]Open file2=\""+file2+"\" fail.");
		#endif
		return -1;
	}
	return a==b;
}
#endif

#ifdef CHECK_FILE_CHOOSE_CRC8
#include "check_file/check_file_CRC8.h"
string getCRC8(string path)
{
	unsigned int crcvalue;
	if(CRC8_calc_img(path.c_str(),&crcvalue)==-1)
		return "error";
	char* crc8=(char*)malloc(3*sizeof(char*));
	sprintf(crc8,"%02x",crcvalue);
	string _crc8;_crc8.clear();
	for(unsigned int i=0;crc8[i]!='\0';i++)
		_crc8+=crc8[i];
	return _crc8;
}
int check_file_CRC8(string file1,string file2)
{
	string a=getCRC8(file1);
	if(a=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_CRC8]Open file1=\""+file1+"\" fail.");
		#endif
		return -1;
	}
	string b=getCRC8(file2);
	if(b=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_CRC8]Open file2=\""+file2+"\" fail.");
		#endif
		return -1;
	}
	return a==b;
}
#endif

#ifdef CHECK_FILE_CHOOSE_CRC16
#include "check_file/check_file_CRC16.h"
string getCRC16(string path)
{
	unsigned int crcvalue;
	if(CRC16_calc_img(path.c_str(),&crcvalue)==-1)
		return "error";
	char* crc16=(char*)malloc(5*sizeof(char*));
	sprintf(crc16,"%04x",crcvalue);
	string _crc16;_crc16.clear();
	for(unsigned int i=0;crc16[i]!='\0';i++)
		_crc16+=crc16[i];
	return _crc16;
}
int check_file_CRC16(string file1,string file2)
{
	string a=getCRC16(file1);
	if(a=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_CRC16]Open file1=\""+file1+"\" fail.");
		#endif
		return -1;
	}
	string b=getCRC16(file2);
	if(b=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_CRC16]Open file2=\""+file2+"\" fail.");
		#endif
		return -1;
	}
	return a==b;
}
#endif

#ifdef CHECK_FILE_CHOOSE_CRC32
#include "check_file/check_file_CRC32.h"
string getCRC32(string path)
{
	unsigned int crcvalue;
	CRC32_calc_img(path.c_str(),&crcvalue);
	char* crc32=(char*)malloc(9*sizeof(char*));
	sprintf(crc32,"%08x",crcvalue);
	string _crc32;_crc32.clear();
	for(unsigned int i=0;crc32[i]!='\0';i++)
		_crc32+=crc32[i];
	return _crc32;
}
int check_file_CRC32(string file1,string file2)
{
	string a=getCRC32(file1);
	if(a=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_CRC32]Open file1=\""+file1+"\" fail.");
		#endif
		return -1;
	}
	string b=getCRC32(file2);
	if(b=="error")
	{
		#ifdef HLS_LOGGER_H
		logger("ERROR","[CHECK_FILE.H][check_file_CRC32]Open file2=\""+file2+"\" fail.");
		#endif
		return -1;
	}
	return a==b;
}
#endif

#ifdef CHECK_FILE_CHOOSE_SIZE
#include "get_file_size.h"
int check_file_SIZE(string file1,string file2)
{
	return get_file_size(file1)==get_file_size(file2);
}
#endif

#ifdef CHECK_FILE_CHOOSE_TIME
#include "get_file_time.h"
#include "compare_SYSTEMTIME.h"
int check_file_TIME(string file1,string file2)
{
	return get_file_time(file1)==get_file_time(file2);
}
#endif

int check_file(string file1,string file2)
{
	#ifdef CHECK_FILE_CHOOSE_MD5
	int MD5=check_file_MD5(file1,file2);
	if(MD5!=1)
		return MD5;
	#endif
	#ifdef CHECK_FILE_CHOOSE_SHA1
	int SHA1=check_file_SHA1(file1,file2);
	if(SHA1!=1)
		return SHA1;
	#endif
	#ifdef CHECK_FILE_CHOOSE_CRC8
	int CRC8=check_file_CRC8(file1,file2);
	if(CRC8!=1)
		return CRC8;
	#endif
	#ifdef CHECK_FILE_CHOOSE_CRC16
	int CRC16=check_file_CRC16(file1,file2);
	if(CRC16!=1)
		return CRC16;
	#endif
	#ifdef CHECK_FILE_CHOOSE_CRC32
	int CRC32=check_file_CRC32(file1,file2);
	if(CRC32!=1)
		return CRC32;
	#endif
	#ifdef CHECK_FILE_CHOOSE_SIZE
	int SIZE=check_file_SIZE(file1,file2);
	if(SIZE!=1)
		return SIZE;
	#endif
	#ifdef CHECK_FILE_CHOOSE_TIME
	int TIME=check_file_SIME(file1,file2);
	if(TIME!=1)
		return TIME;
	#endif
	return 1;
}

#endif

