#ifndef HLS_CONSOLE_TITLE_H
#define HLS_CONSOLE_TITLE_H

#include <windef.h>
#include <minwinbase.h>
#include <apisetcconv.h>
#include <wincon.h>
#include "common/string.h"
#include "turn_wstring.h"

#define GET_CONSOLE_TITLE_MAX_LEN 255

string get_console_title()
{
	char temp[GET_CONSOLE_TITLE_MAX_LEN];
	GetConsoleTitle(temp,GET_CONSOLE_TITLE_MAX_LEN);
	string title;
	title.append(temp);
	return title;
}

WINBOOL set_console_title(string title)
{
	return SetConsoleTitleW(turn_LPCWSTR(title));
	// SetWindowTextW( (HWND)/*窗口句柄*/, L"newTitle123231"/*新标题*/ );
}

#endif

