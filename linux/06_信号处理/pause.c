#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_func(int signum)
{

}
int main()
{
	printf("进程%u即将进入睡眠...\n",getpid());
	signal(SIGINT,sig_func);
	int ret = pause();
	printf("被唤醒%d\n",ret);
	
	return 0;	
}
