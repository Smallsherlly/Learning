#include <stdio.h>

int slen(char* arr)
 {
	 if(NULL==arr)
		 return -1;
	 int i = 0;
	while(arr[i]!='\0')
	{
		i++;
	}
	return i;
 }

int main()
{
	char str[] = "hello";
	if(slen(str)==-1)
	{
		printf("lose\n");
	}
	else
		printf("%d\n",slen(str));
}
