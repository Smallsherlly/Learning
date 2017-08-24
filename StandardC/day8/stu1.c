#include<stdio.h>

int main()
{
	FILE *fp =fopen("./stu.txt","r");
	char brr[204] = {0};
	fread(brr,sizeof(char),31,fp);
	printf("%s\n",brr);
	return 0;	
}
