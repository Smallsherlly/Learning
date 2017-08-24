#include <stdio.h>
#include <fcntl.h>

int main()
{
	//复制标准输出文件描述符
	int fd = fcntl(1,F_DUPFD,10);
	//如果文件描述符复制成功，终端会显示hello。。。
	write(fd,"hello world!\n",13);
	
	return 0;
}
