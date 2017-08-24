#include<stdio.h>
int jc(int x);
int main()
{
	int i = 0,iRe = 0;
	printf("请输入一个整数\n");
	scanf("%d",&i);
	iRe = jc(i);
	printf("%d!=%d\n",i,iRe);
	
	
	
	
	return 0;	
}

int jc(int x)
{
	int i = 2;
	int jc = 1;
	if(x == 1)
		return 1;
	while(i<=x)
	{
		jc *=i;
		i++;
	}
	return jc;

}
