# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minCuttingCost(self, n, m, k):
        """
        :type n: int
        :type m: int
        :type k: int
        :rtype: int
        """
        return k*max(n-k, m-k, 0)
