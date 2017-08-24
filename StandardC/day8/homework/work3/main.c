#include"student.h"
#include"function.h"
#include<stdio.h>
Stu stu[10] = {0};
int num = 140000;
int i;
int main()
{
	int in = show();
	if(in==1)
	{
		add();
	}else if(in==2){
		del();
	}else if(in==3){
		change();
	}
	return 0;
}
