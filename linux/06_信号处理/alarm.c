#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main()
{
	int sec = 10;
	printf("我将在十秒后结束\n");
	alarm(10);
	for(;;)
	{
		printf("*\n");
		sleep(1);
	}
	
	return 0;	
}

