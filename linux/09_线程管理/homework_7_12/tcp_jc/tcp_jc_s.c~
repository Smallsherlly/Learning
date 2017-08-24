#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	//创建sockfd
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备连接地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10000);
	addr.sin_addr.s_addr = inet_addr("192.168.0.102");


	//绑定sockfd和通信地址
	int ret = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("bind");
		return -1;
	}

	//监听
	ret = listen(sockfd,50);
	if(0 > ret)
	{
		perror("listen");
		return -1;
	}

	//等待连接,接收不到连接会阻塞
	socklen_t len = sizeof(addr);
	int inum = 0;
	for(;;inum++)
	{
		
		int fd = accept(sockfd,(struct sockaddr*)&addr,&len);
		printf("sockfd = %d\n",sockfd);
		printf("fd = %d\n",fd);
		printf("port:%u\n",ntohs(addr.sin_port));
		if(0 >= fd)
		{
			perror("accept");
			return -1;
		}
		if(0 == fork())
		{
			while(1)
			{
				static int x = 0;
				//接收请求
				char buf[1024] = {};

				ret = recv(fd,buf,sizeof(buf),0);
				if(0 >= ret)
				{
					perror("recv");
					exit(0);
				}
		
				if('!' == buf[0])
				{
					close(fd);
					close(sockfd);
					printf("与客户端%d的通信结束\n",inum);
					exit(0);
				}
				printf("%d\n",x++);
				printf("客户端%d说：%s\n",inum,buf);
				printf("告诉客户端%d：",inum);
				scanf("%s",buf);
				
				//响应请求
				ret = send(fd,buf,strlen(buf)+1,0);
				if(0 > ret)
				{	
					perror("send");
					exit(0);

				}
			}
		}
		
	}

	
}
