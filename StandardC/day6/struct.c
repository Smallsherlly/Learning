#include<stdio.h>
#include<string.h>
struct Person
{
	char name[24];
	int sex;
	int age;
};

int main()
{
	struct Person pe1 ={"jinping",1,67};
	struct Person pe2 ;
	strcpy(pe2.name,"keqiang");
	pe2.sex =1;
	pe2.age =66;
	printf("%s %d %d",pe1.name,pe1.sex,pe1.age);
	printf("%s %d %d",pe2.name,pe2.sex,pe2.age);
	return 0;	
}
