#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <fcntl.h>


int main()
{
	//创建key
	key_t key = ftok(".",66);
	//获取消息队列
	int msgid = msgget(key,0);

	//读取数据
	struct
	{
		int m_type;
		char m_str[255];
	}msg = {};
	
	msgrcv(msgid,&msg,sizeof(msg.m_str),666,0);
	printf("接收到的数据是%s\n",msg.m_str);

}
