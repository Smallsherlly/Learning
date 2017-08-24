#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	int i=0;
	for(;;i++)
	{
		printf("*\n");
		if(i==3)
		{
			raise(SIGSEGV);
		}
	}
	
}
