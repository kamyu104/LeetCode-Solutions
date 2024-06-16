# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def numberOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        # sequences: [1, 2, 2, 4, 4, 7, 7, 11, 11, 16, 16, 22, 22, ...]
        return (1+((n//2)+1)*(n//2)//2)%MOD


# Time:  O(n)
# Space: O(n)
# dp
class Solution2(object):
    def numberOfWays(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(n+1)
        dp[0] = 1
        for i in (1, 2, 6):
            for j in xrange(i, n+1):
                dp[j] = (dp[j]+dp[j-i])%MOD
        return reduce(lambda x, y: (x+dp[n-4*y])%MOD, (i for i in xrange(min(n//4, 2)+1)), 0)
