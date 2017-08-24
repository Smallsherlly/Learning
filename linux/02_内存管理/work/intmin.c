#include <stdio.h>

int intmin(int num1,int num2)
{
	if(num1==num2)  return -1;
	return num1<num2?num1:num2;
}

int main()
{
	if(intmin(4,5)==-1)
	{
		printf("lose\n");
	}
	printf("%d\n",intmin(4,5));

}
