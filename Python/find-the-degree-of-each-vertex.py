# Time:  O(n * m)
# Space: O(1)

# array
class Solution(object):
    def findDegrees(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        return [sum(row) for row in matrix]
