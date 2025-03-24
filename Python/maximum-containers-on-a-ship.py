# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def maxContainers(self, n, w, maxWeight):
        """
        :type n: int
        :type w: int
        :type maxWeight: int
        :rtype: int
        """
        return min(maxWeight//w, n*n)
