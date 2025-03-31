# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def minCosts(self, cost):
        """
        :type cost: List[int]
        :rtype: List[int]
        """
        for i in xrange(1, len(cost)):
            cost[i] = min(cost[i], cost[i-1])
        return cost
