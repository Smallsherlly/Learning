#include<stdio.h>
int zhishu();
int main()
{
	zhishu();
	
	return 0;	
}

int zhishu()
{
	
	for(int x =2;x<1000;x++)
	{
		int iFlag = 0;
		for(int i = 2;i<=x/2;i++)
		{
			if(x%i == 0)
			{
				iFlag = 1;
				break;
			}
		}
		if(iFlag == 0)
		printf("%d ",x);
	}
	
}
