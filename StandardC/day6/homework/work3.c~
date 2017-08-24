#include<stdio.h>

int find(char (*s1)[10],char *s2)
{
	int len = 0;
	int n = 0;
	int iNum = 0;
	while(n<4)
	{
		len = 0;
		while(len<10)
		{
			if(*(s1[n]+len)==*(s2+len))
			{
				if(s2[len]=='\0')
				{
					iNum++;
					break;
				}
				len++;
			}else
			break;
		}
		n++;	
		
	}
	return iNum;
}
int main()
{
	char arr[4][10] = {"asdf","asdf","abc","s"};
	char brr[10] = {0};
	scanf("%s",brr);
	printf("%d",find(arr,brr));
	return 0;	
}
