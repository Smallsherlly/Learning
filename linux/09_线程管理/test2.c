#include <stdio.h>
#include <pthread.h>

void in_func(void* arg)
{
	printf("我是子线程：%u\n",pthread_self());
}
