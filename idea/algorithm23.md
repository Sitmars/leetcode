## 23. Merge k Sorted Lists

**题目 :**

Merge *k* sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**题意 :**

合并k个链表为一个，使最终的链表为非降序。分析算法的复杂度。

**思路 :**

看了别人一个思路，核心就是：两个两个地合并。

采取首尾两个链表合并的方式，合并后还放到前面，则每一轮剩余链表的总个数减少一半。迭代直至剩下一个链表，即结果。

他特意写了一个合并两个链表的函数，利用递归写的非常巧妙：

```
ListNode* merge2Lists(ListNode* l1, ListNode* l2)
{
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	if(l1->val < l2->val)
	{
      	l1->next = merge2Lists(l1->next, l2);
      	return l1;
	}
	else
	{
      	l2->next = merge2Lists(l1, l2->next);
      	return l2;
	}
}
```

至于复杂度，我是这么想的：

设有m个链表，每个链表的长度都为n。

因为每一轮合并肯定都要遍历到所有的节点，复杂度就一定是mn。

那么需要几轮呢？设需要k轮，则

```
m = 2^k
k = log(m)
```

因此复杂度是`mnlog(m)`。 