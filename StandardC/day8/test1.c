#include<stdio.h>

int main()
{
	int iNum = 10;
	float fNum = 3.14;
	char str[20] = {0};
	sprintf(str,"iNum=%d,fNum=%g",iNum,fNum);
	printf("%s\n",str);
	return 0;
}
