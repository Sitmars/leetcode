##  142. Linked List Cycle II

**题目 :**

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

**Note:** Do not modify the linked list.

**Follow up**:
Can you solve it without using extra space?

**题意 :**

现有一个链表，查找并返回该链表成环的其实节点。如果不存在环，返回NULL。

注意，不要破坏链表的结构。并尝试不使用多余的空间解决问题。

**思路 :**

（1）首先想了一个肯定正确，但有些累的方法。按照上一题walker和runner两个指针一慢一快的方法，能迅速判断是否有环。若有环，此时`walker == runner`。接下来创建一个新指针begin指向头节点，从头节点开始，依次向后假设当前节点为环的起始节点，同时让walker继续走起来，runner原地不动。若begin真的是环的起始节点，那么walker在转完一圈之前，一定会与begin会合；反之，walker走完一圈会与runner会合，此时令`begin = begin->next`，继续让walker转圈。这样下去，begin总会进入圈内并与walker会合，会合节点即环的起始节点。

这个算法较慢，用时42ms，仅击败2%...orz

（2）目前最快的方法是靠数学推出来的。设walker从开始到与runner会合共走了k步，环的长度为r,则`2*k - k = nr, k = nr`。其中n为runner追walker追的圈数。

再设头节点与环起始节点距离为s，会合点与环起始点距离为m。因为只要walker进入环，不到一圈一定被runner追上，所以`k = s + m`。 进而`s = k - m = nr - m = (n-1)r + (r-m)`，可见begin走到环起始点的距离和walker继续走到环起始点的距离相差整圈数，因此只要从walker和runner会合开始，让begin和walker一步一步走下去，终会在环起始点会合。