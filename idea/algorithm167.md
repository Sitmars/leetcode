## 167. Two Sum II - Input array is sorted

**题目 :**

Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have *exactly* one solution and you may not use the *same* element twice.

**Input:** numbers={2, 7, 11, 15}, target=9
**Output:** index1=1, index2=2

**题意 :**

现有一个非降序的整数数组，和一个目标整数。要求从数组中找到两个数，使这两个数的和恰好等于目标整数。

假设结果只有一种情况。

**思路 :**

非常简单的思路，首先将加和的两个数定为首数和尾数。如果它们的和小于目标，就移动左边的数向右；若大于目标，就移动右边的数向左。这样一定能找到和等于目标的两个数。