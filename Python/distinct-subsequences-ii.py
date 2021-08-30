# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        MOD = 10**9+7
        result, dp = 0, [0]*26
        for c in S:
            result, dp[ord(c)-ord('a')] = (result+((result+1)-dp[ord(c)-ord('a')]))%MOD, (result+1)%MOD
        return result
