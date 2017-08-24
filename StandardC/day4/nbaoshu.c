#include<stdio.h>

int main()
{
	int iNum = 0;
	int count = 0;
	int c = 0;
	printf("请输入小孩的个数：\n");
	scanf("%d",&iNum);
	int arr[iNum];
	for(int i = 0;i<iNum;i++)
	{
		arr[i] =i;
		
	}
	for(;count<iNum-1;)
	{
		for(int j =1;j<=3;c++)
		{
			if(c <= iNum-1)
			{
				if(arr[c]!=-1)
				{
					if(j==3)
					{
						j++;
						count++;
						arr[c] = -1;
					}else {
						j++;
					}
				}
			}else
				c=-1;
		}
	}
	for(int i =0;i<iNum;i++)
	{
		if(arr[i]!=-1)
		printf("最后剩下的小孩编号为%d。\n",arr[i]);
	}
	
	return 0;	
}
