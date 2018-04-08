# Time:  O(n^3)
# Space: O(1)

# You have a list of points in the plane. Return the area of the largest
# triangle
# that can be formed by any 3 of the points.
#
# Example:
# Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
# Output: 2
# Explanation:
# The five points are show in the figure below. The red triangle is the
# largest.
#
# Notes:
# - 3 <= points.length <= 50.
# - No points will be duplicated.
# - -50 <= points[i][j] <= 50.
# - Answers within 10^-6 of the true value will be accepted as correct.

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        result = 0
        for i in xrange(len(points)-2):
            for j in xrange(i+1, len(points)-1):
                for k in xrange(j+1, len(points)):
                    result = max(result,
                                 0.5 * abs(points[i][0] * points[j][1] +
                                           points[j][0] * points[k][1] +
                                           points[k][0] * points[i][1] -
                                           points[j][0] * points[i][1] -
                                           points[k][0] * points[j][1] -
                                           points[i][0] * points[k][1]))
        return result
