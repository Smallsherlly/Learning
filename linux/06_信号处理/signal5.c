#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void sig_func(int signum)
{
	sleep(3);
}

int main ()
{
	signal(SIGINT,sig_func);
	for(;;)
	{
		printf("#\n");
		sleep(1);
	}
}
