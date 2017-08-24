#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char** argv[])
{
	//创建socket
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备通信地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//本机地址

	//连接
	int ret = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("connect");
		return -1;
	}

	//发送
	for(;;)
	{
		char buf[1024] = {};
		printf("告诉服务器：");
		scanf("%s",buf);

		ret = write(sockfd,buf,strlen(buf));
		if(0 > ret)
		{
			perror("write");
			return -1;
		}

		if('!' == buf[0])
		{
			close(sockfd);
			printf("通信结束!\n");
			return 0;
		}
	}
	
}

