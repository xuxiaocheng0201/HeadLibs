#ifndef HLS_CHECK_PATH_H
#define HLS_CHECK_PATH_H

#include "../common/string.h"
#include "../common/vector.h"

bool check_path(string path)
{
	if(path.empty())
		return 0;
	vector<string> temp_splited;
	temp_splited.clear();
	string::size_type size_pos=0;
	string::size_type size_prev_pos=0;
	while((size_pos=path.find_first_of('\\',size_pos))!=string::npos)
	{
		string temp=path.substr(size_prev_pos,size_pos-size_prev_pos);
		temp_splited.push_back(temp);
		size_prev_pos=++size_pos;
	}
	temp_splited.push_back(&path[size_prev_pos]);
	
	vector<string> splited;
	splited.clear();
	for(unsigned int i=0;i<temp_splited.size();i++)
	{
		string::size_type size_pos=0;
		string::size_type size_prev_pos=0;
		while((size_pos=temp_splited[i].find_first_of('/',size_pos))!=string::npos)
		{
			string temp=temp_splited[i].substr(size_prev_pos,size_pos-size_prev_pos);
			splited.push_back(temp);
			size_prev_pos=++size_pos;
		}
		splited.push_back(&temp_splited[i][size_prev_pos]);
	}
	if(splited.size()==0)
		return 0;
	if(splited[0].size()!=2)
		return 0;
	if(splited[0][1]!=':')
		return 0;
	if((splited[0][0]<'a' || 'z'<splited[0][0]) && (splited[0][0]<'A' || 'Z'<splited[0][0]))
		return 0;
	int npos=0;
	for(unsigned int i=1;i<splited.size();i++)
	{
		if(splited[i].size()==0)
			return 0;
		npos=splited[i].find('\\');
		if(npos>0)
			return 0;
		npos=splited[i].find('/');
		if(npos>0)
			return 0;
		npos=splited[i].find(':');
		if(npos>0)
			return 0;
		npos=splited[i].find('*');
		if(npos>0)
			return 0;
		npos=splited[i].find('?');
		if(npos>0)
			return 0;
		npos=splited[i].find('"');
		if(npos>0)
			return 0;
		npos=splited[i].find('<');
		if(npos>0)
			return 0;
		npos=splited[i].find('>');
		if(npos>0)
			return 0;
		npos=splited[i].find('|');
		if(npos>0)
			return 0;
	}
	return 1;
}

#endif

