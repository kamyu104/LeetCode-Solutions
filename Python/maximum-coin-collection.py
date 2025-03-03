# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maxCoins(self, lane1, lane2):
        """
        :type lane1: List[int]
        :type lane2: List[int]
        :rtype: int
        """
        result = dp1 = dp12 = dp121 = float("-inf")
        for i in xrange(len(lane1)):
            dp1 = max(dp1, 0)+lane1[i]
            dp12 = max(max(dp12, 0)+lane2[i], dp1)
            dp121 = max(max(dp121, 0)+lane1[i], dp12)
            result = max(result, dp1, dp121)
        return result
