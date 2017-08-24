#include<stdio.h>

struct test
{
	char *a[7];
//	short b;
//	char  c;
//	short g;
//	int d;
//	short f;
};

int main()
{
	printf("%d\n",sizeof(struct test));	
	
	return 0;	
}
