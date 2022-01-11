#ifndef HLS_GET_MOUSE_H
#define HLS_GET_MOUSE_H

#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <winuser.h>

//typedef int VM_Mouse;
#define VM_Left			MOUSE_MOVED
#define VM_Right		MOUSE_EVENT
#define VM_Middle		MOUSE_WHEELED
//typedef DWORD VM_Mouse_part;
#define VM_Left_UP		MOUSEEVENTF_LEFTUP
#define VM_Left_DOWN	MOUSEEVENTF_LEFTDOWN
#define VM_Right_UP		MOUSEEVENTF_RIGHTUP
#define VM_Right_DOWN	MOUSEEVENTF_RIGHTDOWN
#define VM_Middle_UP	MOUSEEVENTF_MIDDLEUP
#define VM_Middle_DOWN	MOUSEEVENTF_MIDDLEDOWN

bool get_mouse_left_click()
{
	if(GetAsyncKeyState(VM_Left) & 0x8000)
		return 1;
	return 0;
}

bool get_mouse_right_click()
{
	if(GetAsyncKeyState(VM_Right) & 0x8000)
		return 1;
	return 0;
}

bool get_mouse_middle_click()
{
	if(GetAsyncKeyState(VM_Middle) & 0x8000)
		return 1;
	return 0;
}

POINT get_mouse_position()
{
	POINT p;
	GetCursorPos(&p);
	return p;
}

#endif
//https://blog.csdn.net/weixin_43202230/article/details/102515347
