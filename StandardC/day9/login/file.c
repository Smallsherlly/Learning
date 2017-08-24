#include"file.h"
#include<stdio.h>

void loadFile(const char *fileName,UAP userPass[],int iLen)
{
	FILE *fp = fopen(filename,"r");
	if(NULL==fp)
	{
		printf("");
		return;
	}
	for(int i = 0;i <iLen;i++)
	{
		int ret = fread(userPass[i],sizeof(UAP),1,fp);
		if(ret<=0)
		{
			break;
		}
		fclose(fp);
}

void saveFile(const char *fileName,UAP userPass[],int iLen)
{



}

