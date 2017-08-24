#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("我是进程：%u 我的父进程是:%u\n",getpid(),getppid());
	printf("实际用户ID:%u\n",getuid());
	printf("有效用户ID:%u\n",geteuid());
	printf("实际组ID:%u\n",getgid());
	printf("有效组ID:%u\n",getegid());
	return 0;	
}
