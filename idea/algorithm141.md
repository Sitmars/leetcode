##  141. Linked List Cycle

**题目 :**

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

**题意 :**

给出一个链表，判断它是否有环。

尝试能不能不使用多余的空间。

**思路 :**

我一开始的思路是想：第一次遍历到一个节点和第二次遍历到同一个节点有什么不同，如果情况相同，那么无法判断是否有环。而每个节点的不同之处仅仅在于它们的地址不同，因为题中并没说节点内的value互不相同。于是我打算每遍历到一个节点，就把它的地址存到value里，这样若`address == value`，那么是第二次遍历到，即有环。

然而，地址占8个字节，而int占4个字节，在强制转换时leetcode的编译器会报异常。失败告终。

后来看了网友给出的一个目前最快的答案：使用两个指针，一个叫walker每次向后走一步，另一个叫runner每次向后走两步。如果链表存在环，那么runner最终一定会追上walker，即当`walker == runner`时发现环。还是很有想象力的。