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

class Solution:
    # @return a string
    def convert(self, s, nRows):
        step, zigzag = 2 * nRows - 2, ""
        if s == None or len(s) == 0 or nRows <= 0:
            return ""
        if nRows == 1:
            return s
        for i in xrange(nRows):
            for j in xrange(i, len(s), step):
                zigzag += s[j]
                if i > 0 and i < nRows - 1 and j + step - 2 * i < len(s):
                    zigzag += s[j + step - 2 * i]
        return zigzag

if __name__ == "__main__":
    print Solution().convert("PAYPALISHIRING", 3)