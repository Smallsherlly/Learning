#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void updata(void)
{
	printf("开始上传数据\n");
	int i;
	for(i=0; i<10; i++)
	{
		printf("进程%u，正在上传第%d条数据\n",getpid(),i);
		sleep(1);
	}
	printf("上传数据结束\n");
}

void sig_func(int signum)
{
	printf("信号%d来了\n",signum);
}
int main()
{
	signal(SIGINT,sig_func);
	//设置信号集
	sigset_t new_set,old_set;
	sigemptyset(&new_set);
	sigaddset(&new_set,SIGINT);

	//屏蔽信号集中的信号,并获取之前屏蔽的信号集
	sigprocmask(SIG_SETMASK,&new_set,&old_set);
	//上传数据
	updata();
	//恢复屏蔽的信号集
	sigprocmask(SIG_SETMASK,&old_set,NULL);
}
