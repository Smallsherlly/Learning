#include <stdio.h>
#include <string.h>

//链式调用
char* scpy(char* st1,char* st2)
{
	if(str1==NULL||str2==NULL)
		return NULL;
	char* str1 = st1;
	char* str2 = st2;
	if(str1<str2&&str1+strlen(str2)>str2)
	{
		int len = strlen(str2);
		while(len--)
			str2[len] = str1[len];
		return st2;
	}
	while(*str1!='\0'&&*str2!='\0')
	{
		*str2++=*str1;
		str1++;
	}
	*str2 = '\0';
	return st2;
}

int main()
{
	char str1[] = "abc";
	char str2[] = "ghijk";
	printf("%s\n",scpy(str2+2,str2));
}
