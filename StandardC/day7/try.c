#include<stdio.h>
int  iOut(char *arr)
{
	if(*arr>*(arr+1))
		return 1;
	else
		return 0;
	
}

int main()
{
	int a = 0x123456;
	char *arr = (char*)&a;
	printf("%d",iOut(arr));
	
	return 0;	
}
