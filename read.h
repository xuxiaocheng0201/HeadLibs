#ifndef HLS_READ_H
#define HLS_READ_H

#include <stdio.h>
#include <bits/localefwd.h>

inline int read()
{
    int num=0;
    bool symbol=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar())
        if(c=='-')
            symbol=1;
    for(;isdigit(c);c=getchar())
        num=num*10+c-'0';
    return symbol?-num:num;
}

#endif

