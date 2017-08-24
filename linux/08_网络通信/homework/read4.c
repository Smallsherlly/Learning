#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp = fopen("ip.dat","r");
	if(0 > fp)
	{
		perror("fopen");
		return -1;
	}
	printf("读取成功！\n");
	char buf[255] = {};
	int i = 0;
	int ret = 0;
	char s[10] = "inet";
	do
	{	
		ret = fscanf(fp,"%s",buf);
		if(!strcmp(s,buf))
		{
			fscanf(fp,"%s",buf);
			printf("%s\n",buf);
		}
	}while(ret>0);

	return 0;
}
