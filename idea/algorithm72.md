## 72. Edit Distance

**题目 :**

Given two words *word1* and *word2*, find the minimum number of steps required to convert *word1* to *word2*. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

**题意 :**

现有两个字符串，给出从`s1`转换到`s2`的最少步数。

每一步可以做的操作有三种：

- 插入一个字符
- 删除一个字符
- 替换一个字符

**思路 :**

这又是一个典型的动态规划问题，因为我们又可以划分子问题了。

- 当一个字符串为空时，转换的步数为另一个字符串的长度（n次插入）
- 当两个字符串都非空时
  - 若它们的最后一位相等，那么所需步数等于都去掉最后一位时的步数
  - 若最后一位不相等，那就是都去掉最后一位、仅`s1`去掉最后一位、仅`s2`去掉最后一位当中转换步数最小的，再加上1。分别对应替换最后一位、插入最后一位和删除最后一位。