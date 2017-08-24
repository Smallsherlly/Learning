#include<stdio.h>

#include<stdbool.h>

#include<stdlib.h>

typedef struct Node
{

	int data;//数据区

	struct Node* next;//指针区：下一个节点

}Node;

Node* create_node(int data)//创建节点
{

	Node* node=malloc(sizeof(Node));
	
	node->next=NULL;
	
	node->data=data;
	
	return node;

}

void list_add(Node* list,int data)//末尾增加
{

	while(list->next)

	{
		
		list=list->next;
	
	}

	list->next=create_node(data);

}

bool list_del(Node* list,int data)//按值删除
{

	Node* node=list->next;
	while(node->next)

	{

		if(node->next->data==data)

		{

			Node* temp=node->next;

			node->next=temp->next;

			free(temp);

			return true;

		}

		node=node->next;

	}

	node=list->next;

	if(node->data==data)

	{

		list->next=node->next;
	
		free(node);

		return true;

	}

	return false;

}

bool list_change(Node* list,int data,int newData)//按值修改
{

	Node* node=list->next;
	while(node)

	{

		if(node->data==data)

		{

			node->data=newData;

			return true;

		}

		node=node->next;

	}

	return false;
}
void list_show(Node* list)
{

	Node* node=list->next;
	while(node)

	{

		printf("%d ",node->data);

		node=node->next;
	}
}
int main()
{
	Node list={0,NULL};
	for(int i=0;i<10;i++){
		list_add(&list,i);
	}
	list_show(&list);
}
