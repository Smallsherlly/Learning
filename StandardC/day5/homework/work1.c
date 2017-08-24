#include<stdio.h>
#include<assert.h>
#include<string.h>
int mystrcmp(const char *s1,const char *s2)
{
	
	assert(s1!=NULL&&s2!=NULL);
	while(*s1++==*s2++)
	{
		if(*s1=='\0'&&*s2=='\0')
		return 0;
	}
	return *--s1>*--s2?1:-1;
}
int main()
{
	char arr[4] = "ca";
	char brr[4] = "cbc";
	printf("%d\n",mystrcmp(arr,brr));
/*	char a = 'a';
	char b = 'c';
	printf("%d\n",a-b);*/
	return 0;	
}


