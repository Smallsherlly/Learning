#include<stdio.h>
#include<string.h>

void moveright(char *s,int n,int iNum)
{
	int count = iNum;
	int len = iNum-1;
	while(n--)
	{
		count = iNum;
		
		while(count)
		{
			if(len+1<5)
			{
				s[len+1]=s[len];
				count--;
				if(len-1<0)
					len = 4;
				else
					len--;
			}else if(len+1 == 5)
			{
				s[0] = s[len];
				count--;
				if(len-1<0)
					len = 4;
				else
					len--;
			}
			if(count==0)
			{
				if(len==4)
					len = 0;
				else
					len++;				
				s[len]=' ';
			}
		}
		if(len+iNum<=4)
		{
			len += iNum;
		}else{
			len =len+iNum-5;
		}
	}
	
}

int main()
{
	char arr[5] = "abcd";
	int n = 0;
	scanf("%d",&n);
	moveright(arr,n,4);
	printf("%s\n",arr);
	return 0;	
}
