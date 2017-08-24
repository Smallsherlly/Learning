#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void* in_func(void* arg)
{
	strcat(arg,"我是子线程，我用了一下这个数据");
	for(;;)
	{
		printf("%s\n",(char*)arg);
		sleep(1);
	}
}

int main()
{
	pthread_t pth_id = 0;
	char str[255] = "我是主线程的数据";
	int ret = pthread_create(&pth_id,NULL,in_func,str);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;
	}

	printf("我有一个子线程，我要等她\n");
	sleep(3);
	printf("%s\n",str);	
}
