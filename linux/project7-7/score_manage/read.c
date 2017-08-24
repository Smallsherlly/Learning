#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	//创建文件
	int fd = open("data.txt",O_WRONLY,0666);
	int fd2 = open("solution.txt",O_RDONLY,0666);
	
	if(0 > fd||0 > fd2)
	{
		perror("open");
		return -1;
	}

	typedef struct Student
	{
		int num;
		char name[20];
		char ans[50];
		short score;
	}Student;
	
	char buf[1024] = {};
	char solution[50] = {};
	int ret = read(fd2,solution,sizeof(char)*50);
	if(0 > ret)
	{
		perror("close");
		return -1;
	}
	
	//学生结构体数组
	Student stu[50] = {};
	int i = 0;
	for(; i<2; i++)
	{
		puts("\n请输入学生学号：");
		scanf("%d",&stu[i].num);
		puts("\n请输入学生姓名：");
		scanf("%s",stu[i].name);
		puts("\n请输入各题答案：");
		stu[i].score = 0;
		int j = 0;
		for(; j<50; j++)
		{
			ret = 0;
			getchar();
			printf("\n第%d道题：",j+1);
			scanf("%c",&stu[i].ans[j]);
			if(solution[j] == stu[i].ans[j])
			stu[i].score = stu[i].score+2;
	
		}
		sprintf(buf+strlen(buf),"%d %s %hd %hd%%\n",stu[i].num,stu[i].name,stu[i].score,stu[i].score);
		
	}
	ret = write(fd,buf,strlen(buf));
	
	if(0 > ret)
	{
		perror("write");
		return -1;
	}

	ret = close(fd2);
	if(0 > ret)
	{
		perror("close");
		return -1;
	}
	
	ret = close(fd);
	if(0 > ret)
	{
		perror("close");
		return -1;
	}
	
	printf("关闭文件成功！\n");

	return 0;
}

