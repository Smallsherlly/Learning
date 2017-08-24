#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

typedef struct sockaddr_in SA;
typedef struct sockaddr* SP;
int create_sockfd(void)
{
	int fd = socket(AF_INET,SOCK_DGRAM,0);
	if(0 >= fd)
	{
		perror("sockfd");
		return -1;
	}

	return fd;
}

void server(SA send_addr)
{
	int fd_c = create_sockfd();
	
	for(;;)
	{
		char buf[1024] = {};
		sprintf(buf,"我是线程：%u为您服务",getpid());
		sendto(fd_c,buf,strlen(buf)+1,0,(SP)&send_addr,sizeof(send_addr));

		socklen_t len = sizeof(send_addr);
		recvfrom(fd_c,buf,sizeof(buf),0,(SP)&send_addr,&len);
		printf("进程：%u 接收到数据:%s\n",getpid(),buf);
		sleep(1);
	}
}

int main()
{
	int fd_s = create_sockfd();

	SA recv_addr;
	recv_addr.sin_family = AF_INET;
	recv_addr.sin_port = htons(17777);
	recv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = bind(fd_s,(SP)&recv_addr,sizeof(recv_addr));
	if(0 > ret) 
	{
		perror("bind");
		exit(-1);
	}
	for(;;)
	{	
		printf("----------------\n");
		SA send_addr; 
		recvfrom(fd_s,&send_addr,sizeof(send_addr),0,NULL,NULL);

		if(0 == fork())
		{
			server(send_addr);
		}
	}
}
