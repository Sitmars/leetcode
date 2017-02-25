##  145. Binary Tree Postorder Traversal

**题目 :**

Given a binary tree, return the *postorder* traversal of its nodes' values.

For example:
Given binary tree `{1,#,2,3}`,

```
   1
    \
     2
    /
   3

```

return `[3,2,1]`.

**Note:** Recursive solution is trivial, could you do it iteratively?

**题意 :**

现有一个二叉树，请返回以后序遍历顺序得到的各节点的值。

请不要使用递归。

**思路 :**

（1）还是朴素的思路。一上来先判断当前栈顶节点是直接向下过来的，还是回退回来的。若是向下过来的，那么先走左子节点，若有左子则将其压栈，若没有左子反而有右子则将右子压栈，若左右都没有证明是叶子节点，访问它并标记回退；若是回退来的，判断是从左子还是右子回退来的，若是左子来的并且仍存在右子，则将右子压栈，标记直接向下。否则都应访问该节点，并标记回退。

（2）网友提供了一个很好理解的方法。因为后序遍历是left-right-root的顺序，所以我们只需得到root-right-left再将其reverse就好了。而root-right-left恰巧是先序遍历的一个变形，先序遍历很好实现。