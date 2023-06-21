# Time:  O(n^2)
# Space: O(n)

import itertools


# knapsack dp
class Solution(object):
    def paintWalls(self, cost, time):
        """
        :type cost: List[int]
        :type time: List[int]
        :rtype: int
        """
        dp = [float("inf")]*(len(cost)+1)
        dp[0] = 0
        for c, t in itertools.izip(cost, time):
            for j in reversed(xrange(1, len(cost)+1)):
                dp[j] = min(dp[j], dp[max(j-(t+1), 0)]+c)
        return dp[-1]
