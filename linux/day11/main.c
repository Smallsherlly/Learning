#include "queue_list.h"

int main()
{
	Queue queue;
	queue_init(&queue,10);
	printf("入队顺序：");
	for(int i=0; i<10; i++)
	{
		queue_push(&queue,i);
		printf("%d ",queue_tail(&queue)->data);
	}
	printf("\n");
	printf("出队顺序：");
	while(!queue_empty(&queue))
	{
		printf("%d ",queue_head(&queue)->data);
		queue_pop(&queue);
	}
	printf("\n");
}
