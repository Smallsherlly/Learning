#include<stdio.h>

int main()
{
	int iN = 0,iCount = 1;
	scanf("%d",&iN);
	int arr[iN][iN];
	int i = 0,j = 0;
	int iRound = 0;
	int iM = iN;
	int iNum = 0;
	for(;iRound < iM/2+iM%2;)
	{
		for(;j < iN;j++,iCount++)//行赋值循环
		{
			if(iNum==iM*iM)
			break;
			arr[i][j] = iCount;
			iNum++;		
		}

		for(j--,i++;i < iN;i++,iCount++)
		{
			if(iNum==iM*iM)
			break;
			arr[i][j] = iCount;
			iNum++;
			
		}

		for(i--,j--;j >= iRound;j--,iCount++)
		{
			if(iNum==iM*iM)
			break;
			arr[i][j] = iCount;
			iNum++;
		}
//printf("%d\n",iCount);
		for(j++,i--;i > iRound;i--,iCount++)
		{
			if(iNum==iM*iM)
			break;
			arr[i][j] = iCount;
			iNum++;
		}
		
		//printf("%d %d\n",i,j);
		//printf("%d\n",iCount);
		i++;
		j++;
		iN = iN-1;
		iRound++;
	
	}
	
	for(int a = 0;a<iM;a++)
	{
		for(int b = 0;b<iM;b++)
		{
			printf("%2d ",arr[a][b]);
			
			
		}
		printf("\n");
		
	}
	return 0;	
}
