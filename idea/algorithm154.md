## 154. Find Minimum in Rotated Sorted Array II

**题目 :**

> *Follow up* for "Find Minimum in Rotated Sorted Array":
> What if *duplicates* are allowed?
>
> Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`).

Find the minimum element.

The array may contain duplicates.

**题意 :**

现有一个排好序的数组，在数组任意位置将数组分为两半（可能有一个是空数组），将两部分前后翻转。试找出最小元素。

注意本题与前一题不同之处是，本题允许数组中出现重复元素。

**思路 :**

跟上一题一样，是二分查找。上一题我们比较中间元素`mid`和首元素`start`的大小从而得知最小元素到底在前半还是后半。

因此现在数组元素可以重复了，当`mid`与`start`的值相等时，我们就没法儿判断了。这里我偷懒了一下，如果二者值相等，那么就分别求前半和后半的最小值，并返回二者中小的那个。

可想而知，这种偷懒的方法不是最快的，但确实是有效的。