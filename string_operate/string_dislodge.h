#ifndef HLS_STRING_DISLODGE_H
#define HLS_STRING_DISLODGE_H

#include "../common/string.h"

#define STRING_DISLODGE_BLANK 1				//0000 0001
#define STRING_DISLODGE_LETTER_BIG 2		//0000 0010
#define STRING_DISLODGE_LETTER_SMALL 4		//0000 0100
#define STRING_DISLODGE_NUMBER 8			//0000 1000
#define STRING_DISLODGE_POINT 16			//0001 0000
#define STRING_DISLODGE_PLUS 32				//0010 0000

#define STRING_DISLODGE_OTHER 64			//0100 0000
#define STRING_DISLODGE_CONTRARY 128		//1000 0000

string string_dislodge(string str,unsigned int type)
{
	bool blank=type&STRING_DISLODGE_BLANK;
	bool letter_big=type&STRING_DISLODGE_LETTER_BIG;
	bool letter_small=type&STRING_DISLODGE_LETTER_SMALL;
	bool number=type&STRING_DISLODGE_NUMBER;
	bool point=type&STRING_DISLODGE_POINT;
	bool plus=type&STRING_DISLODGE_PLUS;
	bool other=type&STRING_DISLODGE_OTHER;
	bool contrary=type&STRING_DISLODGE_CONTRARY;
	if(contrary)
	{
		blank=!blank;
		letter_big=!letter_big;
		letter_small=!letter_small;
		number=!number;
		point=!point;
		plus=!plus;
		other=!other;
	}
	string res="";
	for(unsigned int i=0;i<str.size();i++)
	{
		if(blank && str[i]==' ')
			continue;
		if(letter_big && 'A'<=str[i] && str[i]<='Z')
			continue;
		if(letter_small && 'a'<=str[i] && str[i]<='z')
			continue;
		if(number && '0'<=str[i] && str[i]<='9')
			continue;
		if(point && str[i]=='.')
			continue;
		if(plus && str[i]=='+')
			continue;
		if(other && !(str[i]==' ' || ('A'<=str[i] && str[i]<='Z') || ('a'<=str[i] && str[i]<='z') || ('0'<=str[i] && str[i]<='9') || str[i]=='.' || str[i]=='+'))
			continue;
		res+=str[i];
	}
	return res;
}

#endif

