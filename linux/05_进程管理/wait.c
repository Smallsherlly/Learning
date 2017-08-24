#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
	int id = -1;
	int i = 0;
	for(; i<3; i++)
	{
		if(id != 0)
		{
			id = fork();
		}
	}

	if(0 == id)
	{
		printf("我是子进程%u\n",getpid());
		sleep(3);
		return 110;
	}
	else
	{
		printf("我是父进程，我要回收子进程了\n");
		
		int stats = 0;
		pid_t pid = wait(&stats);
		printf("我的子进程：%u stats：%d\n",pid,stats);
	}
}
