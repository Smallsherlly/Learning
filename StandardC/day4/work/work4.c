#include<stdio.h>
int fuzhi(int x[10]);
int judge(int y[10]);
int iMax = 0;
int iMin = 0;
int main()
{
	int arr[10] ={0};

	printf("请输入十个数\n");
	fuzhi(arr);
	judge(arr);
	
	printf("最大值为%d，最小值为%d。\n",iMax,iMin);
	return 0;

}
int fuzhi(int x[10])
{
	int i = 0;
	while(i<10)
	{
		scanf("%d",&x[i]);
		i++;	
	}

}
int judge(int y[10])
{
	int i = 1;
	iMax = y[0];
	iMin = y[0];
	
	while(i<10)
	{
		if(y[i]>iMax)
		{
			iMax = y[i];
		}
		if(y[i]<iMin)
		{
			iMin = y[i];
		}
		i++;
	}

}
