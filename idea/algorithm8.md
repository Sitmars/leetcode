##  8. String to Integer (atoi)

**题目 :**

Implement atoi to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

**Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

**题意 :**

实现一个字符串转整数的函数atoi，并考虑到各种输入情况。

**思路 :**

此题的重点在于考虑完全各种输入情况：

（1）空字符串

若输入为空`""`，返回0。

（2）前导空格(space)

前导空格一律无视。

（3）正负号

正负号必须出现在数字最前面，且紧邻数字最高位。若正负号与数字最高位之间有空格，返回0；若出现多个正负号，返回0。

（4）插入的非数字字符

一旦开始转换数字字符，期间遇到任何非数字字符，都将使转换停止，并返回前面已经转换过的数值。

（5）整型边界值溢出

正数不应大于`INT_MAX = 2147483647`；负数不应小于`INT_MIN = -INT_MAX - 1`。越界则返回边界值。这里在判断时，为了避免溢出，应将乘法运算移到不等式右边：

```
if MINUS:
	if result > (-INT_MAX - 1 + int(str[i])) /10:
		result = result * 10 + int(str[i])
	else:
		return -INT_MAX - 1
elif PLUS:
	if result < (INT_MAX - int(str[i])) / 10:
		result = result * 10 + int(str[i])
	else:
		return INT_MAX
```

