#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	if(0 == fork())
	{
		printf("我是子进程:%u,我要给父进程发送信号了\n",getpid());
		sleep(3);
		int pid = 0 - getppid();
		kill(pid,SIGINT);
		for(;;)
		{
			sleep(1);
			printf("*\n");
		}
	}
	else
	{
		for(;;)
		{
			sleep(1);
			printf("我是父进程%u\n",getpid());
		}
	}
	return 0;	
}
