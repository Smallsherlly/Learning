#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	struct stat file_s;
	int ret = stat("fcntl.bin",&file_s);
	if(0 > ret)
	{
		perror("stat");
		return -1;
	}

	printf("dev_id=%d info=%d\n",file_s.st_dev,file_s.st_ino);
	printf("文件类型：%c\n",file_s.st_mode&S_IFREG? 'f':'o');
	return 0;	
}
