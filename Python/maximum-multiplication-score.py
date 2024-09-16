# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maxScore(self, a, b):
        """
        :type a: List[int]
        :type b: List[int]
        :rtype: int
        """
        dp = [float("-inf")]*(len(a)+1)
        dp[0] = 0
        for x in b:
            for i in reversed(xrange(1, len(dp))):
                dp[i] = max(dp[i], dp[i-1]+x*a[i-1])
        return dp[-1]
