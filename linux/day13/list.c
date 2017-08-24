#include "list.h"

//创建链表结点
Node* create_node(int data)
{
	Node* node = malloc(sizeof(Node));
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

//初始化链表
void init(List* list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

//释放链表
void deinit(List* list)
{
	while(!empty(list))	pop_head(list);
}

//插入一个头结点
void push_head(List* list,int data)
{
	Node* node = create_node(data);
	if(empty(list))
	{
		list->head = node;
		list->tail = node;
		list->size++;
		return;
	}

	node->next = list->head;
	list->head->prev = node;
	list->head = node;
	list->size++;
}

//插入一个尾结点
void push_tail(List* list,int data)
{
	Node* node = create_node(data);
	if(empty(list))
	{
		list->head = node;
		list->tail = node;
		list->size++;
		return;
	}

	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
	list->size++;
}

//在任意位置插入结点
bool insert(List* list,int index,int data)
{
	if(index < 0 || index >= list->size) return false;
	if(0 == index)
	{
		push_head(list,data);
		return true;
	}
	if(list->size-1 == index)
	{
		push_tail(list,data);
	}

	Node* node = list->head;
	for(int i=0; i<index; i++)
	{
		node = node->next;
	}
	
	Node* new = create_node(data);
	Node* prev = node->prev;

	prev->next = new;
	new->prev = prev;

	new->next = node;
	node->prev = new;

	list->size++;
	return true;
}

//删除头结点
bool pop_head(List* list)
{
	if(empty(list)) return false;
	if(1 == list->size)
	{
		free(list->head);
		init(list);
		return true;
	}

	Node* node = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	list->size--;
	free(node);
	return true;
}

//删除尾结点
bool pop_tail(List* list)
{
	if(empty(list)) return false;
	if(1 == list->size)
	{
		free(list->head);
		init(list);
		return true;
	}
	Node* node = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	list->size--;
	free(node);
	return true;
}
//删除任意位置结点
bool delete(List* list,int index)
{
	if(empty(list)) return false;
	if(index < 0 ||index >= list->size) return false;
	if(0 == index) return pop_head(list);
	if(list->size-1 == index)
		return pop_tail(list);
	Node* node = list->head;
	for(int i=0; i<index; i++)
	{
		node = node->next;
	}
	
	Node* prev = node->prev;
	Node* next = node->next;
	prev->next = next;
	next->prev = prev;
	list->size--;
	free(node);
	return true;
}
//获取头结点
Node* get_head(List* list)
{
	return list->head;
}
//获取尾结点
Node* get_tail(List* list)
{
	return list->tail;
}
//获取任意位置结点
Node* get_node(List* list,int index)
{
	if(index < 0 ||index >= list->size) return NULL;
	Node* node = list->head;
	for(int i=0; i<index; i++)
	{
		node = node->next;
	}

	return node;
}

//更新结点的值
bool updata(List* list,int old,int new)
{
	Node* node = find(list,old);
	if(NULL==node) return false;
	node->data = new;
	return true;
}
//修改任意结点的值
bool modify(List* list,int index,int new)
{
	Node* node = get_node(list,index);
	if(NULL==node) return false;
	node->data = new;
	return true;
}
//判断链表是否为空
bool empty(List* list)
{
	return !list->size;
}
//计算链表结点的数量
size_t size(List* list)
{
	return list->size;
}
//查找结点
Node* find(List* list,int data)
{
	if(0==list->size) return NULL;
	Node* node = list->head;
	while(node!=list->tail->next)
	{
		if(node->data==data)
			return node;
		else
			node = node->next;
	}
	return NULL;
}
//遍历链表
void travel(List* list)
{
	for(Node* node = list->head; node!=list->tail->next; node = node->next)
	{
		printf("%d ",node->data);
	}
	printf("\n");
}

