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
		if(msgrcv(msgid_r,&msg,sizeof(msg.acc),220,IPC_NOWAIT)!=-1)
		{
			msgsnd(msgid_s,&msg,sizeof(msg.acc),0);
			printf("_%d进程已关闭\n",msg.type);			
			return 0;
		}
		if(msgrcv(msgid_r,&msg,sizeof(msg.acc),222,IPC_NOWAIT)!=-1)
		{
		
			DIR* dp = opendir ("./data");
    		if (! dp) 
    		{
       		 perror ("opendir");
       		 return -1;
    		}
    		char s[20] = {};
			struct dirent* de;
    		for (de = readdir (dp); de; de = readdir (dp)) 
    		{
    			if(de->d_name[0]!='.')
    			{
    				sprintf(s,"%ld%s",msg.acc.id[0],".bat");
    				if(0 == strcmp(s,de->d_name))
    				{
    					sprintf(s,"%s%ld%s","./data/",msg.acc.id[0],".bat");
    					unlink(s);
    				}
    			}
    		}
    		msgsnd(msgid_s,&msg,sizeof(msg.acc),0);
    		
   		 }
   	}

	
	return 0;
}
