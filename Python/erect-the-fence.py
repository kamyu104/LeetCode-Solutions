# Time:  O(nlogn)
# Space: O(n)

import itertools


# Monotone Chain Algorithm
class Solution(object):
    def outerTrees(self, points):
        """
        :type points: List[Point]
        :rtype: List[Point]
        """
        def orientation(p, q, r):
            return (q.y - p.y) * (r.x - q.x) - \
                   (q.x - p.x) * (r.y - q.y)

        hull = []
        points.sort(key=lambda p: (p.x, p.y))

        for i in itertools.chain(xrange(len(points)), \
                                 reversed(xrange(len(points)))):
            while len(hull) >= 2 and \
                  orientation(hull[-2], hull[-1],  points[i]) > 0:
                hull.pop()
            hull.append(points[i])

        return list(set(hull))

