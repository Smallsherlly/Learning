#include<stdio.h>
#include<string.h>
char change(char *s)
{
	for(int i = 0;s[i]!='\0';i++)
	{
		if(s[i]>=65&&s[i]<=90)
		
		s[i]=s[i]+32;
	}
}
int main()
{
	 char arr[20] = {0};
	scanf("%s",arr);
	
	change(arr);

	
		printf("%s\n",arr);
	
}
