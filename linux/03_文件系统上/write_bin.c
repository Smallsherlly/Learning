#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	//创建文件
	int fd = open("data.bin",O_RDWR|O_CREAT|O_TRUNC,0666);
	if(0 > fd)
	{
		perror("open");
		return -1;
	}

	struct Student
	{
		char name[20];
		char sex;
		short age;
	} zhaoyun = {"赵云",'m',88};


	int ret = write(fd,&zhaoyun,sizeof(zhaoyun));
	if(0 > ret)
	{
		perror("write");
		return -1;
	}
	
	printf("希望写入%d字节，实际写入%d字节\n",sizeof(zhaoyun),ret);
	
	ret = close(fd);
	if(0 > ret)
	{
		perror("close");
		return -1;
	}
	
	printf("关闭文件成功！\n");
	return 0;
}
