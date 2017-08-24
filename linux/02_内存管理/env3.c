#include <stdio.h>
#include <stdlib.h>

extern char** environ;

void printenv(void)
{
	int i=0;
	printf("-------------------------------------\n");
	for(; environ[i]!=NULL; i++)
	{
		printf("%s\n",environ[i]);
	}
	printf("-------------------------------------\n");
}
int main()
{
	printf("LIBRARY_PATH=%s\n",getenv("LIBRARY_PATH"));	
	printf("CPATH=%s\n",getenv("CPATH"));	
	char env[255] = {};
	sprintf(env,"%s=%s","CPATH","/home/ubuntu/pubic");
	putenv(env);
	printf("CPATH=%s\n",getenv("CPATH"));	
	
	setenv("C_INCLUDE_PATH","/home/ubuntu/public",0);
	setenv("C_INCLUDE_PATH","/home/ubuntu",1);
	unsetenv("CPATH");
	printf("C_INCLUDE_PATH=%s\n",getenv("C_INCLUDE_PATH"));	
	printf("CPATH=%s\n",getenv("CPATH"));	
	printenv();
	clearenv();
	printenv();
}
