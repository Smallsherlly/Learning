#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	//创建key
	key_t key = ftok(".",66);
	//创建消息队列
	int msgid = msgget(key,0644|IPC_CREAT|IPC_EXCL);

	struct
	{
		int m_type;
		char m_str[255];
	}msg = {666,"hahaha"};

	//发送数据
	msgsnd(msgid,&msg,strlen(msg.m_str)+1,0);
	scanf("%*c");

	//销毁消息队列
	msgctl(msgid,IPC_RMID,NULL);
	
}
