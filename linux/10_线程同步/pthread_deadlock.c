#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_b = PTHREAD_MUTEX_INITIALIZER;

void* in_func1(void* arg)
{
	pthread_t pth_id = pthread_self();
	printf("线程%lu，准备加锁b\n",pth_id);
	pthread_mutex_lock(&mutex_b);
	printf("线程%lu，加锁b成功\n",pth_id);
	
	sleep(1);

	printf("线程%lu，准备加锁a\n",pth_id);
	pthread_mutex_lock(&mutex_a);
	printf("线程%lu，加锁a成功\n",pth_id);
}

void* in_func2(void* arg)
{
	pthread_t pth_id = pthread_self();
	printf("线程%lu，准备加锁a\n",pth_id);
	pthread_mutex_lock(&mutex_a);
	printf("线程%lu，加锁a成功\n",pth_id);
	
	sleep(1);
	
	printf("线程%lu，准备加锁b\n",pth_id);
	pthread_mutex_lock(&mutex_b);
	printf("线程%lu，加锁b成功\n",pth_id);
}

int main()
{
	pthread_t pth_id1,pth_id2;

	pthread_create(&pth_id1,NULL,in_func1,NULL);
	pthread_create(&pth_id2,NULL,in_func2,NULL);

	pthread_join(pth_id1,NULL);
	pthread_join(pth_id2,NULL);

	pthread_mutex_destroy(&mutex_a);
	pthread_mutex_destroy(&mutex_b);
	
}
