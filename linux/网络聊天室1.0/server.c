#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

int user_len = 0;
typedef struct sockaddr* SP;
typedef struct sockaddr_in SA;

typedef struct user_info
{
	char user_name[10][20];
	SA 	 user_addr[10];
}user;

typedef struct msg_pub
{
	int msg_num;
	char msg[100][255];
}MSG;

MSG msg;
//user user_info;
SA user_addr[10];
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

void server(void* arg)
{
	printf("-------------\n");
	int i = 0;
	int fd = create_sockfd();
	int user_num = user_len - 1;
	char* user_name = (char*)arg;
	char buf[255] = {};
	sprintf(buf,"尊敬的%s,%u正在为您服务...",user_name,pthread_self());
	sendto(fd,buf,strlen(buf)+1,0,(SP)&user_addr[user_num],sizeof(SA));
	for(i=0; i<user_len; i++)
	{
	sendto(fd,&msg,sizeof(MSG),0,(SP)&user_addr[i],sizeof(SA));
	}
	while(1)
	{
		recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
/*	//@user_name 私信
		if(buf[0] == '@')
		{
			for(i=0; i<user_len; i++)
			{
				if(!strcmp(user_info.user_name,buf+1))
				{
				
				}
			}
			
		}
	*/	
		//群聊
		sprintf(msg.msg[msg.msg_num],"%s\n",buf);
		msg.msg_num++;
		for(i=0; i<user_len; i++)
		{
		sendto(fd,&msg,sizeof(MSG),0,(SP)&user_addr[i],sizeof(SA));
		}
	}
}

int main()
{
	int fd = create_sockfd();
	SA send_addr;
	SA send_addr2;
	SA recv_addr;
	recv_addr.sin_family = AF_INET;
	recv_addr.sin_port = htons(12345);
	recv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int ret = bind(fd,(SP)&recv_addr,sizeof(recv_addr));
	if(0 > ret)
	{
		perror("bind");
		return -1;
	}
	pthread_t pth_id = 0;	
	user user_info;
	char user_name[20] = {};
	socklen_t len = sizeof(send_addr);

	sprintf(msg.msg[0],"\n%s\n","-------");
	msg.msg_num++;
	while(1)
	{
		recvfrom(fd,user_name,sizeof(send_addr),0,(SP)&user_addr[user_len],&len);
		user_len++;	
		sleep(1);
		printf("user_len:%d\n",user_len);
		//开辟子线程
		ret = pthread_create(&pth_id,NULL,server,user_name);
		if(0 > ret)
		{
			perror("pthread_create");
			return -1;
		}
	}
//	printf("send port:%u\n",ntohs(send_addr.sin_port));
	
}
