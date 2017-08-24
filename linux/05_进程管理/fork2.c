#include <stdio.h>
#include <sys/types.h>

int main()
{
	int pid = fork();

	if(0 == pid)
	{
		while(1)
		{
			printf("*");
			fflush(stdout);
			sleep(1);
		}
	}
	else
	{
		while(2)
		{
			printf("#");
			fflush(stdout);
			sleep(1);
		}
	}
	
	return 0;
}
