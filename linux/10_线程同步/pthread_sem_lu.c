#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


unsigned int num = 0;
//定义信号量
sem_t sem;

void* in_func(void* arg)
{
	pthread_t id = *(pthread_t*)arg;
	while(1){
	//减信号量，如果不能减则阻塞
	sem_wait(&sem);
	printf("我%lu骑走了一头驴\n",id);
	sleep(3);
	//加信号量
	sem_post(&sem);
	}
	
}

int main()
{


	pthread_t pth_id[10] = {};
	
	//初始化信号量
	int ret = sem_init(&sem,0,5);
	int i = 0;
	for(; i<10; i++)
	{
		pthread_create(&pth_id[i],NULL,in_func,&pth_id[i]);
	}
	i = 0;
	for(; i<10; i++)
	{
		pthread_join(pth_id[i],NULL);
	}
	
	//销毁信号量
	sem_destroy(&sem);
}
