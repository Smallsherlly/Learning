#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


unsigned int num = 0;
//定义信号量
sem_t sem;

void* in_func(void* arg)
{
	int i = 0;
	for(; i<1000000000; i++)
	{
		//减信号量，如果不能减则阻塞
		sem_wait(&sem);
		num++;

		//加信号量
		sem_post(&sem);
	}
	
}

int main()
{


	pthread_t pth_id[2] = {};
	
	//初始化信号量
	int ret = sem_init(&sem,0,1);

	pthread_create(&pth_id[0],NULL,in_func,NULL);
	pthread_create(&pth_id[1],NULL,in_func,NULL);

	pthread_join(pth_id[0],NULL);
	pthread_join(pth_id[1],NULL);

	printf("num = %u \n",num);

	//销毁信号量
	sem_destroy(&sem);

}
