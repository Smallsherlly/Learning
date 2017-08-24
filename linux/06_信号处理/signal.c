#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	//一般写在初始化部分
	signal(2,SIG_IGN);
	for(;;)
	{
		sleep(1);
		printf("-\n");
	}

}
