# Time:  f(n) = k * f(n/k) + n/k * klogk <= O(logn * nlogk) <= O(n^2)
#        n is the length of S, k is the max number of special strings in each depth
# Space: O(n)

# Special binary strings are binary strings with the following two properties:
#
# The number of 0's is equal to the number of 1's.
# Every prefix of the binary string has at least as many 1's as 0's.
# Given a special string S, a move consists of choosing two consecutive, non-empty,
# special substrings of S, and swapping them.
# (Two strings are consecutive if the last character of the first string is 
# exactly one index before the first character of the second string.)
#
# At the end of any number of moves, what is the lexicographically largest resulting string possible?
#
# Example 1:
# Input: S = "11011000"
# Output: "11100100"
#
# Explanation:
# The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
# This is the lexicographically largest string possible after some number of swaps.
#
# Note:
# - S has length at most 50.
# - S is guaranteed to be a special binary string as defined above.

class Solution(object):
    def makeLargestSpecial(self, S):
        """
        :type S: str
        :rtype: str
        """
        result = []
        anchor = count = 0
        for i, v in enumerate(S):
            count += 1 if v == '1' else -1
            if count == 0:
                result.append("1{}0".format(self.makeLargestSpecial(S[anchor+1:i])))
                anchor = i+1
        result.sort(reverse = True)
        return "".join(result)
