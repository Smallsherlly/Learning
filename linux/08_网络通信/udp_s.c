#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef struct sockaddr* SP;
int main()
{
	//创建sockfd
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备通信地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10010);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//绑定sockfd与通信地址
	int ret = bind(sockfd,(SP)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("bind");
		return -1;
	}

	for(;;)
	{
		char buf[1024] = {};
		struct sockaddr_in cliaddr = {};
		socklen_t len = sizeof(cliaddr);
		//接收请求
		ret = recvfrom(sockfd,buf,sizeof(buf),0,(SP)&cliaddr,&len);

		if(0 >= ret)
		{
			perror("recvfrom");
			return -1;
		}

		if('!' == buf[0])
		{
			close(sockfd);
			printf("通信结束！\n");
			return 0;
		}
		printf("ip:%s port:%u %s\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port),buf);
		printf("告诉客户端:");
		scanf("%s",buf);
		//响应请求
		ret = sendto(sockfd,buf,strlen(buf)+1,0,(SP)&cliaddr,len);
		if(0 >= ret)
		{
			perror("sendto");
			return -1;
		}
	//
	}
}
