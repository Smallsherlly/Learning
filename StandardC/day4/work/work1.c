#include<stdio.h>
int plus(int max,int min);
int main()
{
	int iM = 0,iN = 0,iSum =0 ;
	double iNum = 0;
	int iMax = 0,iMin = 0;
	printf("请输入m和n\n");
	scanf("%d %d",&iM,&iN);
	if(iM>iN)
	{
		iMax = iM;
		iMin = iN;
	}else{
		iMax = iN;
		iMin = iM;
	}
	iSum=plus(iMax,iMin);
	
	
		iNum = iMax-iMin +1;
	
	printf("所有整数之和为%d,平均值为%.2f\n",iSum,iSum/iNum);
	
	return 0;
}
int plus(int max,int min)
{
	int sum;
	int i = min;
	while(i<=max)
	{
		sum += i;
		i++;
	} 
	return sum;
}
