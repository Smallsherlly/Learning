#include <stdio.h>

int main(int argc,char** argv,char** environ)
{
	int i = 0;
	for(;environ[i] !=NULL; i++)
	{
		printf("%s\n",environ[i]);

	}
}
