#ifndef HLS_ERROR_HANDLE_H
#define HLS_ERROR_HANDLE_H

//#include <error.h>
#include <errno.h>
#include "common/string.h"
#include "common/map.h"

map<int,pair<string,string> > error_meanings;

void error_meanings_init()
{
	static bool run_once=0;
	if(run_once)
		return;
	run_once=1;
#ifndef NO_ERROR
#define NO_ERROR 0
#endif
	error_meanings[NO_ERROR]=make_pair("NO_ERROR","All things are good. Nothing went wrong.");
#ifndef EPERM
#define EPERM 1
#endif
	error_meanings[EPERM]=make_pair("EPERM","Operation not permitted.");
#ifndef ENOENT
#define ENOENT 2
#endif
	error_meanings[ENOENT]=make_pair("ENOENT","No such file or directory.");
#ifndef ENOFILE
#define ENOFILE 2
#endif
	//2 error_meanings[ENOFILE]=make_pair("ENOFILE","No such file or directory.");
#ifndef ESRCH
#define ESRCH 3
#endif
	error_meanings[ESRCH]=make_pair("ESRCH","No such process.");
#ifndef EINTR
#define EINTR 4
#endif
	error_meanings[EINTR]=make_pair("EINTR","Interrupted system call.");
#ifndef EIO
#define EIO 5
#endif
	error_meanings[EIO]=make_pair("EIO","I/O error.");
#ifndef ENXIO
#define ENXIO 6
#endif
	error_meanings[ENXIO]=make_pair("ENXIO","No such device or address.");
#ifndef E2BIG
#define E2BIG 7
#endif
	error_meanings[E2BIG]=make_pair("E2BIG","Argument list too long.");
#ifndef ENOEXEC
#define ENOEXEC 8
#endif
	error_meanings[ENOEXEC]=make_pair("ENOEXEC","Exec format error.");
#ifndef EBADF
#define EBADF 9
#endif
	error_meanings[EBADF]=make_pair("EBADF","Bad file number.");
#ifndef ECHILD
#define ECHILD 10
#endif
	error_meanings[ECHILD]=make_pair("ECHILD","No child processes.");
#ifndef EAGAIN
#define EAGAIN 11
#endif
	error_meanings[EAGAIN]=make_pair("EAGAIN","Try again.");
#ifndef EWOULDBLOCK
#define EWOULDBLOCK 140/*11*/
#endif
	error_meanings[EWOULDBLOCK]=make_pair("EWOULDBLOCK","Operation would block.");
#ifndef ENOMEM
#define ENOMEM 12
#endif
	error_meanings[ENOMEM]=make_pair("ENOMEM","Out of memory.");
#ifndef EACCES
#define EACCES 13
#endif
	error_meanings[EACCES]=make_pair("EACCES","Permission denied.");
#ifndef EFAULT
#define EFAULT 14
#endif
	error_meanings[EFAULT]=make_pair("EFAULT","Bad address.");
#ifndef ENOTBLK
#define ENOTBLK 15
#endif
	error_meanings[ENOTBLK]=make_pair("ENOTBLK","Block device required.");
#ifndef EBUSY
#define EBUSY 16
#endif
	error_meanings[EBUSY]=make_pair("EBUSY","Device or resource busy.");
#ifndef EEXIST
#define EEXIST 17
#endif
	error_meanings[EEXIST]=make_pair("EEXIST","File exists.");
#ifndef EXDEV
#define EXDEV 18
#endif
	error_meanings[EXDEV]=make_pair("EXDEV","Cross-device link.");
#ifndef ENODEV
#define ENODEV 19
#endif
	error_meanings[ENODEV]=make_pair("ENODEV","No such device.");
#ifndef ENOTDIR
#define ENOTDIR 20
#endif
	error_meanings[ENOTDIR]=make_pair("ENOTDIR","Not a directory.");
#ifndef EISDIR
#define EISDIR 21
#endif
	error_meanings[EISDIR]=make_pair("EISDIR","Is a directory.");
#ifndef EINVAL
#define EINVAL 22
#endif
	error_meanings[EINVAL]=make_pair("EINVAL","Invalid argument.");
#ifndef ENFILE
#define ENFILE 23
#endif
	error_meanings[ENFILE]=make_pair("ENFILE","File table overflow.");
#ifndef EMFILE
#define EMFILE 24
#endif
	error_meanings[EMFILE]=make_pair("EMFILE","Too many open files.");
#ifndef ENOTTY
#define ENOTTY 25
#endif
	error_meanings[ENOTTY]=make_pair("ENOTTY","Not a typewriter.");
#ifndef ETXTBSY
#define ETXTBSY 26
#endif
	error_meanings[ETXTBSY]=make_pair("ETXTBSY","Text file busy.");
#ifndef EFBIG
#define EFBIG 27
#endif
	error_meanings[EFBIG]=make_pair("EFBIG","File too large.");
#ifndef ENOSPC
#define ENOSPC 28
#endif
	error_meanings[ENOSPC]=make_pair("ENOSPC","No space left on device.");
#ifndef ESPIPE
#define ESPIPE 29
#endif
	error_meanings[ESPIPE]=make_pair("ESPIPE","Illegal seek.");
#ifndef EROFS
#define EROFS 30
#endif
	error_meanings[EROFS]=make_pair("EROFS","Read-only file system.");
#ifndef EMLINK
#define EMLINK 31
#endif
	error_meanings[EMLINK]=make_pair("EMLINK","Too many links.");
#ifndef EPIPE
#define EPIPE 32
#endif
	error_meanings[EPIPE]=make_pair("EPIPE","Broken pipe.");
#ifndef EDOM
#define EDOM 33
#endif
	error_meanings[EDOM]=make_pair("EDOM","Math argument out of domain of func.");
#ifndef ERANGE
#define ERANGE 34
#endif
	error_meanings[ERANGE]=make_pair("ERANGE","Math result not representable.");
#ifndef EDEADLK
#define EDEADLK 36/*35*/
#endif
	error_meanings[EDEADLK]=make_pair("EDEADLK","Resource deadlock would occur.");
#ifndef EDEADLOCK
#define EDEADLOCK 36/*35*/
#endif
	//error_meanings[EDEADLOCK]=make_pair("EDEADLOCK","Resource deadlock would occur.");
#ifndef ENAMETOOLONG
#define ENAMETOOLONG 38/*36*/
#endif
	error_meanings[ENAMETOOLONG]=make_pair("ENAMETOOLONG","File name too long.");
#ifndef ENOLCK
#define ENOLCK 39/*37*/
#endif
	error_meanings[ENOLCK]=make_pair("ENOLCK","No record locks available.");
#ifndef ENOSYS
#define ENOSYS 40/*38*/
#endif
	error_meanings[ENOSYS]=make_pair("ENOSYS","Function not implemented.");
#ifndef ENOTEMPTY
#define ENOTEMPTY 41/*39*/
#endif
	error_meanings[ENOTEMPTY]=make_pair("ENOTEMPTY","Directory not empty.");
#ifndef ELOOP
#define ELOOP 114/*40*/
#endif
	error_meanings[ELOOP]=make_pair("ELOOP","Too many symbolic links encountered.");
#ifndef ENOMSG
#define ENOMSG 42
#endif
	error_meanings[ENOMSG]=make_pair("ENOMSG","No message of desired type.");
#ifndef EIDRM
#define EIDRM 43
#endif
	error_meanings[EIDRM]=make_pair("EIDRM","Identifier removed.");
#ifndef ECHRNG
#define ECHRNG 44
#endif
	error_meanings[ECHRNG]=make_pair("ECHRNG","Channel number out of range.");
#ifndef EL2NSYCN
#define EL2NSYCN 45
#endif
	error_meanings[EL2NSYCN]=make_pair("EL2NSYCN","Level 2 not synchronized.");
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
#ifndef ELOOP
#define ELOOP 114/*40*/
#endif
	error_meanings[ELOOP]=make_pair("ELOOP","Too many symbolic links encountered.");
#ifndef ELOOP
#define ELOOP 114/*40*/
#endif
	error_meanings[ELOOP]=make_pair("ELOOP","Too many symbolic links encountered.");
#ifndef ELOOP
#define ELOOP 114/*40*/
#endif
	error_meanings[ELOOP]=make_pair("ELOOP","Too many symbolic links encountered.");
#ifndef ELOOP
#define ELOOP 114/*40*/
#endif
	error_meanings[ELOOP]=make_pair("ELOOP","Too many symbolic links encountered.");
#ifndef ELOOP
#define ELOOP 114/*40*/
#endif
	error_meanings[ELOOP]=make_pair("ELOOP","Too many symbolic links encountered.");
	error_meanings[EIO]=make_pair("EIO","error.");
	
}

struct error_handle_node
{
	int id;
	string name;
	string description;
	error_handle_node* next;
	void init()
	{
		set(0/*NO_ERROR*/);
		return;
	}
	bool set(int error_id)
	{
		error_meanings_init();
		map<int,pair<string,string> >::iterator it=error_meanings.find(error_id);
		if(it==error_meanings.end())
			return 0;
		pair<string,string> information=error_meanings[i];
		id=error_id;
		name=information.first;
		description=information.second;
		return 1;
	}
};

struct error_handle
{
	error_handle_node* head;
	void init()
	{
		head=NULL;
		create();
		return;
	}
	void create()
	{
		head=new error_handle_node;
		head.init(0);
	}
	void del()
	{
		error_handle_node* p=head;
		error_handle_node* q=p;
		while(p!=NULL)
		{
			p.set(0);
			p=p->next;
			delete q;
			q=p;
		}
		return;
	}
};

#endif

