#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_func(int signum)
{
	printf("信号%d来了\n",signum);
}

int main()
{
	signal(SIGINT,sig_func);
	int sec = 10;

	do
	{
		sec = sleep(sec);
		printf("还剩%d秒没睡\n",sec);
	}
	while(sec > 0);
}
