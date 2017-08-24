#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(int argc,char** argv[])
{
	//创建socket
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备通信地址,127.0.0.1是特殊地址，但有时会被禁止使用
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//绑定通信地址和sock
	int ret = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("bind");
		return -1;
	}

	//接收消息
	for(;;)
	{
		char buf[1024] = {};
		ret = read(sockfd,buf,sizeof(buf));
		if(0 >= ret)
		{
			perror("read");
			return -1;
		}	
		printf("接收到消息:%s\n",buf);	
		//关闭socket
		if('!' == buf[0])
		{
			close(sockfd);
			printf("通信结束\n");
			return 0;
		}
	}
	
}
