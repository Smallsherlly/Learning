#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void sig_func(int signum)
{
	printf("信号%d触发了\n",signum);
	sleep(3);
	printf("信号处理完毕\n");
}

int main()
{
	struct sigaction act = {};
	act.sa_handler = sig_func;
	sigaddset(&act.sa_mask,SIGINT);

	sigaction(SIGINT,&act,NULL);
	for(;;)
	{
		printf("*\n");
		sleep(1);
	}
	
}
