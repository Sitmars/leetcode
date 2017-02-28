##  150. Evaluate Reverse Polish Notation

**题目 :**

Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

Some examples:

```
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```

**题意 :**

通过逆波兰表达式求值。

操作符只有加、减、乘、除，操作数是整数。

**思路 :**

实际上这个题很傻，后缀表达式本身就是适合计算机计算的表达式，既然已经给出来了，就使用一个堆栈存放操作数就行了。遇到数字就压栈，遇到运算符就出栈两个数，计算，再将结果压栈。最终结果保存在栈顶，且栈长度为一。

注意到题目中说操作数除了可以是整数以外，还能是另外一个表达式，但在用例当中并没有出现这种情况。

另外，计算中缀表达式比本题要难一些。