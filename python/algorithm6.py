# 6. ZigZag Conversion
# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
# (you may want to display this pattern in a fixed font for better legibility)
#
# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:
#
# string convert(string text, int nRows);
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s
        result = ""
        for i in xrange(numRows):
            site = i
            up = 0
            while site < len(s):
                result += s[site]
                if i != numRows-1 and (i == 0 or up == 0):
                    site += 2*(numRows - i - 1)
                    up = 1
                else:
                    site += 2*i
                    up = 0
        return result


if __name__ == "__main__":
    sl = Solution()
    s = "PAYPALISHIRING"
    result = sl.convert(s, 2)
    print result
