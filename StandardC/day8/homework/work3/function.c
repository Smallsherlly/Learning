#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
extern Stu stu[];
extern int i;

void loadi()
{
	FILE *fp = fopen("./it.txt","r");
	fscanf(fp,"%d",&i);

	for(int j = 1;j <= i;j++)
	{
		fread(&stu[j],sizeof(Stu),1,fp);
	}
	fclose(fp);
	
}
int show()
{
	printf("请选择你要进行的操作：\n");
	printf("1.录入学生信息。\n");
	printf("2.删除学生信息。\n");
	printf("3.改变学生信息。\n");
	printf("4.查找学生信息。\n");
	int in = 0;
	scanf("%d",&in);
	if(in==1)
	{
		return 1;	
	}else if(in==2){
		return 2;
	}else if(in==3){
		return 3;
	}else if(in==4){
		return 4;
	}

	
	
}

void input()
{
	printf("请输入学生姓名：");	
	scanf("%s",stu[0].name);
	printf("请输入学生所在班级：");	
	scanf("%s",stu[0].grade);	
	stu[0].iNum = i+1;
	printf("%d",stu[0].iNum);
}


void add()//增加学生信息
{
	loadi();
	while(1)
	{
		input();
		FILE *fp = fopen("./data.txt","a+");
		
		fwrite(&stu[0],sizeof(Stu),1,fp);
		i++;
		FILE *fp2 = fopen("./it.txt","w+");
		fprintf(fp2,"%d",i);
		fclose(fp2);
		printf("录入成功！您输入的学生信息为：\n");
		printf("学号： %d\n",stu[0].iNum);
		printf("姓名： %s\n",stu[0].name);
		printf("班级： %s\n",stu[0].grade);
		FILE *fp3 = fopen("./data.txt","r");
		for(int j = 1;j <= i;j++)
	{
		fread(&stu[j],sizeof(Stu),1,fp3);
	}
	
		printf("%d",stu[1].iNum);
	fclose(fp3);
//		char in = 0;
//		printf("请输入‘Q’退出，否则继续录入。\n");
//		getchar();
//		scanf("%c",&in);
//		if(in=='Q')break;
		fclose(fp);
	}
}

void del()//删除学生信息
{
	loadi();
	FILE *fp = fopen("./data.txt","w+");
	while(1)
	{
		
		int num = 0;
		printf("请输入你要删除的学生学号：\n");
		scanf("%d",&num);
		if(num>140000&&num<=i)
		{
			memset(&stu[num-140000],0,sizeof(Stu));
			for(int j = 0;j < i;j++)
			{
				fwrite(&stu[j],sizeof(Stu),1,fp);
			}
		
		}else{
			printf("该学号不存在，输入‘Y’重新输入学号，否则退出。");
			char in = 0;
			scanf("%c",&in);
			if(in!='Y')break;
		}

	}


}

void change()//改变学生信息
{
	loadi();
	int in = 0;
	FILE *fp = fopen("./data.txt","w+");
	printf("请输入你要修改的学生学号：\n");
	scanf("%d",&in);
	in = in-140000;
	memset(&stu[in],0,sizeof(Stu));
	stu[in].iNum = in+140000;
	printf("请输入修改后的学生姓名：");
	scanf("%s",stu[in].name);
	printf("请输入修改后的学生班级：");
	scanf("%s",stu[in].grade);
	fwrite(stu,sizeof(Stu),i,fp);
	fclose(fp);
	/*for(int j = 0;j <= i;j++)
	{
		fread(&stu[j],sizeof(Stu),1,fp);
	}*/

}

void search()//查找学生信息
{
	FILE *fp = fopen("./data.txt","r");
	/*for(int j = 0;j <= i;j++)
	{
		fread(&stu[j],sizeof(Stu),1,fp);
	}*/
	
}
