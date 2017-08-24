#include <stdio.h>
#include <pthread.h>

unsigned int num = 0;
//创建胡吃两
pthread_mutex_t mutex;

void* in_func(void* arg)
{
	int i = 0;
	for(; i<1000000000; i++)
	{
		//为胡吃两加锁
		pthread_mutex_lock(&mutex);
		num++;
		//为胡吃两解锁
		pthread_mutex_unlock(&mutex);
	}
	
}

int main()
{

	//初始化胡吃两
	pthread_mutex_init(&mutex,NULL);

	pthread_t pth_id[2] = {};

	pthread_create(&pth_id[0],NULL,in_func,NULL);
	pthread_create(&pth_id[1],NULL,in_func,NULL);

	pthread_join(pth_id[0],NULL);
	pthread_join(pth_id[1],NULL);

	printf("num = %u \n",num);

	//销毁互斥量
	pthread_mutex_destroy(&mutex);
}
