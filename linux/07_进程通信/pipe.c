#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>



int main()
{
	//获取管道文件描述符,0读，1写
	int fd_pipe[2] = {};
	int ret = pipe(fd_pipe);
	if(0 > ret)
	{
		perror("pipe");
		return -1;
	}
	//创建子进程
	if(0 == fork())
	{
		//子进程关闭写端，读取数据
		close(fd_pipe[1]);
		for(;;)
		{
			char buf[255] = {};
			int ret = read(fd_pipe[0],buf,sizeof(buf));
			if(0 == ret)
			{
				printf("通信结束\n");
				break;
			}
			if(0 > ret)
			{
				perror("read");
				return -1;
			}
			printf("从父进程读取到:%s 共%d字节\n",buf,ret);
		}
		//关闭管道文件描述符
		close(fd_pipe[0]);
	}
	else
	{
		//父进程关闭读端，发送数据
		close(fd_pipe[0]);
		for(;;)
		{
			char buf[255] = {};
			sleep(1);
			printf("zzxx#");
			scanf("%s",buf);
			if('q' == buf[0])
			{
				printf("通信结束\n");
				break;
			}
			int ret = write(fd_pipe[1],buf,strlen(buf));
			printf("向子进程发送了%d字节\n",ret);
		}
		//关闭管道文件描述符
		close(fd_pipe[1]);
	}
}
