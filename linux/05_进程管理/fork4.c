#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = open("fork.bin",O_WRONLY|O_CREAT,0644);
	if(0 > fd)
	{
		perror("open");
		return -1;
	}
	int id = fork();
	if(0 == id)
	{
		char buf[255] = {};
		sprintf(buf,"我是子进程：%u，我的父进程是：%u\n",getpid(),getppid());
		write(fd,buf,strlen(buf));
	}
	else
	{
		sleep(1);
		char buf[255] = {};
		sprintf(buf,"我是父进程：%u，我的子进程是：%u\n",getpid(),id);
		write(fd,buf,strlen(buf));
	}
	close(fd);
	return 0;	
}
