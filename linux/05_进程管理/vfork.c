#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	int id = vfork();
	if(0 == id)
	{
		execl("/home/ubuntu/hello","hello",NULL);
	}
	else
	{
		printf("我是父进程\n");	
	}
	return 0;
}
