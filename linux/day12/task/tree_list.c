#include "tree_list.h"
#include <malloc.h>
#include <math.h>
//创建树节点
Node* create_node(int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//树初始化
void tree_init(Tree* tree)
{
	tree->root = NULL;
	tree->size = 0;
}
void deinit(Node* root)
{
	if(root ==NULL) return;
	deinit(root->left);
	deinit(root->right);
	free(root);
}
//树释放
void tree_deinit(Tree* tree)
{
	deinit(tree->root);
	tree->root = NULL;
}
int iCount = 0;
int iNum = 1;
//向树中插入一个节点
static void insert(Node** root,Node* node)
{
	if(*root == NULL)
	{
		*root = node;
	}
	else
	{
		if((*root)->data > node->data)
		{
			insert(&(*root)->left,node);
			iNum++;
		}
		else
		{
			insert(&(*root)->right,node);
			iNum++;
		}
	}
	if(iCount < iNum)iCount = iNum;
}
//向树中插入一个节点
void tree_insert(Tree* tree,int data)
{
	iNum = 1;
	insert(&tree->root,create_node(data));
}
Node* find(Node* root,int data);

bool delete(Node** root,int data)
{
	if(*root == NULL) return false;
	if((*root)->data == data)
	{
		Node* temp = *root;
		Node* right = (*root)->right;

		*root = (*root)->left;
		insert(root,right);
		free(temp);
		return true;

	}
	if((*root)->data > data)
	{
		delete(&(*root)->left,data);
	}
	else
	{
		delete(&(*root)->right,data);
	}

}
//从树中删除一个节点
bool tree_delete(Tree* tree,int data)
{
	return delete(&tree->root,data);
}
//修改指定的值
bool tree_modify(Tree* tree,int old,int new)
{
	if(delete(&tree->root,old));
	{
		insert(&tree->root,create_node(new));
		return true;
	}
	return false;

}

Node* find(Node* root,int data)
{
	if(root == NULL) return NULL;
	if(root->data == data) return root;
	if(root->data > data)
	{
		find(root->left,data);
	}
	else
	{
		find(root->right,data);
	}
}
//查找指定值一个节点
Node* tree_find(Tree* tree,int data)
{
	return find(tree->root,data);
}
void ergodic(Node* root,size_t size)
{
	if(root == NULL) return;
	size++;
	ergodic(root->left,size);
	printf("%d ",root->data);
	ergodic(root->right,size);
}
//中序遍历树
size_t tree_show(Tree* tree)
{
	tree->size = 0;
	ergodic(tree->root,tree->size);
	printf("\n");
	printf("该树的深度为：");
	printf("%d",iCount);
	printf("\n");
	iCount = 0;
}
void wergodic(Node* root,int i)
{
	iNum++;
	Node* node = root;
	if(node==NULL)
	{
		return;
	}
	if(i==iNum)
	{
		printf("%d ",node->data);
		return;
	}
	wergodic(node->left,i);
	iNum--;
	wergodic(node->right,i);
	iNum--;

}
//广度优先遍历

void tree_wide(Tree* tree)
{
	int i = 1;                       //iCount为二叉树的深度
	if(tree->root == NULL) return;
	Node* node = tree->root;
	while(i <= iCount)//逐层打印，i为层数
	{
		if(iCount==1)
		{
			printf("%d",node->data);
			break;
		}
		else
		{
			iNum = 0;
			wergodic(node,i);
			printf("\n");
		}
		i++;
	}
}

void mirror(Node* node)
{
	if(NULL==node) return;
	Node* temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirror(node->left);
	mirror(node->right);
}
void tree_mirror(Tree* tree)
{
	mirror(tree->root);
}
bool belong(Node* node1,Node* node2)
{
	if(NULL==node2) return true;
	if(NULL==node1) return false;
	if(node1->data==node2->data)
	{
		return belong(node1->left,node2->left)&&belong(node1->right,node2->right);
	}else return false;
		
}
bool tree_belong(Node* parent,Node* kid)
{
	if(parent==NULL||kid==NULL) return false;
	return belong(parent,kid)||tree_belong(parent->left,kid)||tree_belong(parent->right,kid);	
}

//
void print_top(Node* root)
{
	if(NULL == root) return;
	Queue queue;
	queue_init(&queue,0xffffffff);
	queue_push(&queue,root);

	while(!queue_empty(&queue))
	{
		Node* node = queue_head(&queue);
		printf("%d ",node->data);
		if(node->left)queue_push(&queue,node->left);
		if(node->right)queue_push(&queue,node->right);
		queue_pop(&queue);
	}
}
