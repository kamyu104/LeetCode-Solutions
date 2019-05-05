# Time:  O(1)
# Space: O(1)

class Solution(object):
    def isBoomerang(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) - \
               (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]) != 0
