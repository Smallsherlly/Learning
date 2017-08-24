#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	printf("DATE:%s %s\n",__DATE__,__TIME__);
	printf("PATH_MAX:%d\n",PATH_MAX);
	printf("pid:%d\n",getpid());
	int fd = open("./data.bin",O_RDWR|O_CREAT,0644);
	int psw = 1314;
	if( fd == -1)
	{
		perror("open");
		return -1;
	}
	write(fd,&psw,sizeof(int));
	close(fd);
	int rcv = 0;
	 fd = open("./data.bin",O_RDWR|O_CREAT,0644);
	int ret = read(fd,&rcv,sizeof(int));
	printf("%d\n",rcv);
	printf("读到%d个字节",ret);
	close(fd);
	return 0;
}
