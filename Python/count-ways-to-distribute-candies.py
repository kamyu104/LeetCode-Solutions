# Time:  O(n * k)
# Space: O(k)

class Solution(object):
    def waysToDistribute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [1]*(k+1)
        for i in xrange(1, n):
            for j in reversed(xrange(2, min(i, k)+1)):
                dp[j] = (j*dp[j] + dp[j-1]) % MOD
        return dp[k]
