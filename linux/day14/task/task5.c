#include <stdio.h>
#include "tree_list.h"

int main()
{
	Tree tree,tree1;
	tree_init(&tree);
	tree_init(&tree1);
	for(int i=0; i<6; i++)
	{
		tree_insert(&tree1,i);
	}
	tree_insert(&tree,4);
	tree_insert(&tree,7);
	tree_insert(&tree,2);
	tree_insert(&tree,1);
	tree_insert(&tree,5);
	tree_insert(&tree,3);
	tree_insert(&tree,8);
	tree_insert(&tree,6);
	if(findK(&tree,6)==NULL)
		printf("lose");
	else
		printf("%d\n",findK(&tree,6)->data);
	return 0;	
}
