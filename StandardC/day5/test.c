#include<stdio.h>

int main()
{
	int arr[sizeof(int)*8] = {0};
	int iNum = 0;
	scanf("%d",&iNum);

	for(int i = 0;i < sizeof(int)*8;i++)
	{
		if(iNum &= (1<<i) >= 0)
		{
			printf("0");
		}else{
			printf("1");
		}
		
	}printf("\n");
	return 0;
}
