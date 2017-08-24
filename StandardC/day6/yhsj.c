#include<stdio.h>

int func(int x, int y)
{
	if(y == 1||x==y)
		return 1;
	return func(x-1,y-1)+func(x-1,y);	
}

int main()
{
	int iN = 0;
	scanf("%d",&iN);
	for(int i = 1;i <= iN;i++)
	{
		for(int j = 1;j <= i;j++)
		{
			printf("%-2d ",func(i,j));
		}
		printf("\n");
	}
	
	
	
	return 0;	
}
