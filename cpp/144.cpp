/*
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
	1
	 \
	  2
	 /
	3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode*);
vector<int> preorderTraversal2(TreeNode*);
TreeNode* buildtree(vector<int>&);

int main()
{
	vector<int> tree = { 1,2,3,4,5,6,7 };
	TreeNode* head = buildtree(tree);
	vector<int> result = preorderTraversal2(head);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> preorder;
	if (!root)
	{
		return preorder;
	}
	vector<TreeNode*> nodes;
	nodes.push_back(root);
	TreeNode* node;
	while (!nodes.empty())
	{
		node = nodes.back();
		nodes.pop_back();
		preorder.push_back(node->val);
		if (node->right)
		{
			nodes.push_back(node->right);
		}
		if (node->left)
		{
			nodes.push_back(node->left);
		}
	}
	return preorder;
}

vector<int> preorderTraversal2(TreeNode* root)
{
	vector<int> preorder;
	vector<TreeNode*> rights;
	while (root)
	{
		preorder.push_back(root->val);
		if (root->right)
		{
			rights.push_back(root->right);
		}
		root = root->left;
		if (!root && !rights.empty())
		{
			root = rights.back();
			rights.pop_back();
		}
	}
	return preorder;
}

TreeNode* buildtree(vector<int>& tree)
{
	if (tree.empty())
	{
		return NULL;
	}
	queue<TreeNode*> parents;
	TreeNode* head = new TreeNode(tree[0]);
	int i = 1;
	parents.push(head);
	while (!parents.empty())
	{
		if (i < tree.size() && tree[i])
		{
			TreeNode* left = new TreeNode(tree[i]);
			parents.front()->left = left;
			parents.push(left);
		}
		i += 1;
		if (i < tree.size() && tree[i])
		{
			TreeNode* right = new TreeNode(tree[i]);
			parents.front()->right = right;
			parents.push(right);
		}
		i += 1;
		parents.pop();
	}
	return head;
}