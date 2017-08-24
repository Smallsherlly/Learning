#include <stdio.h>

int intave(int num1,int num2)
{
	int ave1 = num1/2;
	int ave2 = num2/2;
	return ave1+ave2;
}

int main()
{
	printf("%d\n",intave(100,20));
	
}
