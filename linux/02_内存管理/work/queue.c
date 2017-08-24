#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct Queue
{
	int* arr;
	int head;
	int tail;
	int cap;
	int num;
}Queue;
//初始化队列
void queue_init(Queue* queue,int cap)
{
	queue->arr = sbrk(0);
	brk(queue->arr+sizeof(int)*cap);
	queue->head = 0;
	queue->tail = 0;
	queue->num = 0;
	queue->cap = cap;
}
//释放队列
bool queue_deinit(Queue* queue)
{
	brk(queue->arr);
	queue->arr = NULL;
	queue->head = 0;
	queue->tail = 0;
	queue->cap = 0;
	queue->num = 0;
}
//判断队列是否为空
bool queue_empty(Queue* queue)
{
	return !queue->num;
}
//判断队列是否已满
bool queue_full(Queue* queue)
{
	return queue->num == queue->cap;
}
//入队
bool queue_push(Queue* queue,int data)
{
	if(queue_full(queue)) return false;
	queue->arr[queue->tail%queue->cap] = data;
	queue->tail++;
	
	queue->num++;
	return true;
}
//出队
bool queue_pop(Queue* queue,int* data_p)
{
	if(queue_empty(queue)) return false;
	*data_p = queue->arr[queue->head % queue->cap];
	queue->head++;
	queue->num--;
	return true;
}
//查看队头
int queue_head(Queue* queue)
{
	return queue->arr[queue->head%queue->cap];
}
//查看队尾
int queue_tail(Queue* queue)
{
	return queue->arr[queue->tail%queue->cap];
}
//计算队列的剩余容量
int queue_size(Queue* queue)
{
	return queue->cap - queue->num;
}
int main()
{
	Queue queue;
	queue_init(&queue,10);
	printf("入队的顺序：");
	int data = 0;
	while(!queue_full(&queue))
	{
		printf("%d ",data);
		queue_push(&queue,data++);
	}
	printf("\n");
	
	printf("出队的顺序：");
	
	while(!queue_empty(&queue))
	{
		int data;
		queue_pop(&queue,&data);
		printf("%d ",data);
	}
	printf("\n");
	queue_deinit(&queue);
	
}

