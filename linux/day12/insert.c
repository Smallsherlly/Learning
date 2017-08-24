static void insert(Node** root,Node* node)
{
	while(1)
	{
		if(*root == NULL)
		{
			*root = node;
			return;
		}
		else
		{
			if((*root)->data > node->data)
			{
				*root = &(*root)->left;
			}
			else
			{
				*root = &(*root)->right;
			}
		}
	}
}
