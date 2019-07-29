No.1128 Number of Equivalent Domino Pairs

$\color{#008000}easy$

---

Given a list of `dominoes`, `dominoes[i] = [a, b]` is *equivalent* to `dominoes[j] = [c, d]` if and only if either (`a==c` and `b==d`), or (`a==d` and `b==c`) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs `(i, j)` for which `0 <= i < j < dominoes.length`, and `dominoes[i]` is equivalent to `dominoes[j]`.

**Example 1:**

```
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
```

 **Constraints:**

- `1 <= dominoes.length <= 40000`
- `1 <= dominoes[i][j] <= 9`

---

**Tag:** `哈希`

找相同、找不同的问题利用哈希最快，这道题的问题是如果对一对儿int值进行哈希。

目前有两种方法：

1. 拼接成字符串，用空格或者其他非数字字符连接，就可以作为哈希的key了；
2. tricky，因为题中说只会出现个位数字，所以可以a*10+b这样拼成两位数。