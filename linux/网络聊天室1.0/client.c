#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

typedef struct sockaddr* SP;
typedef struct sockaddr_in SA;


typedef struct msg
{
	int msg_num;
	char msg[20][255];
}MSG;


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
MSG msg;
SA send_addr;
char user_name[20] = {};
char buf[255] = {};
char getin[255] = {};
int fd_c = 0;
int flag = -1;
socklen_t len = sizeof(send_addr);

void* recv_func(void* arg)
{
	int i = 0;
	char str[255] = {};
	while(1)
	{//与服务器线程建立连接
		recvfrom(fd_c,&msg,sizeof(MSG),0,(SP)&send_addr,&len);
		system("clear");
		printf("%s\n",getin);
		for(i=0; i<msg.msg_num; i++)
		{
			printf("%s",msg.msg[i]);
		}
		printf("\n--------------\n");
		printf("%s:",user_name);
		fflush(stdout);
	}
		
}

void* inp_func(void* arg)
{
	char str[255] = {};
	while(1)
	{
			usleep(200000);
			gets(buf);
			sprintf(str,"%s:%s",user_name,buf);
			sendto(fd_c,str,strlen(str)+1,0,(SP)&send_addr,len);
	

	}
}

int main()
{
	srand(time(NULL));
	
	//服务端通信地址
	
	send_addr.sin_family = AF_INET;
	send_addr.sin_port = htons(12345);
	send_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//随机产生客户端通信端口号
	SA recv_addr = send_addr;
	recv_addr.sin_port = htons(rand()%30000+1024);
	fd_c = create_sockfd();
	
	int ret = bind(fd_c,(SP)&recv_addr,sizeof(recv_addr));
	if(0 > ret)
	{
		perror("bind");
		return -1;
	}


	printf("请输入您的用户名：");
	scanf("%s",user_name);
	getchar();
	pthread_t pth_id1,pth_id2;
	sendto(fd_c,user_name,sizeof(recv_addr),0,(SP)&send_addr,sizeof(send_addr));
	recvfrom(fd_c,getin,sizeof(getin),0,(SP)&send_addr,&len);
	
	sleep(1);
	
	ret = pthread_create(&pth_id1,NULL,recv_func,user_name);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;
	}
	sleep(1);
	ret = pthread_create(&pth_id2,NULL,inp_func,user_name);
	if(0 > ret)
	{
		perror("pthread_create");
		return -1;
	}
	
	pthread_join(pth_id1,NULL);
	pthread_join(pth_id2,NULL);
	
}
