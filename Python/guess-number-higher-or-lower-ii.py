# Time:  O(n^3)
# Space: O(n^2)
class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0]*(n+1) for _ in xrange(n+1)]  # dp[i][j]: min pay in [i+1, j+1)
        for j in xrange(n+1):
            for i in reversed(xrange(j-1)):
                dp[i][j] = min((k+1) + max(dp[i][k], dp[k+1][j]) for k in xrange(i, j))
        return dp[0][n]


# Time:  O(n^3)
# Space: O(n^2)
class Solution2(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0]*(n+1) for _ in xrange(n+1)]  # dp[i][j]: min pay in [i+1, j+1)
        for i in reversed(xrange(n)):
            for j in xrange(i+2, n+1):
                dp[i][j] = min((k+1) + max(dp[i][k], dp[k+1][j]) for k in xrange(i, j))
        return dp[0][n]
