# 7. Reverse Integer
# Reverse digits of an integer.
#
# Example1: x = 123, return 321
# Example2: x = -123, return -321
#
# Note:
# The input is assumed to be a 32-bit signed integer.
# Your function should return 0 when the reversed integer overflows.


class Solution(object):
    def reverse(self, x):
        flag = 1
        if x < 0:
            x = -x
            flag = -1
        result = 0
        max_int = 2147483647
        while x > 0:
            if flag == 1:
                if result * 10 + x % 10 > max_int:
                    return 0
            else:
                if result * 10 + x % 10 > max_int + 1:
                    return 0
            result = result * 10 + x % 10
            x /= 10
        return result*flag


if __name__ == "__main__":
    sl = Solution()
    result = sl.reverse(-8463847412)
    print result