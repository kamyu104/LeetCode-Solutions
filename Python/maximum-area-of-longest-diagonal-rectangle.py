# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        """
        :type dimensions: List[List[int]]
        :rtype: int
        """
        return max((l**2+w**2, l*w) for l, w in dimensions)[1]
