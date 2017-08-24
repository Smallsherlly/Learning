#include<stdio.h>
#include<string.h>

void cmp(char (*s)[10],int *count)
{
	int n =0;
	int i =0;
	//int count[4] ={0};
	while(n<4)
	{
		while(i<10)
		{
			if(*(*(s+n)+i)!='\0'/*&&*(*(s+n)+i)!=' '*/)
			{
				count[n]++;
				i++;
			}else
				break;
			
		}
		n++;
		i =0;
	}
}


int main()
{
	char arr[4][10] ={0};
	int count[4] ={0};
	int iMax = 0,iMin = 50;
	int xmax = 0,xmin =0;
	for(int i =0;i<4;i++)
	{
		scanf("%s",arr[i]);
	}
	cmp(arr,count);
	for(int i =0;i<4;i++)
	{
		if(count[i]>iMax)
		{
			iMax = count[i];
			xmax =i ;
		}

		if(count[i]<iMin)
		{
			iMin = count[i];
			xmin = i;
		}
	}
	
	printf("%s %s\n",arr[xmax],arr[xmin]);
	
	return 0;	
}
