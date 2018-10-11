# Time:  O(n * k)
# Space: O(k)

class Solution(object):
    def kInversePairs(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        M = 1000000007
        dp = [[0]*(k+1) for _ in xrange(2)]
        dp[0][0] = 1
        for i in xrange(1, n+1):
            dp[i%2] = [0]*(k+1)
            dp[i%2][0] = 1
            for j in xrange(1, k+1):
                dp[i%2][j] = (dp[i%2][j-1] + dp[(i-1)%2][j]) % M
                if j-i >= 0:
                    dp[i%2][j] = (dp[i%2][j] - dp[(i-1)%2][j-i]) % M
        return dp[n%2][k]

