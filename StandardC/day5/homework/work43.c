#include<stdio.h>
#include<assert.h>

int strncmp(const char *s1, const char *s2,size_t n)
{	
	assert(s1!=NULL&&s2!=NULL);
	while(n--&&*s1 == *s2++)
	{
		if(*s1++ == '\0')
			return 0;
	}
	if(++n)
	return(*--s1 > *--s2? 1:-1);
	return 0;
}
int main()
{
	char arr[10] = {0};
	char brr[10] = {0};
	size_t n = 0;
	scanf("%s",arr);
	scanf("%s",brr);
	scanf("%u",&n);
	printf("%d\n",strncmp(arr,brr,n));
	return 0;
}
