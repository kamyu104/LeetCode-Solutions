# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minCost(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if (m, n) == (1, 1):
            return 1
        if (m, n) in ((1, 2), (2, 1)):
            return 3
        return -1
