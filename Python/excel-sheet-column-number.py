# Time:  O(n)
# Space: O(1)
#
# Related to question Excel Sheet Column Title
# 
# Given a column title as appear in an Excel sheet, return its corresponding column number.
# 
# For example:
# 
#     A -> 1
#     B -> 2
#     C -> 3
#     ...
#     Z -> 26
#     AA -> 27
#     AB -> 28 
#

class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        result = 0
        for i in xrange(len(s)):
            result *= 26
            result += ord(s[i]) - ord('A') + 1
        return result

if __name__ == "__main__":
    print Solution().titleToNumber("AAAB")