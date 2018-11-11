# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        M = 10**9 + 7
        result, dp = 0, [0]*26
        for c in S:
            result, dp[ord(c)-ord('a')] = 2*result-dp[ord(c)-ord('a')]+1, result+1
        return result % M
