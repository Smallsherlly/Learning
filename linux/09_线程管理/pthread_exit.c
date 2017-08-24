#include <stdio.h>
#include <malloc.h>
#include <pthread.h>

#define PI 3.1415926
void* in_func(void* arg)
{
	double* rst_p = malloc(sizeof(double));
	*rst_p = PI * *(int*)arg * *(int*)arg;
	pthread_exit(rst_p);
	printf("------------\n");
	return rst_p;
}

int main()
{
	pthread_t pth_id = 0;
	int r = 10;
	int ret = pthread_create(&pth_id,NULL,in_func,&r);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;
	}
	double* rst_p;
	ret = pthread_join(pth_id,(void**)&rst_p);
	printf("线程结束，圆的面积是%g\n",*rst_p);
	//释放堆内存
	free(rst_p);
}
