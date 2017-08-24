#include<stdio.h>
#include<assert.h>
char *mystrncpy(char *dest,const char *src,size_t n)
{
	assert(dest!=NULL&&src!=NULL);
	char *pdest=dest;
	while(n--)
	{	
		*pdest++ =*src++;
	}
	*pdest = '\0';
	return dest;
}
int main()
{
	char arr[10] = {0};
	char brr[10] = {0};
	size_t n =0;
	scanf("%s",arr);
	scanf("%s",brr);
	scanf("%u",&n);
	printf("%s\n",mystrncpy(arr,brr,n));
	return 0;	
}
