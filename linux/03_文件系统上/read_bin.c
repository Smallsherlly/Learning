#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	//创建文件
	int fd = open("data.bin",O_RDONLY,0666);

	typedef struct Student
	{
		char name[20];
		char sex;
		short age;
	}Student;
//	Student zhaoyun = {"赵云",'m',88};
	Student zhaoyun = {};

	//创建缓冲区
	char buf[1024];

	//把要写的数据拼接入缓冲区
//	sprintf(buf,"%s %c %hd\n",zhaoyun.name,zhaoyun.sex,zhaoyun.age);

	//把缓冲区写入文件

	int ret = read(fd,&zhaoyun,sizeof(Student));
	if(0 > ret)
	{
		perror("read");
		return -1;
	}
//	sscanf(buf,"%s %c %hd",zhaoyun.name,&zhaoyun.sex,&zhaoyun.age);
	printf("%s %c %hd\n",zhaoyun.name,zhaoyun.sex,zhaoyun.age);	
//	printf("%s",buf);	
	ret = close(fd);
	if(0 > ret)
	{
		perror("close");
		return -1;
	}
	
	printf("关闭文件成功！\n");
	return 0;
}
