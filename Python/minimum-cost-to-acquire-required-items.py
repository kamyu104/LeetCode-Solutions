# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minimumCost(self, cost1, cost2, costBoth, need1, need2):
        """
        :type cost1: int
        :type cost2: int
        :type costBoth: int
        :type need1: int
        :type need2: int
        :rtype: int
        """
        mn = min(need1, need2)
        mx = max(need1, need2)
        return min(need1*cost1+need2*cost2, mn*costBoth+(need1-mn)*cost1+(need2-mn)*cost2, mx*costBoth)
