#include <stdio.h>
#include <sys/mman.h>

int main()
{
	//分配内存
	int* p = mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,0,0);
	if(NULL == p)
	{
		puts("内存分配失败！");
		return -1;
	}
	*p = 10010;
	printf("*p = %d\n",*p);
	//释放内存
	munmap(p,4);
	return 0;
}
