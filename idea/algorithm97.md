## 97. Interleaving String

**题目 :**

Given *s1*, *s2*, *s3*, find whether *s3* is formed by the interleaving of *s1* and *s2*.

For example,
Given:
*s1* = `"aabcc"`,
*s2* = `"dbbca"`,

When *s3* = `"aadbbcbcac"`, return true.
When *s3* = `"aadbbbaccc"`, return false.

**题意 :**

现有三个字符串s1,s2和s3。判断s3是不是由s1和s2交错交叉得到的。

**思路 :**

关键又是缩小问题规模。

我起初一种**不好**的思路是：因为s3的首部一定来自s1或s2，那么就从仅s1（或仅s2）的首部取出能与s3最长匹配、且期间一直不等于s2[0]（或s1[0]）的子串`s1.substr(0,i)`，递归判断剩下的部分能否匹配（`s1.substr(i)、s2、s3.substr(i)`）。这样虽然问题规模也在缩小，但效率不高，不能通过长且复杂的用例。

后来看了别人一个缩小规模的方法。用一个二维向量`subs[s1.length()+1][s2.length()+1]`保存`s1.substr(0,i)、s2.substr(0,j)、s3.substr(0,i+j)`能否匹配的结果true/false。通过两层循环填满这个二维向量，最终答案就在`subs[s1.length()][s2.length()]`里。