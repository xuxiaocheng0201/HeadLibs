#ifndef HLS_MOUSE_H
#define HLS_MOUSE_H

#include "get_mouse.h"

#ifndef MOUSE_SLEEP_TIME
#define MOUSE_SLEEP_TIME 50
#endif

inline void set_mouse_state(DWORD mouse)
{
	mouse_event(mouse,0,0,0,0);
	Sleep(MOUSE_SLEEP_TIME);	//给一些进程反应时间 
	return;
}

inline void input_mouse(int mouse)
{
	if(mouse==VM_Left)
		if(get_mouse_left_click())
		{
			set_mouse_state(VM_Left_UP);
			set_mouse_state(VM_Left_DOWN);
		}
		else
		{
			set_mouse_state(VM_Left_DOWN);
			set_mouse_state(VM_Left_UP);
		}
	else;
	if(mouse==VM_Middle)
		if(get_mouse_middle_click())
		{
			set_mouse_state(VM_Middle_UP);
			set_mouse_state(VM_Middle_DOWN);
		}
		else
		{
			set_mouse_state(VM_Middle_DOWN);
			set_mouse_state(VM_Middle_UP);
		}
	else;
	if(mouse==VM_Right)
		if(get_mouse_right_click())
		{
			set_mouse_state(VM_Right_UP);
			set_mouse_state(VM_Right_DOWN);
		}
		else
		{
			set_mouse_state(VM_Right_DOWN);
			set_mouse_state(VM_Right_UP);
		}
	else;
	return;
}

#endif
