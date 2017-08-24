#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


int sockfd = 0;
int ret = 0;
int inum2 = 0;
void* in_func(void* arg)
{
	int inum = inum2++;
	int fd = *(int*)arg;
	while(1)
	{
		
		//接收请求
		char buf[1024] = {};

		ret = recv(fd,buf,sizeof(buf),0);
		if(0 >= ret)
		{
			perror("recv");
			pthread_exit(NULL);
		}


		if('!' == buf[0])
		{
			close(fd);
			close(sockfd);
			printf("与客户端%d的通信结束\n",inum);
			pthread_exit(NULL);
		}
		printf("客户端%d说：%s\n",inum,buf);
		printf("告诉客户端%d：",inum);
		scanf("%s",buf);
		
		
		//响应请求
		ret = send(fd,buf,strlen(buf)+1,0);
		if(0 > ret)
		{	
			perror("send");
			pthread_exit(NULL);

		}
	}
}
int main()
{

	pthread_t inum = 0;
	//创建sockfd
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备连接地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10087);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	//绑定sockfd和通信地址
	ret = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
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
	inum = 0;
	for(;;inum++)
	{
		
		int fd = accept(sockfd,(struct sockaddr*)&addr,&len);
		if(0 >= fd)
		{
			perror("accept");
			return -1;
		}
		int ret = pthread_create(&inum,NULL,in_func,&fd);
		if(0 > ret)
		{
			perror("pthread_create");
			return -1;
		}
		
		
			
		
	}

	
}
