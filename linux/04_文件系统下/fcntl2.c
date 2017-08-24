#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int wlock(int fd,size_t len,int wait)
{
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = len;
	lock.l_pid = -1;

	if(0 == fcntl(fd,wait?F_SETLKW:F_SETLK,&lock))
	{
		printf("加锁成功！\n");
		return 0;
	}
	else
	{
		printf("加锁失败！\n");
		return -1;
	}
}

int main()
{
	int fd = open("fcntl.bin",O_WRONLY|O_CREAT);
	
	wlock(fd,20,0);
	scanf("%*c");

	return 0;
}

