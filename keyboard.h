#ifndef HLS_KEYBOARD_H
#define HLS_KEYBOARD_H

#include <synchapi.h>
#include "get_keyboard.h"

#ifndef KEYBOARD_SLEEP_TIME
#define KEYBOARD_SLEEP_TIME 50
#endif

inline void set_keyboard_state(int Key,bool Press=true)
{
	if(Press)
		keybd_event(Key,0,KEYEVENTF_EXTENDEDKEY | 0,0);
	else
		keybd_event(Key,0,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,0);
	Sleep(KEYBOARD_SLEEP_TIME);	//给一些进程反应时间 
	return;
}

inline void input_keyboard(int Key)
{
	if(get_keyboard_state(Key))
	{
		set_keyboard_state(Key,false);
		set_keyboard_state(Key,true);
	}
	else
	{
		set_keyboard_state(Key,true);
		set_keyboard_state(Key,false);
	}
	return;
}

//CapsLock为TRUE则切换大写状态,为FALSE则切换小写状态
inline void set_caps_lock(bool CapsLock=false)
{
	if(get_keyboard_state(VK_CAPITAL) != CapsLock)
		input_keyboard(VK_CAPITAL);
	return;
}

#endif

