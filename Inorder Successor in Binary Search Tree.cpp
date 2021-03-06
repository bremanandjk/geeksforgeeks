//http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/

//方法一：使用父指针，时间复杂度：O(h)；
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

TreeNode * minValue(TreeNode* node)
{
	if (!node)
	{
		return NULL;
	}
	TreeNode* cur=node;
	while (cur->left)
	{
		cur=cur->left;
	}
	return cur;
}

TreeNode * inOrderSuccessor(TreeNode *root, TreeNode *node)
{
	if (!root)
	{
		return NULL;
	}
	if (node->right)
	{
		return minValue(node->right);
	}
	TreeNode *cur=node->parent;
	while (cur && cur->left!=node)
	{
		node=cur;
		cur=cur->parent;
	}
	return cur;
}

//方法二：从根处搜索，不需要父指针，时间复杂度：O(h)；
TreeNode * inOrderSuccessor1(TreeNode *root, TreeNode *node)
{
	if (!root)
	{
		return NULL;
	}
	if (node->right)
	{
		return minValue(node->right);
	}
	TreeNode *succ=NULL;
	while (root)
	{
		if (node->val<root->val)
		{
			succ=root;
			root=root->left;
		}
		else if (node->val>root->val)
		{
			root=root->right;
		}
		else break;
	}
	return succ;
}
