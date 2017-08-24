#include "tree_list.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	Tree tree1,tree2;
	tree_init(&tree1);
	tree_init(&tree2);
	for(int i=0; i<10; i++)
	{
		tree_insert(&tree1,i);
	}
	printf("\n");
	tree_show(&tree1);
	for(int i=3; i<7; i++)
	{
		tree_insert(&tree2,i);
	}
	tree_show(&tree2);
	printf("树2%s树1的子树。",tree_belong(tree1.root,tree2.root)?"是":"不是");
}
