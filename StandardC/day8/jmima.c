#include<stdio.h>

int main()
{
	FILE *fp = fopen("./mima.txt","r");
	char brr[24] = {0};
	for(int i = 0;i < 7;i++)
	{
		fread(&brr[i],sizeof(char),1,fp);
		brr[i] -=1;
	}
	printf("%s\n",brr);
	fclose(fp);
	return 0;	
}
