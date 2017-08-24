#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sig_alarm(int signum)
{
	printf("*\n");
}

void sig_int(int signum)
{
	static struct itimerval new_it = {};
	static struct itimerval old_it = {};
	setitimer(ITIMER_REAL,&new_it,&old_it);
	new_it = old_it;
}


int main()
{
	signal(SIGALRM,sig_alarm);
	signal(SIGINT,sig_int);

	struct itimerval it = {{0,500000},{3,0}};
	printf("%ld秒后开始发送时钟信号\n",it.it_value.tv_sec);

	setitimer(ITIMER_REAL,&it,NULL);
	for(;;)pause();
}
