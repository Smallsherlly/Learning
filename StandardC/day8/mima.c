#include<stdio.h>


int main()
{
	FILE *fp = fopen("./mima.txt","w");
	char arr[24] ="1314520";
	for(int i = 0;i <7;i++)
	{
		arr[i] = arr[i]+1;
		fwrite(&arr[i],sizeof(char),1,fp);
	}

	fclose(fp);
	
	
	
	return 0;	
}
