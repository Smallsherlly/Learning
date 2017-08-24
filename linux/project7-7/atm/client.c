#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"

struct account acc = {};
struct msg msg = {};

int login(int msgid_s,int msgid_r)
{
	puts("请输入您的账户");
	scanf("%ld",&msg.acc.id[0]);
	getchar();
	puts("请输入您的密码");
	scanf("%s",msg.acc.psw);
	msg.type = 777;
	//发送数据
	msgsnd(msgid_s,&msg,sizeof(msg.acc),0);

	//接收数据
	msgrcv(msgid_r,&msg,sizeof(msg.acc),0,0);
	
	if(msg.type == 123)
	{
		printf("登录成功\n");
		return 1;
	}
	else if(msg.type == 456)
	{
	
		return -1;
	}
	return 0;
}
int main()
{
	
	int i = 0;
	int flag = 0;
	//获取消息队列
	key_t key1 = ftok(".",11);
	key_t key2 = ftok(".",22);
	int msgid_r = msgget(key1,0);
	int msgid_s = msgget(key2,0);

	//登录界面
	while(1)
	{
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
		switch(input)
		{
			case 1:
			{
				msg.type = 111;
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
				
				break;
			}
			case 2:
			{
				
				if(login(msgid_s,msgid_r)==1)
				{
					msg.type = 222;
				}
				else
				{
					printf("输入的密码有误！\n");
					msg.type = 888;
				}
				break;
			}
			case 3:
			{
				
				if(login(msgid_s,msgid_r)==1)
				{
				
					msg.type = 333;
					printf("请输入存款金额:");
					scanf("%d",&msg.acc.money);
				}
				else
				{
					printf("输入的密码有误！\n");
					msg.type = 888;
				}
				break;
			}
			case 4:
			{
				if(login(msgid_s,msgid_r)==1)
				{
					msg.type = 444;
					printf("请输入取款金额:");
					scanf("%d",&msg.acc.money);
				}
				else
				{
					printf("输入的密码有误！\n");
					msg.type = 888;
				}
				break;
			}
			case 5:
			{
				if(login(msgid_s,msgid_r)==1)
				{
					msg.type = 555;
					puts("请输入目标帐号：");
					scanf("%ld",&msg.acc.id[1]);
					printf("请输入转账金额:\n");
					scanf("%d",&msg.acc.money);
				}
				else
				{
					printf("输入的密码有误！\n");
					msg.type = 888;
				}
				break;
			}
			case 6:
			{
				if(login(msgid_s,msgid_r)==1)
				{
					msg.type = 666;
				}
				else
				{
					printf("输入的密码有误！\n");
					msg.type = 888;
				}
				break;
			}
			case 7:
			{
				return 0;
			}
		}

		//发送数据
		msgsnd(msgid_s,&msg,sizeof(msg.acc),0);
		
		msgrcv(msgid_r,&msg,sizeof(msg.acc),0,0);
		
		//反馈
		switch(msg.type)
		{
			case 111:
			{
				system("clear");
				getchar();
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),111,0);
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
			case 222:
			{
				getchar();
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),222,0);
				system("clear");
				puts("销户成功！\n");
				printf("输入任意键返回");
				scanf("%*c");
				break;
			}
			case 333:
			{
				getchar();
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),333,0);
				system("clear");
				puts("存款成功！\n");
				printf("您当前的余额为:%d\n",msg.acc.money);
				printf("输入任意键返回");
				scanf("%*c");
				break;
			}
			case 444:
			{
				getchar();
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),444,0);
				system("clear");
				if(msg.acc.money < 0)
				{
					puts("对不起！您的余额不足！\n");
					printf("输入任意键返回");
					scanf("%*c");
					break;
				}
				else
				{
					puts("取款成功！\n");
					printf("您当前的余额为:%d\n",msg.acc.money);
					printf("输入任意键返回");
					scanf("%*c");
					break;
				}
			}
			case 555:
			{
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),555,0);
				system("clear");
				if(msg.acc.money < 0)
				{
					puts("对不起！您的余额不足！\n");
					printf("输入任意键返回");
					scanf("%*c");
					break;
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
			case 567:
			{
				getchar();
				printf("目标账户不存在！\n");
				printf("输入任意键返回");
				scanf("%*c");
				break;

			}
			case 666:
			{
				getchar();
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),666,0);
				printf("您当前的余额为:%d\n",msg.acc.money);
				printf("输入任意键返回");
				scanf("%*c");
				break;
			}
			default :
			{
				getchar();
		//		msgrcv(msgid_r,&msg,sizeof(msg.acc),888,0);
				printf("输入任意键返回");
				scanf("%*c");
			 	break;
			 }

		}
	}


}
