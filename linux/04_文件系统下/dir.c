#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

//判断文件类型
void show_type(unsigned char type)
{
	switch(type)
	{
		case DT_DIR:
			printf("目录");break;
		case DT_REG:
			printf("普通文件");break;
		case DT_LNK:
			printf("链接文件");break;
		case DT_BLK:
			printf("块设备文件");break;
		case DT_CHR:
			printf("字符设备文件");break;
		case DT_SOCK:
			printf("socket文件");break;
		case DT_FIFO:
			printf("管道文件");break;
		case DT_UNKNOWN:
			printf("未知的文件类型");break;
	}
}
int main ()
{
	//打开一个目录返回一个fd
	int fd = open("/home/ubuntu",O_RDONLY);
	//根据fd打开目录，返回一个目录流
	DIR* dp = fdopendir(fd);
	//读取目录流当中的条目
	struct dirent* de = NULL;
	for(de = readdir(dp); de; de = readdir(dp))
	{
		if('.'!=de->d_name[0])
		{
			printf("%s\n",de->d_name);
			show_type(de->d_type);
			printf("\n");
		}
	}
	return 0;	
}
