#include <stdio.h>
#include <limits.h>

//获取文件大小的函数
long fsize(const char* path)
{
	FILE* frp = fopen(path,"r");
	if(NULL == frp) return -1;

	fseek(frp,0,SEEK_END);
	long size = ftell(frp);

	fclose(frp);

	return size;
}

int main()
{
	char path[PATH_MAX] = {};
	printf("请输入一个文件的路径：");
	scanf("%s",path);
	long size = fsize(path);
	if(size < 0)
	{
		printf("获取文件大小失败");
		return -1;
	}

	printf("文件大小是%ld字节\n",size);
	return 0;
}
