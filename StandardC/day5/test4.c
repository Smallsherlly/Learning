
#include<stdio.h>
int mystrlen(const char *s);
int main()
{
	char arr[] = {};
	scanf("%s",arr);
	printf("%d\n",mystrlen(arr));
	
	return 0;	
}
int mystrlen(const char *s)
{
	int count = 0;
	while(*(s+count)!='\0')
	{
		count++;
	}
	
	return count;
}
