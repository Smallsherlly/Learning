#include<stdio.h>
int exchange();
int main()
{
	int a = 10,b = 20;
	int *pa = &a,*pb = &b;
	exchange(&pa,&pb);
	printf("%d,%d",*pa,*pb);
	return 0 ;	
}
int exchange(int **ppa,int **ppb)
{
	int *t = *ppa;
	
	*ppa = *ppb;
	*ppb = t;
	
	
}

