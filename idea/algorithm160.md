## 160. Intersection of Two Linked Lists

**题目 :**

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

```

begin to intersect at node c1.

**Notes:**

- If the two linked lists have no intersection at all, return `null`.
- The linked lists must retain their original structure after the function returns.
- You may assume there are no cycles anywhere in the entire linked structure.
- Your code should preferably run in O(n) time and use only O(1) memory.

**题意 :**

现有两个链表，请找到它们的交错起始点。如果它们没有交错，返回NULL。

- 提示：
  - 算法中不要改变两链表的结构，包括节点中的值。
  - 假设两链表都不存在环。
  - 算法必须的时间复杂度O(n)且空间复杂度O(1)的。

**思路 :**

本体思路有点儿神奇，我自己想了半天搞出一个必须修改节点值的方法。

后来看了别人一个，它是这样：让两个指针先后交错各遍历一遍a链和b链。即指针A先遍历a再遍历b，指针B先遍历b再去遍历a。这样的好处是，指针A、B一定同时遍历结束——因为遍历的长度一样嘛！

接下来假设，若a、b交错，那么A、B一定是同时同刻走过交错的节点——否则它们就不可能同时到达尾部，而且A、B相遇的节点刚好就是交错起始节点。

不得不佩服，墙倒了都不服，就服它。