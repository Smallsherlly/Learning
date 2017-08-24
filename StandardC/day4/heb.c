#include<stdio.h>

int main()
{
	int arr1[5] ={135,643,983,1001,1007};
	int arr2[5] = {564,666,789,999,1000};
	int	brr[10] ={0};
	if(arr1[0]>arr2[0])
	{
		brr[0] = arr2[0];

	}else{
		brr[0] =arr1[0];
		for(int j=0, i =1,k =1 ; k<10 ;k++)
		{
			if(i<5&&j<5)
			{
				if(arr1[i]<arr2[j])
				{
					brr[k] = arr1[i];
					i++;
				}else{
					brr[k] = arr2[j];
					j++;
				}
			}else if(j==5){
				brr[k] = arr1[i];
				i++;
			}
		}
	}
	for(int i =0;i<10;i++)
	{
		printf("%d ",brr[i]);
	}
	
	return 0;	
}
