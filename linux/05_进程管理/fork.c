#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("我要创建进程了！\n");
	if(0 == fork())
	{
		printf("我是子进程：%u我的父进程是：%u\n",getpid(),getppid());
	}
	else
	{
		printf("我是父进程:%u\n",getpid());
	}

	printf("hello world\n");
	return 0;
}
