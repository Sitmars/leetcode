/*
145. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
	1
	 \
	  2
	 /
	3
return [3,2,1].

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

vector<int> postorderTraversal(TreeNode*);
vector<int> postorderTraversal2(TreeNode*);
TreeNode* buildtree(vector<int>&);

int main()
{
	vector<int> tree = { 1,2,3,4,5,6,7};
	TreeNode* head = buildtree(tree);
	vector<int> postorder = postorderTraversal(head);
	for (int i = 0; i < postorder.size(); ++i)
	{
		cout << postorder[i] << " ";
	}
	cout << endl;
	postorder = postorderTraversal2(head);
	for (int i = 0; i < postorder.size(); ++i)
	{
		cout << postorder[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> postorder;
	if (!root)
	{
		return postorder;
	}
	vector<TreeNode*> parents;
	parents.push_back(root);
	TreeNode* child = NULL;
	while (true)
	{
		if (!child)
		{
			if (parents.back()->left)
			{
				parents.push_back(parents.back()->left);
			}
			else if (parents.back()->right)
			{
				parents.push_back(parents.back()->right);
			}
			else
			{
				postorder.push_back(parents.back()->val);
				child = parents.back();
				parents.pop_back();
			}
		}
		else
		{
			if (parents.empty())
			{
				break;
			}
			if (child == parents.back()->left && parents.back()->right)
			{
				parents.push_back(parents.back()->right);
				child = NULL;
			}
			else
			{
				postorder.push_back(parents.back()->val);
				child = parents.back();
				parents.pop_back();
			}
		}
	}
	return postorder;
}

//root-right-left to left-right-root(postorder)
vector<int> postorderTraversal2(TreeNode* root)
{
	vector<int> postorder;
	vector<TreeNode*> lefts;
	while (root)
	{
		postorder.push_back(root->val);
		if (root->left)
		{
			lefts.push_back(root->left);
		}
		root = root->right;
		if (!root && !lefts.empty())
		{
			root = lefts.back();
			lefts.pop_back();
		}
	}
	reverse(postorder.begin(), postorder.end());
	return postorder;
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