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

Node* list_combine(Node* head1,Node* head2)
{
	Node* node1 = head1;
	Node* node2 = head2;

	if(node1->data < node2->data)
	{
		for(;node2->next!=NULL;node2 = head2)
		{
			
			node1 = head1;
			for(;node2->data > node1->next->data;node1=node1->next);
	
			head2 = node2->next;
			node2->next = node1->next;
			node1->next = node2;
			
		}
		node1->next->next->next = node2;
		return head1;
		
	}else{
		for(;node1->next!=NULL;node1 = head1)
		{
			
			node2 = head2;
			for(;node1->data > node2->next->data;node2=node2->next);
	
			head1 = node1->next;
			node1->next = node2->next;
			node2->next = node1;
			
		}
		node2->next->next->next = node1;
		return head2;

	}
}

int main()
{
	Node* head1 = create_node(1);
	head1->next = create_node(3);
	head1->next->next = create_node(5);
	head1->next->next->next = create_node(7);
	head1->next->next->next->next = create_node(9);
	
	Node* head2 = create_node(2);
	head2->next = create_node(4);
	head2->next->next = create_node(6);
	head2->next->next->next = create_node(8);
	head2->next->next->next->next = create_node(10);
//	list_combine(head1,head2);
	list_show(list_combine(head2,head1));
//	printf("%d",list_combine(head1,head2)->data);
//	list_show(head1);
//	list_show(head2);
}
	

