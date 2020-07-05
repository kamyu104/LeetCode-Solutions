# Time:  O(n)
# Space: O(1)

class Solution(object):
    def getLastMoment(self, n, left, right):
        """
        :type n: int
        :type left: List[int]
        :type right: List[int]
        :rtype: int
        """
        return max(max(left or [0]), n-min(right or [n]))
