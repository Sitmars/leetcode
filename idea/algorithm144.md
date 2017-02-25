##  144. Binary Tree Preorder Traversal

**题目 :**

Given a binary tree, return the *preorder* traversal of its nodes' values.

For example:
Given binary tree `{1,#,2,3}`,

```
   1
    \
     2
    /
   3

```

return `[1,2,3]`.

**Note:** Recursive solution is trivial, could you do it iteratively?

**题意 :**

现有一个二叉树，请用先序遍历的顺序返回各节点的值。

因为用递归法太简单无聊了，所以请不要使用递归。

**思路 :**

（1）最常规的思路很好形成，使用一个堆栈，每次取出堆栈栈顶的节点并访问它，然后依次将它的右子节点、左子节点压入堆栈。当然NULL不用压入。直到堆栈取完，也完成了先序遍历。

（2）另外还看了网友一个最快算法。在（1）的基础上略改：我们不将左子节点压入堆栈，而是直接判断其是否为NULL。若为NULL，则直接进入右子树；若不为NULL，直接进入左子树。这样就节省了将左子节点压入堆栈的事儿——（1）相当于刚把左子节点压进去了，又马上把它弹出来——这是无用功。