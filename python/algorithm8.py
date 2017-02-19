# 8. String to Integer (atoi)
# Implement atoi to convert a string to an integer.
#
# Hint: Carefully consider all possible input cases.
# If you want a challenge, please do not see below and ask yourself what are the possible input cases.
#
# Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
# You are responsible to gather all the input requirements up front.

class Solution(object):
    def myAtoi(self, str):
        result = 0
        while str != "" and str[0] == " ":
            str = str[1:]
        INT_MAX = 2147483647
        flag = 1
        for i in xrange(len(str)):
            if str[i] == "-" or str[i] == "+":
                if i == 0 and str[i] == "-":
                    flag = -1
                    continue
                elif i == 0 and str[i] == "+":
                    continue
                else:
                    return result
            elif not ("0" <= str[i] <= "9"):
                return result
            if flag == -1:
                if result > (-INT_MAX - 1 + int(str[i])) / 10:
                    result = result * 10 - int(str[i])
                else:
                    return -INT_MAX - 1
            elif flag == 1:
                if result <= (INT_MAX - int(str[i])) / 10:
                    result = result * 10 + int(str[i])
                else:
                    return INT_MAX
        return result


if __name__ == "__main__":
    sl = Solution()
    result = sl.myAtoi("  -12a3")
    print result
