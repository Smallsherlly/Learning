#include<stdio.h>

int main()
{
	FILE *fp = fopen("./a.txt","w");
	if(NULL == fp)
	{
		printf("0\n");
	}else{
		printf("1\n");
	}
	return 0;	
}
