#include<stdio.h>


int main(int argc,char * argv[])
{
	FILE *fp1 = fopen(argv[1],"r+");
	FILE *fp2 = fopen(argv[2],"w+");
	if(argc<3)
	{
		printf("a.out filename1 filename2");
		return -1;
	}
	//for(int i = 0; i<4;i++)
	while(!feof(fp1))	
	{
		char c = 0;
//		fread(&c,sizeof(char),1,fp1);
//		fwrite(&c,sizeof(char),1,fp2);
		
		c = fgetc(fp1);
		if(c==EOF)
		{
			break;
		}else
		fputc(c,fp2);
		
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;	
}
