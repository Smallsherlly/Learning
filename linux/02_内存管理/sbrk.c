#include <stdio.h>
#include <unistd.h>

int main()
{
	int* p = sbrk(0);//首次分配会映射1页
	sbrk(4);//分配四个字节
	p[0] = 10086;
	printf("%d\n",p[0]);
	sbrk(-4);//释放内存
	
	return 0;
}
