# Time:  O(k * n) = O(n)
# Space: O(k) = O(1)

# dp
class Solution(object):
    def numberOfWays(self, s):
        """
        :type s: str
        :rtype: int
        """
        K = 3
        dp = [[0]*2 for _ in xrange(K)]  # dp[i][j]: number of ways of selecting i+1 buildings ending with type j
        for c in s:
            j = ord(c)-ord('0')
            dp[0][j] += 1
            for i in xrange(1, len(dp)):
                dp[i][j] += dp[i-1][1^j]
        return dp[-1][0]+dp[-1][1]
