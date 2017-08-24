#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd = open("data2.txt",O_RDWR);

	lseek(fd,8,SEEK_END);

	//文件黑洞
	write(fd,"这里有个洞洞\n",19);

	close(fd);

}
