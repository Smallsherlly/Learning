#include<stdio.h>
typedef struct Student
{
	int age;
	char name[24];
	int grade;
}Stu;
int main()
{
	FILE *fp = fopen("./stu.txt","w+");
	Stu stu[3] = {{12,"lin",21},{ 13,"chen",31},{14,"yuan",41}};
//	char brr[204] = {0};
//	for(int i = 0;i < 3;i++)
	
		fwrite(&stu[0],sizeof(Stu),3,fp);
	
	fclose(fp);
	Stu s[3] = {0};
	fp = fopen("stu.txt","r");
	fread(&s[0],sizeof(Stu),3,fp);
//	for(int i = 0;i<3;i++)
	for(int i =0;i<3;i++)
	{
		printf("%d %s %d\n",s[i].age,s[i].name,s[i].grade);
	}
	fclose(fp);


	
	return 0;	
}
