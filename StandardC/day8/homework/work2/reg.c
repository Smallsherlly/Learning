#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Guest.h"

int i ;
extern Gue gue[100];
int checkname();
int checkpsw();
void input();
void loadi()
{
	FILE *fp3 = fopen("./it.txt","r+");
	fscanf(fp3,"%d",&i);
	fclose(fp3);
}
int reg()
{
	//FILE *fp3 = fopen("./it.txt","r+");
	FILE *fp1 = fopen("./data.txt","r");
	FILE *fp2 = fopen("./data.txt","a+");
	loadi();
	//printf("%d",i);
	
	//if(i!=1)
	//{
		for(int j = 1;j <= i;j++)
		{
			fread(&gue[j],sizeof(Gue),1,fp1);
		}
	//}
	while(1)
	{
		system("clear");
		input();
				
		if(checkname()==0)
		{
			fwrite(&gue[0],sizeof(Gue),1,fp2);
		//rewind(fp);	
			i++;//注册成功后注册号加1
			printf("%d",i);
			FILE *fp3 = fopen("./it.txt","w+");
			fprintf(fp3,"%d",i);
			fclose(fp1);
			fclose(fp2);
			fclose(fp3);
			return 0 ;
		}
		printf("用户名已存在，请输入‘Y’返回注册界面！\n");
		char in = 0;
		getchar();
		gets(&in);
		if(in!='Y')break;
	}
	
		
}
void input()
{
	printf("请输入用户名");
	scanf("%s",gue[0].name);
	printf("请输入密码");
	scanf("%s",gue[0].psw);
		
}
int checkname()
{
	loadi();
	//printf("%s %s",gue[2].name,gue[2].psw);
//	printf("*%d",i);
	//if(i==1)return 0;
	for(int j = 1;j <= i;j++)
	{
		for(int x = 0; x<24;)
		{
			if(gue[0].name[x]==gue[j].name[x])
			{
				x++;
			}else
				break;
			if(x==24)
				return 1;
			
		
		}
	}
	return 0;
	
	
}
int checkpsw()
{
	loadi();
	int t = 0;
	//printf("%s %s",gue[2].name,gue[2].psw);
//	printf("*%d",i);
	for(int j = 1;j <= i;j++)
	{
		for(int x = 0; x<24;)
		{
			if(gue[0].name[x]==gue[j].name[x])
			{
				x++;
			}else
				break;
			if(x==24)
			{
				t = j;
				for(int z = 0; z<24;)
				{
					if(gue[0].psw[z]==gue[t].psw[z])
					{
						z++;
					}else
						break;
					if(z==24)
						return 1;
			
					
				}
			}
			
		
		}
	}
	

	return 0;
	
	
}

int  show()
{
	printf("请选择你要进行的操作：\n");
	printf("1.登录帐号\n");
	printf("2.注册帐号\n");
	int in = 0;
	scanf("%d",&in);
	return in;
	
	
	
	
}
int login()
{
	loadi();
	FILE *fp1 = fopen("./data.txt","r");
	for(int j = 1;j <= i;j++)
	{
		fread(&gue[j],sizeof(Gue),1,fp1);
	}
	while(1)
	{
		
		system("clear");
		input();
		if(checkpsw()==1)
		{
			printf("登录成功！\n");
			break;
		}else{
			printf("登录失败！输入Y重新登录，否则退出。\n");
			char in = 0;
			getchar();
			gets(&in);
			if(in!='Y')break;
		}
	}
	
	
}
