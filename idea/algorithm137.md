## Algorithm 137

**题目 : **

"Given an array of integers, every element appears three times except for one, which appears exactly once.Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?"

**题意 : **

有一个整数数组，除了其中一种元素只出现1次以外，其他元素均出现3次。找到这个只出现1次的元素。提示：你的算法必须是线性时间复杂度的，另外能不能不使用多余的空间实现？

**解题思路 : **

（1）可以理解成"3"的循环、或3进制。每叠加3次则溢出为0，因此最后叠加剩余仅出现1次的元素。具体讲解见"https://leetcode.com/problems/single-number-ii/?tab=Solutions"。（目前尚不能完全理解）

（2）可以统计每一位出现的次数。因为每一位一定是出现3n+1次，统计完后模余3，就得到仅出现一次的元素各个位上的0/1bit了。该算法的时间复杂度为32n，另外还需要32个整型空间。