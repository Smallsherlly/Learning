#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("haha",O_RDWR|O_CREAT|O_TRUNC,0666);

/*	close(1);
	dup(fd);//复制fd的内容，返回当前没有使用的最小的fd
*/
	dup2(fd,1);//把fd复制给1，如果1被打开，先关闭再复制
	printf("hello world!\n");

	close(fd);
}
