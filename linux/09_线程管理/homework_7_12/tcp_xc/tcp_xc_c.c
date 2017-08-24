#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	//创建sockfd
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备通信地址，目标机器的地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10087);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	//使用通信地址，连接到目标机器
	int ret = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("connect");
		return -1;
	}

	for(;;)
	{
		char buf[1024] = {};
		printf("告诉服务器：");
		scanf("%s",buf);

		//发送请求
		ret = send(sockfd,buf,strlen(buf)+1,0);
		if(0 > ret)
		{		
			perror("send");
			return -1;
		}

		if('!' == buf[0])
		{
			close(sockfd);
			printf("通信结束！\n");
			return 0;
		}
		
		//接收响应
		ret = recv(sockfd,buf,sizeof(buf),0);
		if(0 >= ret)
		{
			perror("recv");
			return -1;
		}
		printf("服务器返回：%s\n",buf);

	}
}
