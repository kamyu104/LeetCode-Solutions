# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        return sum(max(abs(points[i+1][0] - points[i][0]),
                       abs(points[i+1][1] - points[i][1]))
                   for i in xrange(len(points)-1))
