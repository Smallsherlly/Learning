#include "tree_list.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	Tree tree;
	tree_init(&tree);
	printf("插入顺序：");
	for(int i=0; i<10; i++)
	{
		int data = rand() % 10;
		printf("%d ",data);
		tree_insert(&tree,data);
	}
	printf("\n");
	tree_show(&tree);
	tree_mirror(&tree);
	tree_show(&tree);
}
