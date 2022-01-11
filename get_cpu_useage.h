#ifndef HLS_GET_CPU_USEAGE_H
#define HLS_GET_CPU_USEAGE_H

#include <windef.h>
#include <winbase.h>

class get_cpu_useage
{
	public:
		//两次调用之间需间隔一段时间，否则会给出错误的答案，建议1秒
		double CpuUseage()
		{
			FILETIME idleTime;
			FILETIME kernelTime;
			FILETIME userTime;
			GetSystemTimes(&idleTime,&kernelTime,&userTime);
			int idle=CompareFileTime(m_preidleTime,idleTime);
			int kernel=CompareFileTime(m_prekernelTime,kernelTime);
			int user=CompareFileTime(m_preuserTime,userTime);
			if(kernel+user==0)
				return 0;
			double cpu=(kernel+user-idle)*100.0/(kernel+user);
			m_preidleTime=idleTime;
			m_prekernelTime=kernelTime;
			m_preuserTime=userTime;
			return cpu;
		}
	private:
		FILETIME m_preidleTime;
		FILETIME m_prekernelTime;
		FILETIME m_preuserTime;
		__int64 CompareFileTime(FILETIME time1,FILETIME time2)
		{
			__int64 a=/*time1.dwHighDateTime<<32 | */time1.dwLowDateTime;
			__int64 b=/*time2.dwHighDateTime<<32 | */time2.dwLowDateTime;
			return b-a;
		}
};

#endif
//https://blog.csdn.net/anda0109/article/details/40073067
