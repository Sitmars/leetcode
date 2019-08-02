No.1 Two Sum

$\color{#008000}easy$

---

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

---

**Tag:** `数组` `tricky`

- 解法1 `O(nlogn)`：因为两个数的和（sum）一定，所以我们拿到一个数（n1），就能确定想要的另一个数n2（sum-n1）。于是问题就是在一堆数里查一个数存不存在，用哈希就可以做到。

- 解法2 `O(nlogn)`：有点儿tricky。首先将数组排序，用两个指针分别指向头节点（left）和尾节点（right）；如果它们的和小于sum，那么说明left指向的数没用了，因为它和最大的数组合扔小于sum，此时为了使和更大，++left；同理，当和大于sum时，right指向的数就没用了，--right。

  ```
  vector<int> twoSum(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int left = 0;
      int right = nums.size()-1;
      while(left < right) {
          if(nums[left] + nums[right] > target) {
              --right;
          } else if(nums[left] + nums[right] < target) {
              ++left;
          } else {
              break;
          }
      }
      return vector<int>{left, right};
  }
  ```

  