#include<stdio.h>

#define iMax(x,y) ((x)>(y)?(x):(y))


int main()
{
	int x = 0,y = 0;
	scanf("%d %d",&x,&y);
	printf("%d\n",iMax(x,y));
	
	return 0;	
}
