#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;//用于接收文件描述符的变量

	fd = open("note.c",O_RDWR,0666);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	printf("文件打开成功！\n");

	int ret = close(fd);

	if(0 == ret)
	{
		printf("关闭文件成功！\n");
		return 0;
	}
	return -1;
}
