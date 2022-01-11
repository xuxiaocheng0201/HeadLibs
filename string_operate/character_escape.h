#ifndef HLS_CHARACTER_ESCAPE_H
#define HLS_CHARACTER_ESCAPE_H

#include "../common/string.h"

string character_escape(char character)
{
	if(character=='\a')
		return "\\a";
	if(character=='\b')
		return "\\b";
	if(character=='\f')
		return "\\f";
	if(character=='\n')
		return "\\n";
	if(character=='\r')
		return "\\r";
	if(character=='\t')
		return "\\t";
	if(character=='\v')
		return "\\v";
	if(character=='\'')
		return "\\\'";
	if(character=='\"')
		return "\\\"";
	if(character=='\\')
		return "\\\\";
	if(character=='\?')
		return "\\?";
	if(character=='\0')
		return "\\0";
	return (string)""+character;
}

char character_escape(string character)
{
	if(character=="\\a")
		return '\a';
	if(character=="\\b")
		return '\b';
	if(character=="\\n")
		return '\n';
	if(character=="\\f")
		return '\f';
	if(character=="\\r")
		return '\r';
	if(character=="\\t")
		return '\t';
	if(character=="\\v")
		return '\v';
	if(character=="\\\'")
		return '\'';
	if(character=="\\\"")
		return '\"';
	if(character=="\\\\")
		return '\\';
	if(character=="\\?")
		return '\?';
	if(character=="\\0")
		return '\0';
	return 0;
}

#endif

