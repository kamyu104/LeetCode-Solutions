# Time:  O(n)
# Space: O(1)
#
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
#

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        step, zigzag = 2 * numRows - 2, ""
        for i in xrange(numRows):
            for j in xrange(i, len(s), step):
                zigzag += s[j]
                if 0 < i < numRows - 1 and j + step - 2 * i < len(s):
                    zigzag += s[j + step - 2 * i]
        return zigzag

if __name__ == "__main__":
    print Solution().convert("PAYPALISHIRING", 3)
