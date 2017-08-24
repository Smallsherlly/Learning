#include <stdio.h>
#include "tree_list.h"
int main()
{
	Tree tree;
	tree_init(&tree);
	tree_insert(&tree,5);
	tree_insert(&tree,1);
	tree_insert(&tree,2);
	tree_insert(&tree,7);
	tree_insert(&tree,6);
	tree_show(&tree);
	show_tree_list(tree_list(&tree));
	
}



