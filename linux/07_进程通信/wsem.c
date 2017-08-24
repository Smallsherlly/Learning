#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>


int main()
{
	//创建key
	key_t key = ftok(".",168);
	//创建信号量
	int semid = semget(key,1,0644|IPC_CREAT|IPC_EXCL);
	//创建初始化信号量
	semctl(semid,0,SETVAL,5);
	scanf("%*c");
	//销毁信号量
	semctl(semid,0,IPC_RMID);
	
}
