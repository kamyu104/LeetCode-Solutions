# Time:  O(n * sqrt(n))
# Space: O(n)

# dp
class Solution(object):
    def minDays(self, n):
        """
        :type n: int
        :rtype: int
        """
        def count(n):
            return (n+1)*n//2

        dp = [float("inf")]*(n+1)
        dp[0] = -1
        for d in xrange(1, n+1):
            if count(d) > n:
                break
            for i in xrange(min(count(d), len(dp)-1-count(d))+1):
                dp[i+count(d)] = min(dp[i+count(d)], dp[i]+1+d)
        return dp[-1]
