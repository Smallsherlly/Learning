#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sig_alarm(int signum)
{
	static	int time = 0;
	time = time+1;
	printf("\r%d秒 %d毫秒",time/1000,time%1000);
	printf("\033[5;15H");	
//	system("clear");
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
	struct itimerval it = {{0,1000},{1,0}};
	setitimer(ITIMER_REAL,&it,NULL);

	for(;;)
	{
		pause();
	}
}
