#include<stdio.h>
int jc(int y[10]);
int main()
{
	int arr[10] = {1,1,1,1,1,1,1,1,1,1};

	jc(arr);
	
	return 0;	
}
int jc(int y[10])
{
	int i=0,j=2;
	int x =0;
	while(i<=9)
	{
		while(j<=(i+1))
		{
			y[i] *=j;
			j++;
		}
		
		j = 2;
		i++;
	}
	while(x<=9)
	{
		printf("%d！=%d  ",x+1,y[x]);
		x++;
	}



}
