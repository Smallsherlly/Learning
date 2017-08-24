#include <stdio.h>
#include <sys/types.h>
#include <sys/un.h>
#include <string.h>
#include <sys/socket.h>

int main()
{
	//创建socket
	int sockfd = socket(AF_LOCAL,SOCK_DGRAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备通信地址
	struct sockaddr_un addr = {AF_LOCAL,"/tmp/sock5"};

	//连接服务器
	int ret = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("connect");
		return -1;
	}
	

	printf("连接服务器成功!\n");
	for(;;)
	{
		char buf[1024] = {};
		printf("告诉服务器：");
		scanf("%s",buf);

		ret = write(sockfd,buf,strlen(buf)+1);
		if(0 >= ret)
		{
			perror("write");
			return -1;
		}
		
		if('!' == buf[0])
		{
			puts("通信结束");
			return 0;
		}
	}
	
}
