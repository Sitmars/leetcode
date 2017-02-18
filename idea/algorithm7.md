

## 7. Reverse Integer

**题目 :**

Reverse digits of an integer.

**Example1:** x = 123, return 321
**Example2:** x = -123, return -321

**Note:**
The input is assumed to be a 32-bit signed integer. Your function should **return 0 when the reversed integer overflows**.

**题意 :**

反转整数。将一个整数按位倒置。

如果反正后的整数超出了32位整数表示的范围，返回0。

**思路 :**

一位一位反转没问题，问题的关键在于怎么检测反转后的整数溢出。可以设置`INT_MAX = 2147483647`和`INT_MIN = -INT_MAX -1`，在检测时可以用：

`result > (INT_MAX - x%10) * 10`

这样反过来检测，以免计算时溢出。

（另附，题目页点赞最多算法，java）：

```
public int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }
    return result;
}
```

他利用的是，如果溢出，那么按照计算来的路子算回去，那么一定与原数不相等。