#include <stdio.h>

int main()
{
	int i = 0;
	for(; i<2; i++)
	{
		fork();
		printf("*");
	}
	
}
