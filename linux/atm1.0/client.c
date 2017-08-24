#include "struct.h"


int sockfd = 0;

int login(MSG* msg)
{
	
	puts("请输入您的账户");
	scanf("%ld",&msg->acc.id[0]);
	getchar();
	puts("请输入您的密码");
	scanf("%s",msg->acc.psw);
	
	int ret = send(sockfd,msg,sizeof(MSG),0);
	if(0 > ret)
	{
		perror("send");
		return -1;
	}
	//接收数据
	recv(sockfd,msg,sizeof(MSG),0);
	printf("%d\n",msg->type);
	getchar();
	if(msg->type == 1)
	{
		printf("登录成功\n");
		return 1;
	}
	else if(msg->type == 0)
	{
	
		return 0;
	}
	return 0;
}

int main()
{
	
	int i = 0;
	int flag = 0;
	//创建sockfd
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(0 >= sockfd)
	{
		perror("socket");
		return -1;
	}

	//准备通信地址，目标机器的地址
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(18888);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	//使用通信地址，连接到目标机器
	int ret = connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	if(0 > ret)
	{
		perror("connect");
		return -1;
	}

	
	
	//登录界面
	while(1)
	{
		struct account acc = {};
		struct msg msg = {};

		msg.acc.money = 0;
		msg.type = 0;
		system("clear");
		puts("****欢迎来到指针银行！****");
		puts("***请选择您要进行的操作***");
		puts("*1.开户               ****");
		puts("*2.销户               ****");
		puts("*3.存款               ****");
		puts("*4.取款               ****");
		puts("*5.转账               ****");
		puts("*6.查询余额           ****");
		puts("*7.退出银行系统       ****");
		
		int input = 0;
		scanf("%d",&input);
		ret = send(sockfd,&input,sizeof(int),0);//2   1
		if(0 > ret)
		{
			perror("send");
			return -1;
		}
		switch(input)
		{
			case 1:
			{
		
				system("clear");
				printf("请输入你的姓名：");
				scanf("%s",msg.acc.name);
	/*			printf("请输入你的身份证号码：");
				for(i=0; i<18; i++)
				{
					scanf("%c",&msg.acc.idnum[i]);
				}
				getchar();
				*/
				printf("请输入您的密码：");
				scanf("%s",msg.acc.psw);
				
				ret = send(sockfd,&msg,sizeof(MSG),0);//3   2
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				
				ret = recv(sockfd,&msg,sizeof(MSG),0);//4   3
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				
				getchar();
				puts("开户成功！您的信息如下");
				printf("账户：%ld\n",msg.acc.id[0]);
				//printf("身份证号码：%s\n",msg.acc.idnum);
				printf("姓名：%s\n",msg.acc.name);
				printf("余额：%d\n",msg.acc.money);
				printf("密码:%s\n",msg.acc.psw);
				printf("输入任意键返回");
				scanf("%*c");
				
				break;
			}
			case 2:
			{
				
				puts("请输入您的账户");
				scanf("%ld",&msg.acc.id[0]);
				getchar();
				puts("请输入您的密码");
				scanf("%s",msg.acc.psw);

				int ret = send(sockfd,&msg,sizeof(MSG),0);
				if(0 > ret)
				{
					perror("send");
					return -1;
				}
				//接收数据
				recv(sockfd,&msg,sizeof(MSG),0);
				getchar();
				if(msg.type == 1)
				{
					printf("登录成功\n");
				}
				else if(msg.type == 0)
				{
					printf("帐户或密码错误，按任意键返回！\n");
					scanf("%*c");
					break;
					
				}
				
			
				ret = recv(sockfd,&msg,sizeof(MSG),0);
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				

				system("clear");
				puts("销户成功！\n");
				printf("输入任意键返回");
				scanf("%*c");
				break;
		
			}
			case 3:
			{
				puts("请输入您的账户");
				scanf("%ld",&msg.acc.id[0]);
				getchar();
				puts("请输入您的密码");
				scanf("%s",msg.acc.psw);

				int ret = send(sockfd,&msg,sizeof(MSG),0);
				if(0 > ret)
				{
					perror("send");
					return -1;
				}
				//接收数据
				recv(sockfd,&msg,sizeof(MSG),0);
				getchar();
				if(msg.type == 1)
				{
					printf("登录成功\n");
				}
				else if(msg.type == 0)
				{
					printf("帐户或密码错误，按任意键返回！\n");
					scanf("%*c");
					break;
					
				}
				
				printf("请输入存款数额：");
				scanf("%d",&msg.acc.money);
				send(sockfd,&msg,sizeof(MSG),0);
				ret = recv(sockfd,&msg,sizeof(MSG),0);
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				
				getchar();
	
				system("clear");
				puts("存款成功！\n");
				printf("您当前的余额为:%d\n",msg.acc.money);
				printf("输入任意键返回");
				scanf("%*c");	
				
				break;
			}
			case 4:
			{
				puts("请输入您的账户");
				scanf("%ld",&msg.acc.id[0]);
				getchar();
				puts("请输入您的密码");
				scanf("%s",msg.acc.psw);

				int ret = send(sockfd,&msg,sizeof(MSG),0);
				if(0 > ret)
				{
					perror("send");
					return -1;
				}
				//接收数据
				recv(sockfd,&msg,sizeof(MSG),0);
				getchar();
				if(msg.type == 1)
				{
					printf("登录成功\n");
				}
				else if(msg.type == 0)
				{
					printf("帐户或密码错误，按任意键返回！\n");
					scanf("%*c");
					break;
					
				}
				printf("请输入取款金额：");
				scanf("%d",&msg.acc.money);
				send(sockfd,&msg,sizeof(MSG),0);
				
				ret = recv(sockfd,&msg,sizeof(MSG),0);
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				
				getchar();

				system("clear");
				if(msg.acc.money < 0)
				{
					puts("对不起！您的余额不足！\n");
					printf("输入任意键返回");
					scanf("%*c");
					
				}
				else
				{
					puts("取款成功！\n");
					printf("您当前的余额为:%d\n",msg.acc.money);
					printf("输入任意键返回");
					scanf("%*c");
					
				}
				break;
				
			}
			case 5:
			{

				puts("请输入您的账户");
				scanf("%ld",&msg.acc.id[0]);
				getchar();
				puts("请输入您的密码");
				scanf("%s",msg.acc.psw);

				int ret = send(sockfd,&msg,sizeof(MSG),0);
				if(0 > ret)
				{
					perror("send");
					return -1;
				}
				//接收数据
				recv(sockfd,&msg,sizeof(MSG),0);
				getchar();
				if(msg.type == 1)
				{
					printf("登录成功\n");
				}
				else if(msg.type == 0)
				{
					printf("帐户或密码错误，按任意键返回！\n");
					scanf("%*c");
					break;
					
				}
				
				printf("请输入目标账户：");
				scanf("%ld",&msg.acc.id[1]);
				printf("请输入转账金额：");
				scanf("%d",&msg.acc.money);
				send(sockfd,&msg,sizeof(MSG),0);
				
				ret = recv(sockfd,&msg,sizeof(MSG),0);
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				
				system("clear");
				
				if(msg.type ==567)
				{
					getchar();
					printf("目标账户不存在！\n");
					printf("输入任意键返回");
					scanf("%*c");
					break;
				}
				
				if(msg.acc.money < 0)
				{
					getchar();
					puts("对不起！您的余额不足！\n");
					printf("输入任意键返回");
					scanf("%*c");
					
				}
				else
				{
					getchar();
					puts("转账成功！\n");
					printf("您当前的余额为:%d\n",msg.acc.money);
					printf("输入任意键返回");
					scanf("%*c");
				}
				break;
			}
			case 6:
			{
	
				puts("请输入您的账户");
				scanf("%ld",&msg.acc.id[0]);
				getchar();
				puts("请输入您的密码");
				scanf("%s",msg.acc.psw);

				int ret = send(sockfd,&msg,sizeof(MSG),0);
				if(0 > ret)
				{
					perror("send");
					return -1;
				}
				//接收数据
				recv(sockfd,&msg,sizeof(MSG),0);
				getchar();
				if(msg.type == 1)
				{
					printf("登录成功\n");
				}
				else if(msg.type == 0)
				{
					printf("帐户或密码错误，按任意键返回！\n");
					scanf("%*c");
					break;
					
				}
				
				ret = recv(sockfd,&msg,sizeof(MSG),0);
				if(0 >= ret)
				{
					perror("recv");
					pthread_exit(NULL);
				}
				
				

				printf("您当前的余额为:%d\n",msg.acc.money);
				printf("输入任意键返回");
				scanf("%*c");
				break;
				
			}
			case 7:
			{
				return 0;
			}
		}
		//fflush(stdout);

	}
	


}
