# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def probabilityOfHeads(self, prob, target):
        """
        :type prob: List[float]
        :type target: int
        :rtype: float
        """
        dp = [0.0]*(target+1)
        dp[0] = 1.0
        for p in prob:
            for i in reversed(xrange(target+1)):
                dp[i] = (dp[i-1] if i >= 1 else 0.0)*p + dp[i]*(1-p)
        return dp[target]
