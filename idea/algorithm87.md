## 87. Scramble String

**题目 :**

Given a string *s1*, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of *s1* = `"great"`:

```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

```

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node `"gr"` and swap its two children, it produces a scrambled string `"rgeat"`.

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

```

We say that `"rgeat"` is a scrambled string of `"great"`.

Similarly, if we continue to swap the children of nodes `"eat"` and `"at"`, it produces a scrambled string `"rgtae"`.

```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

```

We say that `"rgtae"` is a scrambled string of `"great"`.

Given two strings *s1* and *s2* of the same length, determine if *s2* is a scrambled string of *s1*.

**题意 :**

将一个字符串从中间任意位置一分为二，且两部分都非空，此时可以左右交换两个子串或不交换，这种操作称作一次变形。子串可以重复变形。

现在给出两个字符串`s1`和`s2`，判断后者是不是由前者变形而来的。

假定`s1`和`s2`的长度一样，且仅包含英文小写字母。

**思路 :**

此题需要把控的是每次分割的分割界限。一旦分割形成，那么左右两子块的字符组合就确定了，无非是左右可以交换罢了，但组合不会变。

因此我们从第一个位置开始，遍历到最后一个位置，分别尝试界限划在当前位置可不可以。所谓可以，即`s1`的左部分可以由`s2`的左部分变形过来，且右部分也可以；或者`s1`的左部分可以由`s2`的右部分变形过来，当然`s2`的分割点的位置是反过来的，相当于交换两个子串。

递归这两种情况即可。