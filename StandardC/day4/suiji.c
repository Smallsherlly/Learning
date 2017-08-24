#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int suiji();
int main()
{
	
	
	int arr[6] ={0};
	suiji(arr);
	
	return 0;	
}

int suiji(int x[6])
{
	srand(time(NULL));
	int i = 1,j = 0;
	while(i < 7)
	{
	 	int	iFlag =0;
		
		int iNum = rand()%31+1;

		j =0;
		while(j<i)
		{
			if(iNum == x[j])
			{
				iFlag =0;
			
				break;
			}
			else{
				iFlag = 1;
			}
			j++;
		}
			if(iFlag == 1)
			{
				x[i-1]=iNum;
				i++;
				printf("%d\n",iNum);
			}
		
	}


}
