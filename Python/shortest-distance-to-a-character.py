# Time:  O(n)
# Space: O(1)

# Given a string S and a character C,
# return an array of integers representing the shortest distance
# from the character C in the string.
#
# Example 1:
#
# Input: S = "loveleetcode", C = 'e'
# Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
#
# Note:
# - S string length is in [1, 10000].
# - C is a single character, and guaranteed to be in string S.
# - All letters in S and C are lowercase.

import itertools

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        result = [len(S)] * len(S)
        prev = -len(S)
        for i in itertools.chain(xrange(len(S)),
                                 reversed(xrange(len(S)))):
            if S[i] == C:
                prev = i
            result[i] = min(result[i], abs(i-prev))
        return result
