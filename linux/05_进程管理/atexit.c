#include <stdio.h>
#include <unistd.h>

void words(void)
{
	printf("同一个世界，同一个梦想\n");
}

int main()
{
	//向系统注册一个函数，程序结束时调用一下
	//int atexit(void (*func)(void));
	//防止程序意外结束，用来保存数据
	//但不能防止异常信号
	int ret = atexit(words);
	if(0 == ret)
	{
		printf("函数注册成功\n");
	}
	else
	{
		printf("函数注册失败\n");
	}

	return 0;
}
