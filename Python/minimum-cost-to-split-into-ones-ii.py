# Time:  O(1)
# Space: O(1)

# math, invariant
class Solution(object):
    def minCost(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n*(n-1)//2
