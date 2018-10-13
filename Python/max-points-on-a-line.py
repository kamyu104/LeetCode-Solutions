# Time:  O(n^2)
# Space: O(n)

import collections


# Definition for a point
class Point(object):
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        max_points = 0
        for i, start in enumerate(points):
            slope_count, same = collections.defaultdict(int), 1
            for j in xrange(i + 1, len(points)):
                end = points[j]
                if start.x == end.x and start.y == end.y:
                    same += 1
                else:
                    slope = float("inf")
                    if start.x - end.x != 0:
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x)
                    slope_count[slope] += 1

            current_max = same
            for slope in slope_count:
                current_max = max(current_max, slope_count[slope] + same)

            max_points = max(max_points, current_max)

        return max_points

