#include<stdio.h>
#include<stdlib.h>
size_t mystrlen(const char *s)
{
	size_t len = 0;
	while(*s++)
		len++;
	return len;
	
}
int main()
{
	char arr[10] = {};
	scanf("%s",arr);
	printf("%u %u\n",mystrlen(arr),strlen(arr));
}
