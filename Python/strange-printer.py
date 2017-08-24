# Time:  O(n^3)
# Space: O(n^2)

# There is a strange printer with the following two special requirements:
#
# The printer can only print a sequence of the same character each time.
# At each turn, the printer can print new characters starting from
# and ending at any places, and will cover the original existing characters.
#
# Given a string consists of lower English letters only,
# your job is to count the minimum number of turns the printer needed in order to print it.
#
# Example 1:
# Input: "aaabbb"
# Output: 2
# Explanation: Print "aaa" first and then print "bbb".
# Example 2:
# Input: "aba"
# Output: 2
# Explanation: Print "aaa" first and then print "b" from 
# the second place of the string, which will cover the existing character 'a'.
#
# Hint: Length of the given string will not exceed 100.
    
class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        def dp(s, i, j, lookup):
            if i > j:
                return 0
            if (i, j) not in lookup:
                lookup[(i, j)]  = dp(s, i, j-1, lookup) + 1
                for k in xrange(i, j):
                    if s[k] == s[j]:
                        lookup[(i, j)] = min(lookup[(i, j)], \
                                             dp(s, i, k, lookup) + dp(s, k+1, j-1, lookup))
            return lookup[(i, j)]

        lookup = {}
        return dp(s, 0, len(s)-1, lookup)
