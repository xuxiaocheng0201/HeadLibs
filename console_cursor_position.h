#ifndef HLS_CONSOLE_CURSOR_POSITION_H
#define HLS_CONSOLE_CURSOR_POSITION_H

#include <windef.h>
#include <winbase.h>
#include <wincon.h>

struct console_cursor_position//x为列，y为行
{
	int x;
	int y;
};

console_cursor_position getxy()
{
	CONSOLE_SCREEN_BUFFER_INFO pos;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&pos);
	console_cursor_position position;
	position.x=pos.dwCursorPosition.X;
	position.y=pos.dwCursorPosition.Y;
	return position;
}

WINBOOL gotoxy(console_cursor_position position)
{
	COORD pos;
	pos.X=position.x;
	pos.Y=position.y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

#endif

