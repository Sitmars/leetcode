## 99. Recover Binary Search Tree

**题目 :**

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

**题意 :**

一颗二叉搜索树中有两个节点交换了位置，请找出这两个节点并将他们的值交换。

**思路 :**

既然是树肯定少不了遍历。一开始的我的思路是遍历一遍二叉树，检查每个节点是否符合当前的上、下限。但问题是，一旦发现不符合上下限的节点后：一是无法断定是当前节点交换了位置、还是父节点交换了位置导致当前节点错了；二是以当前节点为根的子树缺少了一个界限，无法继续遍历了。

因此看了别人一个答案。这要从二叉搜索树的性质说起，对二叉搜索树进行中序遍历，得到的是一个升序的序列。而两个出错的节点处，一定会造成降序。找到两个降序点即可。

另外，此题貌似不存在相邻两个节点交换的情况。否则上述方法只能找到一个降序点。