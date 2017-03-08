## 153. Find Minimum in Rotated Sorted Array

**题目 :**

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`).

Find the minimum element.

You may assume no duplicate exists in the array.

**题意 :**

现有一个排好序的数组（非降序），从任意一处切开并交换前后两段的位置。试从中找出最小元素。

**思路 :**

核心思路是二分法。每次拿出中间元素`mid`，若中间元素`mid`大于头元素`start`，说明前一半仍是升序，被挪动的最小元素还在后面，因此再去搜索后一半；若中间元素`mid`小于头元素`start`，说明`mid`原来就在`start`前面，那么最小元素也在`mid`前面，因此再去搜索前一半。

值得注意的是，上面的方法是建立在分割点在元素内部，即真的有元素被挪到后面的情况。还有一种情况是原数组根本就没动，这时最小值当然是`nums[0]`啦。因此在返回时比较一下算法结果和`nums[0]`，谁小就返回谁。