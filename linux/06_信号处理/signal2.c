#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_func(int signum)
{
	printf("我是进程%u，我捕获到信号%d\n",getpid(),signum);

}

int main()
{
	signal(SIGINT,sig_func);
	if(0 == fork())
	{
		printf("我是子进程：%u\n ",getpid());
		for(;;)
		{
			printf("*\n");
			sleep(1);
		}
	}
	else
	{
		printf("我是父进程：%u\n",getpid());
		for(;;)
		{
			printf("#\n");
			sleep(1);
		}
	}
}
