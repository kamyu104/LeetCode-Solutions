# Time:  O(n + m), m = len(offers)
# Space: O(n + m)

# dp
class Solution(object):
    def maximizeTheProfit(self, n, offers):
        """
        :type n: int
        :type offers: List[List[int]]
        :rtype: int
        """
        lookup = [[] for _ in xrange(n)]
        for s, e, g in offers:
            lookup[e].append([s, g])
        dp = [0]*(n+1)
        for e in xrange(n):
            dp[e+1] = dp[(e-1)+1]
            for s, g in lookup[e]:
                dp[e+1] = max(dp[e+1], dp[(s-1)+1]+g)
        return dp[-1]
