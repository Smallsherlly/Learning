#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sig_func(int signum,siginfo_t* info,void *pr)
{
	printf("捕获到信号%d\n",signum);
	printf("接收到附加数据:%s\n",(char*)info->si_value.sival_ptr);
}

int main()
{
	//准备信号触发时附加的数据
	char* str = "我爱你";
	//准备注册函数使用的结构体
	struct sigaction act = {};
	//使用可以附加数据的函数
	act.sa_sigaction = sig_func;
	//使用结构体中第二个函数指针
	act.sa_flags = SA_SIGINFO;
	
	sigaction(SIGINT,&act,NULL);

	sleep(3);
	//准备发送信号时附加的联合变量
	sigval_t val;
	val.sival_ptr = str;

	//发送信号
	sigqueue(getpid(),SIGINT,val);

	return 0;	
} 
