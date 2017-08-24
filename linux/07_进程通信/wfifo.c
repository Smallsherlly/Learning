#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE_FIFO  "/tmp/fifo"


int main()
{
	//创建管道
	int ret = mkfifo(FILE_FIFO,0644);
	if(0 > ret)
	{
		perror("mkfifo");
		return -1;
	}
	//打开管道
	int fd = open(FILE_FIFO,O_WRONLY);
	if(0 > fd)
	{
		perror("open");
		return -1;
	}
	//向管道中写数据
	for(;;)
	{
		char buf[255] = {};
		printf(">>");
		gets(buf);
		if('q' == buf[0])
		{
			printf("退出通信\n");
			break;
		}
		int ret = write(fd,buf,strlen(buf));
		printf("发送了%d字节到管道\n",ret);
	}
	//关闭管道
	close(fd);
	//删除管道
	unlink(FILE_FIFO);

	printf("完成通信\n");
}
