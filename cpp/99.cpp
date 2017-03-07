/*
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prevnode = new TreeNode(INT_MIN);

void recoverTree(TreeNode*);
void traverse(TreeNode*);

int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->right = new TreeNode(1);
	recoverTree(root);
	cout << "hehe" << endl;

	system("pause");
	return 0;
}

void recoverTree(TreeNode* root)
{
	traverse(root);
	int temp = first->val;
	first->val = second->val;
	second->val = temp;
}

void traverse(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	traverse(root->left);
	if (first == NULL && prevnode->val >= root->val)
	{
		first = prevnode;
	}
	if (first != NULL && prevnode->val >= root->val)
	{
		second = root;
	}
	prevnode = root;
	traverse(root->right);
}