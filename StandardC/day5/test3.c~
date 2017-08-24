#include<stdio.h>
int cha(int iA,int iB)
{
	
	int result = 0;
	if(iA>=iB)
		result = iA-iB;
	else
		result = iB-iA;
}
int he(int iA,int iB)
{
	int result = 0;
	result = iA+iB;
}
int main()
{
	int (*pa)(int ,int ) = &cha;
	int (*pb)(int ,int ) = &he;
	printf("%d",pa(1,2));
	printf(" %d\n",pb(1,2));

	
}
