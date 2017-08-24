#include<stdio.h>

int change();
int main()
{
	int a =10,b = 20;
	change(&a,&b);
	
	printf("%d,%d\n",a,b);
	return 0;	
}
int change(int* x,int* y)
{
	int t = 0;
	t = *x;
	*x= *y;
	*y = t;
	
}
