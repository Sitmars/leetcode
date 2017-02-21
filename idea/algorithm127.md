##  127. Word Ladder

**题目 :**

Given two words (*beginWord* and *endWord*), and a dictionary's word list, find the length of shortest transformation sequence from*beginWord* to *endWord*, such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list. Note that *beginWord* is *not* a transformed word.

For example,

Given:
*beginWord* = `"hit"`
*endWord* = `"cog"`
*wordList* = `["hot","dot","dog","lot","log","cog"]`

As one shortest transformation is `"hit" -> "hot" -> "dot" -> "dog" -> "cog"`,
return its length `5`.

**Note:**

- Return 0 if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- You may assume no duplicates in the word list.
- You may assume *beginWord* and *endWord* are non-empty and are not the same.

**题意 :**

给出两个单词（一个起始单词beginWord和一个结束单词endWord）和一个单词词典序列。请在单词序列中寻找由起始单词变换到结束单词的最短路径：

1. 每次只能变换单词中的一个字符
2. 每次变换的单词必须在词典中。起始词不算在变换单词中。

另外：

- 如果不存在从起始词都结束词的变换，返回0。
- 所有词长度相同。
- 所有词都只包含英文小写字母。
- 词典序列里没有重复的词。
- 起始词和结束词都非空，且二者不同。

**思路 :**

这个题可以引申成图的遍历。每个词都是图中的一个节点，相邻的节点之间只相差一个字符。而题目是要寻找两个节点间的最短路径，从起始点开始进行广度优先遍历即可。

有个小tip，若要比较两个词是否仅相差一个字符，一个通用的做法是循环前一个词的每一位，并分别用`a~z`替换，与后一个词比较。