#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>


int main()
{
	//创建key
	key_t key = ftok(".",168);

	//获取信号量
	int semid = semget(key,0,0);

	//操作信号量
	for(;;)
	{
		struct sembuf sem = {0,-1,IPC_NOWAIT};
		int ret = semop(semid,&sem,1);
		if(0 == ret)
		{
			printf("我骑了一头驴\n");
		}
		else if(0 > ret)
		{
			perror("semop");
			break;
		}
		sleep(1);
	}
}
