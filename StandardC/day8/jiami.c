#include<stdio.h>


int main()
{
	FILE *fp = fopen("./mima.txt","r+");
	char arr[200] = {0};
	int i = 0;
	while(!feof(fp))
	{
//		char arr[200] = {0};
		
		arr[i] = ~fgetc(fp);
		i++;
	}
//	fclose(fp);
//	fp = fopen("./mima.txt","r+");
//	rewind(fp);

	i--;
	fseek(fp,-i,SEEK_CUR);
//三种回到开头的方式任选一种
	//for(int j = 0;j < i;j++)
	int j = 0;
	while(!feof(fp)&&j<i)	
	{
		
		fputc(arr[j],fp);
		j++;		
	}
		
	fclose(fp);
	return 0;
}
