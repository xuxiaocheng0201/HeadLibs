#ifndef HLS_GET_DRIVERS_H
#define HLS_GET_DRIVERS_H

#include <windef.h>
#include <winbase.h>
#include "common/string.h"
#include "common/vector.h"
#include "logger.h"
#include "string_operate/turn/turn_string.h"

#include "GetLastError_string.h"

struct driver_information
{
	char disk;	//�����̷�
	unsigned long long all;		//�����ܵĴ�С
	unsigned long long free;	//���̿��ÿռ�
	UINT type;		//��������
// 1 DRIVE_UNKNOWN		�޷�ȷ�����������͡�
// 2 DRIVE_NO_ROOT_DIR	��·����Ч; ���磬ָ��·����û�а�װ��
// 3 DRIVE_REMOVABLE	�������п��ƶ�����; ���磬������������Ĵָ�����������濨��������
// 4 DRIVE_FIXED		�������й̶���ý��; ���磬Ӳ����������������������
// 5 DRIVE_REMOTE		����������Զ�̣����磩��������
// 6 DRIVE_CDROM		����������һ��CD-ROM��������
// 7 DRIVE_RAMDISK		��������RAM���̡�
	inline void clear()
	{
		disk=0;
		all=0;
		free=0;
		type=0;
		return;
	}
};

vector<driver_information> get_drivers()
{
	vector<driver_information> drivers;
	for(char d='A';d<='Z';d++)
	{
		driver_information dir;dir.clear();
		string szTemp;szTemp.clear();
		szTemp+=d;
		szTemp+=':';
		dir.type=GetDriveType(szTemp.c_str());
		if(dir.type==DRIVE_NO_ROOT_DIR)
			continue;
		dir.disk=d;
		unsigned long long i64FreeBytesToCaller;
		unsigned long long i64TotalBytes;
		unsigned long long i64FreeBytes;
		WINBOOL fResult=GetDiskFreeSpaceEx(szTemp.c_str(),(PULARGE_INTEGER)&i64FreeBytesToCaller,(PULARGE_INTEGER)&i64TotalBytes,(PULARGE_INTEGER)&i64FreeBytes);
		if(fResult)
		{
			dir.all=i64TotalBytes;
			dir.free=i64FreeBytesToCaller;
		}
		else
		{
			logger("ERROR","[GETDRIVERS.H]GetDiskFreeSpaceEx error.");
			logger("DEBUG","[GETDRIVERS.H]GetLastError is "+GetLastError_string()+". It means \""+GetLastError_string_meaning()+"\".");
		}
		drivers.push_back(dir);
	}
	return drivers;
}

#endif
//https://www.cnblogs.com/duxie/p/11204081.html
