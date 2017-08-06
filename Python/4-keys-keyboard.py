# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxA(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N <= 6:
            return N
        dp = [i for i in range(N+1)]
        for i in xrange(7, N+1):
            dp[i % 6] = max(dp[(i-4) % 6]*3,dp[(i-5) % 6]*4)
        return dp[N % 6]
 
