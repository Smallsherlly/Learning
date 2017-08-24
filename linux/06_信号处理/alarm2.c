#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main()
{
	alarm(10);
	printf("我将在10秒后结束\n");

	alarm(0);

	for(;;)
	{
		printf("*\n");
		sleep(1);

	}
}
