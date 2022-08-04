# Time:  O(n)
# Space: O(1)

import itertools


# dp
class Solution(object):
    def minimumCosts(self, regular, express, expressCost):
        """
        :type regular: List[int]
        :type express: List[int]
        :type expressCost: int
        :rtype: List[int]
        """
        result = []
        dp = [0, expressCost]  # dp[0]: min cost of regular route to curr stop, dp[1]: min cost of express route to curr stop
        for r, e in itertools.izip(regular, express):
            dp = [min(dp[0]+r, dp[1]+e), min(dp[0]+(r+expressCost), dp[1]+e)]
            result.append(min(dp[0], dp[1]))
        return result
