#include <stdio.h>
#include "tree_list.h"
int main()
{
	int a[8] = {1,2,4,7,3,5,6,8};
	int b[8] = {4,7,2,1,5,3,8,6};
	int c[3] = {2,4,7};
	int d[3] = {4,2,7};
	Tree tree = recover(a,b,8);
	tree_show(&tree);	
}

