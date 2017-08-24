#include <stdio.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>

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

	//fd与通信地址绑定
	int ret = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("bind");
		return -1;
	}
	

	for(;;)
	{
		static int flag = 1;
		char buf[1024] = {};
		ret = read(sockfd,buf,sizeof(buf));
		if(0 > ret)
		{
			perror("read");
			return -1;
		}
		if('!' == buf[0])
		{
			printf("客户端退出，通信结束\n");
			break;
		}
		printf("客户端发来消息：%s\n",buf);
	}
		//关闭
		close(sockfd);
		unlink("/tmp/sock5");
}
