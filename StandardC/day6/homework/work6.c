#include<stdio.h>
#include<string.h>


struct student 
{
	char name[24];
	int  num;
	int  score[4];
};

void exchange(struct student *stu1,struct student *stu2)
{
	char tem[24] = {0};
	int tnum = 0;
	int tscore = 0;
	strcpy(tem,stu1->name);
	strcpy(stu1->name,stu2->name);
	strcpy(stu2->name,tem);
	tnum = stu1->num;
	stu1->num = stu2->num;
	stu2->num = tnum;
	for(int i = 0;i<4;i++)
	{
		tscore = stu1->score[i];
		stu1->score[i] = stu2->score[i];
		stu2->score[i] = tscore;
	}
	stu1->score[3] = (stu1->score[0]+stu1->score[1]+stu1->score[2])/3;
	stu2->score[3] = (stu2->score[0]+stu2->score[1]+stu2->score[2])/3;
}
	

int main()
{
	struct student stu1 = {"唧唧稿",14036812,{30,29,31}};
	struct student stu2 = {"小夏林",14036820,{99,98,100}};
	exchange(&stu1,&stu2);
	printf("%s %d %d %d %d %d\n",stu1.name,stu1.num,stu1.score[0],stu1.score[1],stu1.score[2],stu1.score[3]);	
	printf("%s %d %d %d %d %d\n",stu2.name,stu2.num,stu2.score[0],stu2.score[1],stu2.score[2],stu2.score[3]);	
	return 0;	
}
