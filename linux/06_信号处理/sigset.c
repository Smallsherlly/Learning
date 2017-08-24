#include <stdio.h>
#include <signal.h>
#include <unistd.h>



int main()
{
	sigset_t set;
	sigemptyset(&set);

	sigaddset(&set,SIGINT);

	if(1 == sigismember(&set,SIGINT))
	{
		printf("信号集中存在SIGINT信号\n");
	}
	else
	{
		printf("信号集中不存在SIGINT信号\n");
	}
	
}
