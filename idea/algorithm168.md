## 168. Excel Sheet Column Title

**题目 :**

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
```

**题意 :**

实现excel中列标题与列数的对应关系，输入列数，返回大写英文字母组成的列标题。

**思路 :**

虽说这是一道easy的题，但还是有一个小坑，那就是虽说是逢26进1，但并没有0所对应的英文字母。例如当列数为`52`时，对应的并不是`B0`，而是`AZ`。`53`才进一到`BA`。

我的方法是每次模余26，得到当前最高位的字母对应的数字。但模余出来的数字是`0~25`的，因此把`0`当作26，代表当余数是0时当前最高位为`Z`，然后在总数`n`上减去一个26，再除以26；若不是0，则`n`直接除以26即可。

不过这方法并不快。