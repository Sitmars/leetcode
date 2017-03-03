## 85. Maximal Rectangle

**题目 :**

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

```

Return 6.

**题意 :**

现有一个平面上的矩阵，矩阵元素只可能是字符1或0。找出由字符1组成的最大的矩形的面积，面积即为矩形中包含字符1的个数。

**思路 :**

一个基本的想法是：随着从左上角遍历到右下角，包含的矩形在不断扩大。如果有一种方法能由前面已经得出的结果推倒当当前位置字符作为**右下角**时的最大矩形就好了。

网友给出了一种方法。他想为每行元素存储3个值：`left`、`right`、`height`，分别表示矩形的宽度左界限、宽度又界限和高度。在这种表示方法下，矩形的面积由`(right -left)*height `计算。该算法以行为单位，所以3个值都只保存列数个。

对于`height[j]`。如果当前位置为1，就给`height[j]++`；否则`height[j]=0`。

对于`left[j]`。如果为1，就得找最紧界限，即上一行的左界限和当前行左界限谁更靠右，当前行左界限为最近的一个由0变到1的1。`left[j] = max(left[j], cur_left)`；否则，令`left[j] = 0`，且`cur_left++`。

对`right[j]`和左边界非常类似，但是要注意从右向左遍历更新，空值对应列数。

每遍历完一行，更新最大面积。