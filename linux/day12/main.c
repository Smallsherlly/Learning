#include "tree_list.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	Tree tree;
	tree_init(&tree);
	for(int i=0; i<10; i++)
	{
		//int data = rand() % 100;
		Newinsert(&tree.root,i);
		//tree_insert(&tree,i);
	}
	
	tree_show(&tree);
	/*tree_insert(&tree,50);
	tree_show(&tree);
	tree_modify(&tree,50,-1);
	tree_show(&tree);
	tree_delete(&tree,-1);
	tree_show(&tree);
	tree_deinit(&tree);*/
}
