#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

//此函数有线程库的pthread保护
void* in_func(void* arg)
{
	printf("使用主线程传递的参数：%d\n",*(int*)arg);
	*(int*)arg = 32767;
	sleep(1);
	static char str[] = "我是悲伤的子线程！";
	return str;
}

int main()
{
	//用来获取子线程的id
	pthread_t pth_id = 0;
	//传递给子线程的数据
	int num = 65536;
	//创建子线程
	int ret = pthread_create(&pth_id,NULL,in_func,&num);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;
	}

	//用来获取子线程的返回值
	//此指针要跨函数共享，因此要传递的是它的地址
	char* str_p;
	//可以等待指定的线程结束，并获取线程的返回值
	pthread_join(pth_id,(void**)&str_p);
	
	printf("子线程已经结束，遗言是%s\n",str_p);
	printf("被子线程修改过的数据：%d\n",num);
}
