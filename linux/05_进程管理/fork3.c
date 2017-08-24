#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	if(0 == fork())
	{
		sleep(20);
		printf("我是子进程：%u,%u,我即将变成僵尸\n",getpid(),getppid());
		return 0;

	}
	else
	{
		printf("我是父进程：%u\n",getpid());
	}
	return 0;	
}
