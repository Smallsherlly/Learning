#include <stdio.h>
#include <unistd.h>


int main()
{
	void* end = sbrk(0);

	brk(end+4);//分配4字节
	printf("%d\n",*(int*)end);

	brk(end);//释放内存
}
