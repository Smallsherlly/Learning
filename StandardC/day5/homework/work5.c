#include<stdio.h>
#include<assert.h>
#include<string.h>
int iNum(char (*s1)[20],const char *s2)
{
	size_t n = 0;
	//assert(s1!=NULL&&s2!=NULL);
	
		while(*s2==' ')
		s2++;

	while(*s2!='\0')
	{
		while(*s2!=' '&&*s2!='\0')
		{
			strncat(*(s1+n),s2++,1);
		}
		while(*s2++==' ');
		n++;
		s2--;
	}
	return n;
}

int main()
{
	char arr[20] = {0};
	char brr[20][20] = {0};
	int n = 0;
	gets(arr);
	
	n = iNum(brr,arr);
	printf("%d\n",n);
	
	for(int i = 0;i < n;i++)
	printf("%s ",*(brr+i));
	printf("\n");
	return 0;	
}

