#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{	
	//创建key
	key_t key = ftok("..",144);
	//获取共享内存id
	int shid = shmget(key,255,0);
	if(0 > shid)
	{
		perror("shid");
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
	printf("从共享内存中读取到%s\n",buf);
	//卸载共享内存
	int ret = shmdt(buf);
	if(0 > ret)
	{
		perror("shmdt");
		return -1;
	}
	//销毁共享内存

}
