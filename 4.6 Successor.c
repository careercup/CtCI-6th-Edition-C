#include "stdio.h"

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

bool mark = false;
TreeNode *inorder(TreeNode *root, int dd)
{
	if (root == NULL)
		return NULL;

	TreeNode *n;
	n = inorder(root->left, dd);
	if (n != NULL)
		return n;

	if (mark == true)
		return root;

	if (root->data == dd)
		mark = true;

	n = inorder(root->right, dd);
	if (n != NULL)
		return n;

	return NULL;
}

int main()
{
	/*
	*    8
	*	  / \
	*	 4	 10
	* / \   \
	*2   6   20
  *
	*/
	TreeNode node2 = { 2,NULL,NULL };
	TreeNode node6 = { 6,NULL,NULL };
	TreeNode node20 = { 20,NULL,NULL };
	TreeNode node4 = { 4,&node2,&node6 };
	TreeNode node10 = { 10,NULL,&node20 };
	TreeNode node8 = { 8,&node4,&node10 };
	printf("%d\n", inorder(&node8, 10)->data);
	mark = false;
	printf("%d\n", inorder(&node8, 8)->data);
	mark = false;
	printf("%d\n", inorder(&node8, 6)->data);
	mark = false;
	printf("%d\n", inorder(&node8, 4)->data);
	mark = false;
	printf("%d\n", inorder(&node8, 2)->data);
}
