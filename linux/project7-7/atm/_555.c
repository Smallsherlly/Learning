#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include <signal.h>
#include <dirent.h>

int main(int argc,char* argv[])	
{
	struct account acc = {};
	struct msg msg = {};
	struct msg msg2 = {};

	//获取消息队列
	key_t key1 = ftok(".",11);
	key_t key2 = ftok(".",22);
	int msgid_s = msgget(key1,0);
	int msgid_r = msgget(key2,0);
	while(1)
	{
		if(msgrcv(msgid_r,&msg,sizeof(msg.acc),550,IPC_NOWAIT)!=-1)
		{
			msgsnd(msgid_s,&msg,sizeof(msg.acc),0);
			printf("_%d进程已关闭\n",msg.type);		
			return 0;
		}
		
		if(msgrcv(msgid_r,&msg,sizeof(msg.acc),555,IPC_NOWAIT)!=-1)
		{
			int flag = 0;
			//读取指定账户文件
			char s[2][30] = {};
			
			DIR* dp = opendir ("./data");
    		if (! dp) 
    		{
       		 perror ("opendir");
       		 return -1;
    		}
			struct dirent* de;
			sprintf(s[1],"%ld%s",msg.acc.id[1],".bat");
    		for (de = readdir (dp); de; de = readdir (dp)) 
    		{
    			if(de->d_name[0]!='.')
    			{
    				if(0 == strcmp(s[1],de->d_name))
    				{
    					flag = 1;
    				}
    			}
    		}
    		if(flag == 1)
    		{
    			sprintf(s[0],"%s%ld%s","./data/",msg.acc.id[0],".bat");
				sprintf(s[1],"%s%ld%s","./data/",msg.acc.id[1],".bat");
				FILE* fp = fopen(s[0],"r+");
				if(NULL == fp)
				{
					perror("fopen");
					return -1;
				}
				FILE* fp2 = fopen(s[1],"r+");
				if(NULL == fp2)
				{
					perror("fopen");
					return -1;
				}
				int money = msg.acc.money;
				fread(&msg2.acc,sizeof(msg.acc),1,fp);
				msg.acc.money = msg2.acc.money-money;
				fseek(fp,0,SEEK_SET);
			
				if(msg.acc.money > 0)
				{
					fwrite(&msg.acc,sizeof(msg.acc),1,fp);
				
					fread(&msg2.acc,sizeof(msg.acc),1,fp2);
					fseek(fp2,0,SEEK_SET);
					msg2.acc.money = msg2.acc.money + money;
					fwrite(&msg2.acc,sizeof(msg.acc),1,fp2);
				}
				msgsnd(msgid_s,&msg,sizeof(msg.acc),0);
				fclose(fp);
				fclose(fp2);
			}
			else
			{
				msg.type = 567;
				msgsnd(msgid_s,&msg,sizeof(msg.acc),0);
			}
			

		}
	}
	
	return 0;
}
