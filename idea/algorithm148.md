## 148. Sort List

**题目 :**

Sort a linked list in *O*(*n* log *n*) time using constant space complexity.

**题意 :**

用一个O(nlogn)时间复杂度的算法对一个链表排序。

**思路 :**

一看到nlogn，就想到了分治，也就是归并排序，流程仍同数组。就是找中间元素需要用到walker和runner。合并两个有序链表仍然使用插入排序。