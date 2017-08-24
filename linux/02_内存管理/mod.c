#include <stdio.h>

int intmod(int num1,int num2,int* mod)
{
	if(0 == num2) return -1;
	*mod = num1%num2;

	return 0;
}

int main()
{
	int mod = 0;
	if(0 > intmod(8,3,&mod))
	{
		printf("取模失败！\n");
		return -1;
	}
	printf("取模结果:%d\n",mod);
	return 0;
}
