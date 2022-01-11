#ifndef HLS_TURN_STRING_WINDOWS_H
#define HLS_TURN_STRING_WINDOWS_H

#include <windef.h>
#include "turn_string.h"

inline string turn_string(DWORD a1)
{
	string a2;
	turn_string_stream.clear();
	turn_string_stream<<a1;
	turn_string_stream>>a2;
	return a2;
}

#endif

