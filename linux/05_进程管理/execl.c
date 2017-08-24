#include <stdio.h>
#include <unistd.h>



int main()
{
	int ret = execl("/bin/ls","ls","-l",NULL);
	if(0 > ret)
	{
		perror("execl");
		return -1;
	}
	
	return 0;	
}
