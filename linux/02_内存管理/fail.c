#include <stdio.h>
#include <string.h>

char* strmax(char* str1,char* str2)
{
	if(NULL == str1 || NULL == str2)
	{
		return NULL;
	}
	else
	{
		//1 >,0 =,-1 <
		if(strcmp(str1,str2)>0)
		{
			return str1;
		}
		else
			return str2;
	}

	return str1&&str2 ? (strcmp(str1,str2)>0?str1:str2) : NULL;
}

int main()
{
	char* str = strmax("hello",NULL);
	if(NULL == str)
	{
		printf("获取最大的字符串失败！\n");
		return -1;
	}
	printf("最大字符串%s\n",str);
	return 0;
}
