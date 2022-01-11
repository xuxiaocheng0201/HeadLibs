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
	char disk;	//磁盘盘符
	unsigned long long all;		//磁盘总的大小
	unsigned long long free;	//磁盘可用空间
	UINT type;		//磁盘类型
// 1 DRIVE_UNKNOWN		无法确定驱动器类型。
// 2 DRIVE_NO_ROOT_DIR	根路径无效; 例如，指定路径上没有安装卷。
// 3 DRIVE_REMOVABLE	驱动器有可移动介质; 例如，软盘驱动器，拇指驱动器或闪存卡读卡器。
// 4 DRIVE_FIXED		驱动器有固定的媒体; 例如，硬盘驱动器或闪存驱动器。
// 5 DRIVE_REMOTE		该驱动器是远程（网络）驱动器。
// 6 DRIVE_CDROM		该驱动器是一个CD-ROM驱动器。
// 7 DRIVE_RAMDISK		驱动器是RAM磁盘。
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
