# Time:  O(nlogn)
# Space: O(n)

# knapsack dp
class Solution(object):
    def numberOfWays(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: int
        """
        MOD = 10**9+7

        dp = [0]*(n+1)
        dp[0] = 1
        for i in xrange(1, n+1):
            i_pow_x = i**x
            if i_pow_x > n:
                break
            for j in reversed(xrange(i_pow_x, n+1)):
                dp[j] = (dp[j]+dp[j-i_pow_x])%MOD
        return dp[-1]
