#include <stdio.h>
#include <pthread.h>

pthread_t main_id = 0;

void func(void)
{
	//判定是谁在调用此函数
	printf("--------");
	pthread_t fun_id = 0;
	fun_id = pthread_self();
	if(fun_id == main_id)
	{
		printf("主线程在调用此函数\n");
	}
	else
	{
		printf("子线程在调用此函数\n");

	}
}

void* in_func(void* arg)
{
	func();
}

int main()
{
	//获取主线程的ID
	main_id = pthread_self();
	pthread_t pth_id = 0;
	
	int ret = pthread_create(&pth_id,NULL,in_func,NULL);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;
	}

	func();

	pthread_join(pth_id,NULL);
}
