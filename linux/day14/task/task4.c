#include <stdio.h>
#include "tree_list.h"

int main()
{
	Tree tree;
	tree_init(&tree);
	for(int i=0; i<6; i++)
	{
		tree_insert(&tree,i);
	}
/*	tree_insert(&tree,4);
	tree_insert(&tree,7);
	tree_insert(&tree,2);
	tree_insert(&tree,1);
	tree_insert(&tree,5);
	tree_insert(&tree,3);
	tree_insert(&tree,8);
	tree_insert(&tree,6);*/

	if(balance(tree.root))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;	
}
