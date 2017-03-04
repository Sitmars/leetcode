/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

	1         3     3      2      1
	 \       /     /      / \      \
	  3     2     1      1   3      2
	 /     /       \                 \
	2     1         2                 3
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

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int);
vector<TreeNode*> subTrees(int, int);

int main()
{
	vector<TreeNode*> trees = generateTrees(0);
	cout << "haha" << endl;

	system("pause");
	return 0;
}

vector<TreeNode*> generateTrees(int n)
{
	if (n == 0)
	{
		return vector<TreeNode*>();
	}
	return subTrees(1, n);
}

vector<TreeNode*> subTrees(int start, int end)
{
	vector<TreeNode*> subtrees;
	if (start > end)
	{
		subtrees.push_back(NULL);
		return subtrees;
	}
	if (start == end)
	{
		subtrees.push_back(new TreeNode(start));
		return subtrees;
	}
	for (int i = start; i <= end; ++i)
	{
		vector<TreeNode*> lefts = subTrees(start, i - 1);
		vector<TreeNode*> rights = subTrees(i + 1, end);
		for (int j = 0; j < lefts.size(); ++j)
		{
			for (int k = 0; k < rights.size(); ++k)
			{
				TreeNode* node = new TreeNode(i);
				node->left = lefts[j];
				node->right = rights[k];
				subtrees.push_back(node);
			}
		}
	}
	return subtrees;
}