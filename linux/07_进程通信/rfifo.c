#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define FILE_FIFO "/tmp/fifo"

int main()
{
	//打开管道文件
	int fd = open(FILE_FIFO,O_RDONLY);
	if(0 > fd)
	{
		perror("open");
		return -1;
	}
	//从管道中读数据
	for(;;)
	{
		char buf[255] = {};
		int ret = read(fd,buf,sizeof(buf));
		if(ret == 0)
		{
			printf("通信结束\n");
			break;
		}
		if(0 > ret)
		{
			perror("read");
			return -1;
		}
		printf("接收到:%s 共%d个字节\n",buf,ret);
	}
	//关闭管道文件
	close(fd);
	printf("通信完成\n");
}
