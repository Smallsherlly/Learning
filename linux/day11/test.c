#include "stack_list.h"

Node* node_create(int data)
{
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
}

typedef struct Queue
{
	Stack* s1;
	Stack* s2;
	size_t cap;
}Queue;

void queue_init(Queue* queue,size_t cap)
{
	queue->s1 = malloc(sizeof(Stack));
	queue->s2 = malloc(sizeof(Stack));
	queue->cap = cap;
	stack_init(queue->s1,cap);
	stack_init(queue->s2,cap);
}

void queue_deinit(Queue* queue)
{
	stack_deinit(queue->s1);
	stack_deinit(queue->s2);
}

bool queue_push(Queue* queue,int data)
{
	if(stack_full(queue->s1)) return false;
	stack_push(queue->s1,data);
	return true;
}

bool queue_pop(Queue* queue,int* data)
{
	if(stack_empty(queue->s1)&&stack_empty(queue->s2))
		return false;
	if(stack_empty(queue->s2))
	{
		while(!stack_empty(queue->s1))
		{
			int data = stack_top(queue->s1)->data;
			stack_push(queue->s2,data);
			stack_pop(queue->s1);
		}
	}
	*data = stack_top(queue->s2)->data;
	stack_pop(queue->s2);
	return true;
}

int main()
{
	Queue queue;
	queue_init(&queue,20);
	printf("入队顺序：");
	for(int i=0; i<10; i++)
	{
		printf("%d ",i);
		queue_push(&queue,i);
	}
	printf("\n");
	printf("出队顺序：");
	for(int i=0; i<10; i++)
	{
		int data;
		queue_pop(&queue,&data);
		printf("%d ",data);
	}
	printf("\n");

}
