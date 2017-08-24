#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp1 = fopen("data1.txt","r");
	FILE* fp2 = fopen("data2.txt","r");
	FILE* fp3 = fopen("data3.txt","a");
	if(fp1 == NULL||fp2 == NULL||fp3 == NULL)
	{
		printf("打开文件失败！\n");
		return -1;
	}
	
	typedef struct Student
	{
		int num;
		char name[20];
		char ans[5][20];
		short score;
	}Student;
	
	Student stu = {};
	int i = 0, j = 0;
	int ret = fscanf(fp1,"%d %s %d~%d:%s %d~%d:%s %d~%d:%s %d~%d:%s %d~%d:%s\n",&stu.num,stu.name,&i,&j,stu.ans[0],&i,&j,stu.ans[1],&i,&j,stu.ans[2],&i,&j,stu.ans[3],&i,&j,stu.ans[4]);
	printf("%d %s\n01~10:%s\n11~20:%s\n21~30:%s\n31~40:%s\n41~50:%s\n",stu.num,stu.name,stu.ans[0],stu.ans[1],stu.ans[2],stu.ans[3],stu.ans[4]);
	if(0 > ret)
	{
		printf("读取文件失败");
	}
printf("$$%c",stu.ans[1][1]);	
	Student sol = {};
	ret = fscanf(fp2,"%d %s %d~%d:%s %d~%d:%s %d~%d:%s\n%d~%d:%s\n%d~%d:%s\n",&sol.num,sol.name,&i,&j,sol.ans[0],&i,&j,sol.ans[1],&i,&j,sol.ans[2],&i,&j,sol.ans[3],&i,&j,sol.ans[4]);
	printf("%d %s\n01~10:%s\n11~20:%s\n21~30:%s\n31~40:%s\n41~50:%s\n",sol.num,sol.name,sol.ans[0],sol.ans[1],sol.ans[2],sol.ans[3],sol.ans[4]);
	if(0 > ret)
	{
		printf("读取文件失败");
	}
	i = 0;
	j = 0;
	ret = 0;
	char buf[1024] = {};
	for(; i<5; i++)
	{
		j = 0;
		for(; j<10; j++)
		{
			if(sol.ans[i][j*2] == stu.ans[i][j*2])
			stu.score = stu.score+2;
	
		}
		
	}
	sprintf(buf+strlen(buf),"%d %s %hd %hd%%\n",stu.num,stu.name,stu.score,stu.score);
	ret = fwrite(buf,strlen(buf),1,fp3);
	
	if(0 > ret)
	{
		perror("write");
		return -1;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	
	return 0;
	
}
