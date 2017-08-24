#include <stdio.h>
#include <unistd.h>

int main()
{
	int i = 1000;
	int* p = sbrk(0);
	int* pp = p;
	for(; i<10000; i++)
	{
		int j = 2;
		int flag = 0;
		for(; j<i/2;j++)
		{
			if(i%j==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			sbrk(4);
			*p = i;
			p = sbrk(0);
		}
	}
	printf("%d",*p);
	while(*pp!=0)
	{
		printf("%d ",*pp);
		pp++;
	}
}
