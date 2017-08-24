#include <stdio.h>
#include "tree_list.h"

int main()
{
	int a[6] = {1,3,2,6,5,4};
	int b[6] = {1,2,3,7,5,6};
	if(houxu(b,6))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;	
}
