#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* in_func(void* arg)
{
	for(;;)
	{
		printf("\n");
		sleep(1);
	}
}

int main()
{
	pthread_t pth_id = 0;
	int ret = pthread_create(&pth_id,NULL,in_func,NULL);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;

	}
	//使用它结束线程，资源不会被释放
	//pthread_exit(NULL);
	
	//子现场与主线程分离，无法用join等待，自动释放
	pthread_detach(pth_id);

	//等待子线程退出
	pthread_join(pth_id,NULL);
	printf("-----");
	sleep(10);
}
