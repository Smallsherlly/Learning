#include<stdio.h>
int nine();
int main()
{
	nine();
	return 0;	
}
int nine()
{
	int i = 1,j = 1;
		
	while(i<=9)
	{
		while(j<=i)
		{
			printf("%dx%d=%2d ",j,i,i*j);
			j++;
		}printf("\n");
		i++;
		j = 1;
	}



}
