# Time:  O(n^2 * logn)
# Space: O(n)

import math


# angle sweep solution
# great explanation:
# https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636345/Python-O(n3)-and-O(n2logn)-solution-explained-in-detail-with-pictures
class Solution(object):
    def numPoints(self, points, r):
        """
        :type points: List[List[int]]
        :type r: int
        :rtype: int
        """
        def count_points(points, r, i):
            angles = []
            for j in xrange(len(points)):
                if i == j:
                    continue
                dx, dy = points[i][0]-points[j][0], points[i][1]-points[j][1]
                d = math.sqrt(dx**2 + dy**2)
                if d > 2*r:
                    continue
                delta, angle = math.acos(d/(2*r)), math.atan2(dy, dx)
                angles.append((angle-delta, 0)), angles.append((angle+delta, 1))
            angles.sort()
            result, count = 1, 1
            for _, is_closed in angles:  # angle sweep
                if not is_closed:
                    count += 1
                else:
                    count -= 1
                result = max(result, count)
            return result

        return max(count_points(points, r, i) for i in xrange(len(points)))
