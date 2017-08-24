#include<stdio.h>
int fuzhi(int x[20]);
int iCount(int y[20]);
int out(int z[20]);
int main()
{
	int arr[20] = {0};
	
	
	fuzhi(arr);
	iCount(arr);
	out(arr);
	
	
	return 0;	
}

int fuzhi(int x[20])
{
	int i = 0;
	while(i<20)
	{
		x[i] =i;
		i++;
	}
}
int iCount(int y[20])
{
	int count = 0;
	int c = 0;
	int j = 1;
	while(count<19)
	{
		j = 1;
		while(j<=3)
		{
			if(c <= 19)
			{
				if(y[c]!=-1)
				{
					if(j==3)
					{
						j++;
						count++;
						y[c] = -1;
					}else {
						j++;
					}
				}
			}else{
				c=-1;
			}
			//j++;
			c++;
		}
	}
}

int out(int z[20])
{
	int i = 0;
	while(i<20)
	{
		if(z[i]!=-1)
		printf("%d\n",z[i]);
		i++;
	}
	
}



