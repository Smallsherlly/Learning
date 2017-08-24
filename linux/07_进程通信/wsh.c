#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main()
{
	//创建key
	key_t key = ftok("..",144);
	printf("创建key值为%u\n",key);
	//创建共享内存
	int shid = shmget(key,255,0664|IPC_CREAT);
	if(0 > shid)
	{
		perror("shmget");
		return -1;
	}
	//加载共享内存
	char* buf = shmat(shid,NULL,0);
	if(NULL == buf)
	{
		perror("shmat");
		return -1;
	}
	//使用共享内存
	sprintf(buf,"你好，我是进程%u\n",getpid());
	scanf("%*c");
	//卸载共享内存
	int ret = shmdt(buf);
	if(0 > ret)
	{
		perror("shmdt");
		return -1;
	}
	//销毁共享内存
	ret = shmctl(shid,IPC_RMID,NULL);
	if(0 > ret)
	{
		perror("ret");
		return -1;

	}
	
}
