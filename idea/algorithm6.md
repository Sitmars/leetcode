## Algorithm 6

**题目 :**

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string text, int nRows);
```

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

**题意 :**

字符串"PAYPALISHIRING"以被写成n行zigzag的形式给出，像下面这样：

```
P   A   H   N
A P L S I I G
Y   I   R
```

则可以一行一行地读成：`"PAHNAPLSIIGYIR"`编写函数接收一个字符串和一个行数为输入，将字符串转换为zigzag按行读形式，返回按行读字符串：

**思路 :**

这是一个找规律的问题。从上到下顺序读出每一行：对于第i行，当读完当前的字符后，为了得到同行下一个字符的运动轨迹是：（1）向下折一个弯再向上，或（2）向上折一个弯再向下。

对于（1），字符下标增加了`2*(nRows - i - 1)`

对于（2），字符下标增加了`2*i`

最后值得注意的是，对于第0行和第nRows-1行，前者只有情况（1），后者只有情况（2）。