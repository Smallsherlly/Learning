#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void exchange(char *s1,char *s2)
{
	char *tem = malloc(sizeof(s1>s2?s1:s2)*4) ;
	strcpy(tem,s1);
	strcpy(s1,s2);
	strcpy(s2,tem);
	free(tem);
}
	
int main()
{
	char arr[20] ;
	char brr[20] ;
	scanf("%s",arr);
	scanf("%s",brr);
	exchange(arr,brr);
	printf("%s %s\n",arr,brr);
	
	return 0;	
}
