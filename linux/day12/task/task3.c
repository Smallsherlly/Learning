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
		int data = rand() % 10;
		tree_insert(&tree,data);
	}
	printf("该树的密度为%d\n",tree_show(&tree));
}
