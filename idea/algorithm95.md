## 95. Unique Binary Search Trees II

**题目 :**

Given an integer *n*, generate all structurally unique **BST's** (binary search trees) that store values 1...*n*.

For example,
Given *n* = 3, your program should return all 5 unique BST's shown below.

```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

**题意 :**

给一个数字n，请构造由1...n这n个数组成的所有二叉搜索树。

**思路 :**

首先遍历1~n，即假设1~n分别充当根的情况。在每一种情况下，其左子树由1~i-1组成，而右子树由i+1~n组成。因此递归构造左子树和右子树，相当于缩小问题规模分别为i-1和n-i-1。