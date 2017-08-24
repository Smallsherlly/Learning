#include<stdio.h>
int huitu();
int main()
{
	int iN = 0;
	printf("请输入n的值：\n");
	scanf("%d",&iN);
	if(iN%2 == 1)
	{
		
		
		huitu(iN);


	}else{
		printf("该值是偶数，无法打印。\n");
	}
	return 0;	
}

int huitu(int iN)
{
	int i = 1,j = 1;
	while(i <= iN)
		{
			if(i<=(iN-1)/2)
			{	
				j = 1;
				while(j <= (iN+1)/2-i)
				{
					printf(" ");
					j++;
				}
				j = 1;
				while(j <= 2*i-1)
				{
					printf("*");
					j++;
				}
				printf("\n");
			}else{
				j = 1;
				while(j <= i-(iN+2)/2)
				{
					printf(" ");
					j++;
				}
				j = 1;
				while(j <= iN-2*(i-(iN+1)/2))
				{
					printf("*");
					j++;
				}
				printf("\n");
			}
			i++;
		}



}
