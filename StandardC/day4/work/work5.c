#include<stdio.h>
int sxh();
int main()
{
	sxh();
	
	
	
		return 0;
}

int sxh()
{
	int iNum = 100;
	int ia = 0,ib = 0,ic = 0;
	
	while(iNum < 999)
	{
		ia = iNum/100;
		ib = (iNum%100)/10;
		ic = iNum%10;
		 if(iNum == ia*ia*ia+ib*ib*ib+ic*ic*ic)
		{
			printf("%d是水仙花数\n",iNum);
		}
		iNum++;
	}




}
