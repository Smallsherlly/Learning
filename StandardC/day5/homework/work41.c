#include<stdio.h>

char *mystrncat(char *dest,const char *src,size_t n)
{
	char *pdest = dest;
	while(*pdest++);
	pdest--;
	while(n-->0)
	{
		*pdest++ = *src++;
		
	}
	return dest;
}
int main()
{
	char arr[10] = {0};
	char brr[10] = {0};
	size_t n = 0;
	scanf("%s",arr);
	scanf("%s",brr);
	scanf("%u",&n);
	mystrncat(arr,brr,n);
	printf("%s\n",arr);
	return 0;



}

