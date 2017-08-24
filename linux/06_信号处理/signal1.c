#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ctrl_c(int signum)
{
	printf("你小子居然敢按Ctrl+c，但我就是不死！\n");

}

int main()
{
	signal(SIGINT,ctrl_c);

	for(;;)
	{
		sleep(1);
		printf("*\n");
	}
	
}
