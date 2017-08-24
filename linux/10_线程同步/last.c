#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//仓库的最大容量
#define MAX_STOCK 15

//定义一个仓库
char depot[MAX_STOCK];

//当前仓库数据的数量
volatile size_t stock;

//定义互斥量
pthread_mutex_t mute = PTHREAD_MUTEX_INITIALIZER;

//定义仓库满的条件变量
pthread_cond_t c_full = PTHREAD_COND_INITIALIZER;

//定义仓库空的条件变量
pthread_cond_t c_empty = PTHREAD_COND_INITIALIZER;

//显示仓库中的数据
void show_depot(char* str)
{
	int i = 0;
	printf("\r");
	for(; i<stock; i++)
	{
		printf("%c ",depot[i]);
	}
	printf("%s",str);
	fflush(stdout);
}

//生产数据的线程函数
void* in_func_pro(void* arg)
{
	for(;;)
	{
		//访问仓库前加锁
		pthread_mutex_lock(&mute);

		//如果仓库已满，则暂停,并且解锁
		if(stock >= MAX_STOCK)
		{
			pthread_cond_wait(&c_full,&mute);
		}

		//生产数据
		depot[stock++] = 'A' + rand() % 26;
		
		//显示仓库中的数据
		show_depot("->");
		usleep(rand()%100*1000);
//		sleep(1);		
		//此时仓库中至少有一个数据，可以唤醒消费者了
		pthread_cond_signal(&c_empty);
			
		//解锁
		pthread_mutex_unlock(&mute);

	}
}

//消费数据的线程函数
void* in_func_use(void* arg)
{
	for(;;)
	{
		//访问仓库前加锁
		pthread_mutex_lock(&mute);

		//如果仓库已满，则暂停,并且解锁
		if(stock <= 0)
		{
			pthread_cond_wait(&c_empty,&mute);
		}

		//生产数据
		stock--;
		//显示仓库中的数据
		show_depot("<-");
		usleep(rand()%100*500);
		sleep(1);		
		//此时仓库中至少有一个数据空位，可以唤醒消费者了
		pthread_cond_signal(&c_full);
			
		//解锁
		pthread_mutex_unlock(&mute);

	}

}

int main()
{
	//种植随机种子
	srand(time(NULL));

	//定义线程id
	pthread_t pth_id1,pth_id2;
	
	//创建生产数据线程
	pthread_create(&pth_id1,NULL,in_func_pro,NULL);
	//创建消费数据线程
	pthread_create(&pth_id2,NULL,in_func_use,NULL);

	//把子线程与主线程分离
	pthread_detach(pth_id1);
	pthread_detach(pth_id2);

	//主线程暂停
	scanf("%*c");
	
}
