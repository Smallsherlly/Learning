#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
int main(int argc,char** argv)
{
	if(argc != 3)
		return -1;
	char arr[4] = "./cp";
	char brr[4] = "./mv";
	printf("%s",argv[0]);
	if(strcmp(arr,argv[0]))
	{
		int fd = open(argv[1],O_RDONLY);
		char buf[1024] = {};
		int ret = read(fd,buf,sizeof(buf));
		if(ret<0)
		{
			perror("read");
			return -1;
		}
		char* path = malloc(sizeof(char)*1024);
		sprintf(path,"%s/%s",argv[2],argv[1]);
		int fd2 = open(path,O_RDWR|O_CREAT|O_TRUNC,0666);
		ret = write(fd2,buf,ret);
		ret = close(fd);
		ret = close(fd2);
		if(ret<0)
		{
			perror("close");
			return -1;
		}
		printf("关闭文件成功！\n");
		free(path);
		return 0;
	}else if(strcmp(brr,argv[0]))
	{
		
	}
		return 0;

}
