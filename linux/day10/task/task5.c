#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* create_node(int data)
{
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;
	return node;
}
Node* create_list(size_t len)
{
	if(0 == len) return NULL;

	Node* head = create_node(0);
	Node* node = head;
	
	for(int i = 1; i < len; i++)
	{
		node->next = create_node(i);
		node = node->next;
	}
	
	return head;
}

void list_show(Node* head)
{
	for(Node* node=head;node!=NULL;node = node->next)
	{
		printf("%d ",node->data);
	}
	printf("\n");

}

//在链表中的指定位置插入一个节点
//C99标准中新加入的数据类型，_Bool是一种关键字，宽度一个字节
_Bool list_insert(Node* head,int index,int data)
{
	Node* node = head;
	for(int i = 0; i<index-1; i++)
	{
		if(NULL == node) return 0;
		node = node->next;
	}
	Node* new = create_node(data);
	new->next = node->next;
	node->next = new;
	return 1;
}
_Bool list_del(Node* head,int index)
{
	Node* node = head;
	for(int i=0; i<index-1; i++)
	{
		if(NULL == node) return 0;
		node = node->next;
	}

	//备份要删除的节点的地址
	Node* temp = node->next;
	//把要删除节点的前后连接起来
	node->next = temp->next;
	free(temp);
	return 1;
}

_Bool list_change(Node* head,int index,int data)
{
	Node* node = head;
	for(int i=0; i<index; i++)
	{
		if(NULL == node)return 0;
		node = node->next;
	}

	node->data = data;
	return 1;
}

Node* list_find(Node* head,int data)
{
	for(Node* node=head; node!=NULL; node=node->next)
	{
		if(node->data == data)
			return node;
	}
	return NULL;

}

int list_findNum(Node* head,int n)
{
	Node* node = head;
	int iCount = 0;
	for(;node!=NULL; node = node->next)
	{
		iCount++;
	}
//	printf("%d",list_find(head,iCount-n)->data);
	node = head;
	for(int i=0; i<iCount-n; i++)
	{
		node = node->next;
	}
	printf("%d",node->data);

}

_Bool checkRound(Node* list)
{
	Node* node1 = list;
	Node* node2 = list;
	while(1)
	{
		if(node1->next->next!=NULL&&node2->next!=NULL)
		{
			node1 = node1->next->next;
			node2 = node2->next;
			if(node1->data==node2->data)
				break;
		}else{
			return 0;
		}
	}
	return 1;
}

int main()
{
	Node* list1 = create_list(10);
	Node* node1 = list1;
	Node* node2 = list1;
	for(;node2->data!=5;node2=node2->next);
	for(;node1->next!=NULL;node1=node1->next);
	node1->next = node2;
	Node* list2 = create_list(2);
	if(checkRound(list1)==1)
		printf("YES\n");
	else
		printf("NO\n");
	if(checkRound(list2)==1)
		printf("YES\n");
	else
		printf("NO\n");
}
	

