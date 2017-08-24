#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

typedef struct sockaddr* SP;
typedef struct sockaddr_in SA;
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

int main()
{
	srand(time(NULL));
	
	int fd_s = create_sockfd();
	SA send_addr;
	send_addr.sin_family = AF_INET;
	send_addr.sin_port = htons(18899);
	//send_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	SA recv_addr = send_addr;
	recv_addr.sin_port = htons(rand()%30000+1024);
printf("----%u------\n",ntohs(recv_addr.sin_port));
	int fd_c = create_sockfd();
	int ret = bind(fd_c,(SP)&recv_addr,sizeof(recv_addr));
	if(0 > ret)
	{
		perror("bind");
		exit(-1);
	}

	sendto(fd_s,&recv_addr,sizeof(recv_addr),0,(SP)&send_addr,sizeof(send_addr));


	for(;;)
	{
		char buf[1024] = {};
		socklen_t len = sizeof(recv_addr);
		recvfrom(fd_c,buf,sizeof(buf),0,(SP)&recv_addr,&len);
		printf("接收到数据%s\n",buf);
		printf("发送给服务器：");
		scanf("%s",buf);
		sendto(fd_c,buf,strlen(buf)+1,0,(SP)&recv_addr,sizeof(recv_addr));
		sleep(1);
	}
}
