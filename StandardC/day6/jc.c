#include<stdio.h>

int jc(int x)
{
	if(x==1)
		return 1;
	return (x =x*jc(x-1));
	
}
int main()
{
	int x = 0;
	scanf("%d",&x);
	printf("%d\n",jc(x));
	
	return 0;	
}
