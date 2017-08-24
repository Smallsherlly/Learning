#include <stdio.h>
#include <unistd.h>

int main()
{
	char* argv[] = {"ls","-l",NULL};
	char* path = "/bin/ls";

	int ret = execv(path,argv);
	if(0 > ret)
	{
		perror("execv");
		return -1;
	}

}
