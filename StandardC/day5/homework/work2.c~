#include<stdio.h>
#include<assert.h>
int iIn();
char arr[10] = "silence";//"silence";
char brr[10] = {0};
char crr[20] = "1314520";
char drr[20] = {};
int mystrcmp(const char *s1,const char *s2)
{
	assert(s1!=NULL&&s2!=NULL);
	
	while(*s1++==*s2++)
	{
		if(*s1=='\0'&&*s2=='\0')
			return 0;
	}
	if(*--s1>*--s2)
		return 1;
	else
		return -1;
	
}
int main()
{
	
	int iResult = 0;
	iIn();
	if(mystrcmp(arr,brr)==0&&mystrcmp(crr,drr)==0)
	{
		printf("登录成功！\n");
	}else{
		while(3-iResult)
		{	
			printf("登录失败，请重新输入。你还有%d次输入机会。\n",3-(++iResult));
			iIn();
			if(mystrcmp(arr,brr)==0&&mystrcmp(crr,drr)==0)
			{
				printf("登录成功！\n");
				return 0;
			}
		}
		
		printf("登录失败!");
	}


	return 0;	
}
int iIn()
{
	printf("请输入用户名：\n");
	scanf("%s",brr);
	printf("请输入密码：\n");
	scanf("%s",drr);

}


