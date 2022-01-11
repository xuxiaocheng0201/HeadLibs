#ifndef HLS_PTHREAD_LIVES_H
#define HLS_PTHREAD_LIVES_H

#include <pthread.h>
#include <errno.h>

#define PTHREAD_ERROR -1
#define PTHREAD_ALIVE 1
#define PTHREAD_DEAD 0

int pthread_lives(pthread_t tid)
{
	int res=pthread_kill(tid,0);
	if(res==EINVAL)
		return PTHREAD_ERROR;
	if(res==ESRCH)
		return PTHREAD_DEAD;
	return PTHREAD_ALIVE;
}

#endif
//https://zhidao.baidu.com/question/1494312705810216619.html
