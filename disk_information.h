#ifndef HLS_DISK_INFORMATION_H
#define HLS_DISK_INFORMATION_H

#include <stdlib.h>
#include "common/fstream.h"
#include "common/string.h"

string disk_information_temp_path="disk_information.temp";
bool disk_information_temp_delete=1;

class disk_information
{
	public:
		disk_information()
		{
			clear();
			return;
		}
		
		disk_information(char path)
		{
			clear();
			set_path(path);
			return;
		}
		
		void clear()
		{
			path=0;
			name="";
			serial="";
			return;
		}
		
		string name;
		string serial;
		char get_path()
		{
			return path;
		}
		
		bool set_path(char new_path)
		{
			if((new_path<'a' || 'z'<new_path) && (new_path<'A' || 'Z'<new_path))
				return 1;
			system(((string)"vol "+new_path+": >\""+disk_information_temp_path+"\"").c_str());
			ifstream in(disk_information_temp_path.c_str());
			char ch;
			in>>ch;
			if(ch!=EOF)
			{
				string temp;
				in>>temp;
				in>>path;
				in>>temp;
				in>>name;
				in>>temp;
				in>>serial;
			}
			in.close();
			if(disk_information_temp_delete)
				system(((string)"del \""+disk_information_temp_path+"\"").c_str());
			return ch==EOF;
		}
	
	private:
		char path;
};

#endif
//https://blog.csdn.net/limingandritchie/article/details/103666271
