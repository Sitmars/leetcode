## 139. Word Break

**题目 :**

Given a **non-empty** string *s* and a dictionary *wordDict* containing a list of **non-empty** words, determine if *s* can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
*s* = `"leetcode"`,
*dict* = `["leet", "code"]`.

Return true because `"leetcode"` can be segmented as `"leet code"`.

**UPDATE (2017/1/4):**
The *wordDict* parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

**题意 :**

现有一个非空字符串s和一个非空词典wordDict，词典包含单词序列。请确定字符串s能否用一个或多个词典中的词分隔开来。你可以假设词典中没有重复的词。

**思路 :**

在做这个题时，我首先有了一个最朴实的想法：即按照深度优先的规则，将字符串s从头到尾地进行查词典。按当前的分隔，若后面剩余的字符串在词典中查不到了（没法儿再分了），就回退上一个分隔的词，去寻找一个更长的分隔。但是，这种思路重复的操作过多，过不了第27/34个测试用例：

```
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
```

于是发现，这个题是一个动态规划问题。一个明显的特征是，它能很方便地缩小问题规模：如果第i位前的子串能被分隔，那么只需要检测第i位后的子串能不能被分隔就行了。因此，从长度为1开始，依次考虑前N个字符组成的子串能不能被分隔。用一个长度为`s.length()+1`的向量保存前i位子串能否被分隔，在后面的检测中可以被直接引用，省去了很多计算。