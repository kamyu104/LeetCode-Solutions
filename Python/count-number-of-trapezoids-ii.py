# Time:  O(n^2 * logr), r = max(max(abs(x), abs(y)) for x, y in points)
# Space: O(n^2)

import collections


# freq table, combinatorics
class Solution(object):
    def countTrapezoids(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return abs(a)

        lookup_slope = collections.defaultdict(int)
        lookup_line = collections.defaultdict(int)
        lookup_slope_length = collections.defaultdict(int)
        lookup_line_length = collections.defaultdict(int)
        result = same = 0
        for i in range(len(points)):
            x1, y1 = points[i]
            for j in xrange(i):
                x2, y2 = points[j]
                dx, dy = x2-x1, y2-y1
                g = gcd(dx, dy)
                a, b = dx//g, dy//g
                if a < 0 or (a == 0 and b < 0):
                    a, b = -a, -b
                c = b*x1-a*y1
                result += lookup_slope[a, b]-lookup_line[a, b, c]
                lookup_slope[a, b] += 1
                lookup_line[a, b, c] += 1
                l = dx**2+dy**2
                same += lookup_slope_length[a, b, l]-lookup_line_length[a, b, c, l]
                lookup_slope_length[a, b, l] += 1
                lookup_line_length[a, b, c, l] += 1
        return result-same//2
