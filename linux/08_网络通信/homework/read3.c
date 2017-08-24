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
	char buf[255][255] = {};
	int i = 0;
	int ret = 1;
	int count = 0;
	char s[10] = "inet";
	for(; ret>0; i++)
	{	
		ret = fscanf(fp,"%s",buf[i]);
		if(0 > ret)
		{
			perror("fscanf");
			return -1;
		}
		if(!strcmp(s,buf[i]))
		{
			i++;
			count++;
			fscanf(fp,"%s",buf[i]);
			printf("%s\n",buf[i]);
			if(count == 2)
				break;
		}
	}
/*	for(;i<7;i++)
	{
		printf("%s\n",buf[i]);
	}*/
	return 0;
		
}
