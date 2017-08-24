#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main()
{
	int sec = 10;
	printf("我将在%d秒后结束\n",sec);
	alarm(sec);
	
	sleep(2);
	sec = alarm(sec+10);
	printf("我将延时10秒,上次的定时还剩%d秒",sec);
	for(;;)
	{
		printf("$\n");
		sleep(1);
	}
}
