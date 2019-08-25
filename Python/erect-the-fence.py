# Time:  O(nlogn)
# Space: O(n)

import itertools


# Monotone Chain Algorithm
class Solution(object):
    def outerTrees(self, points):
        """
        :type points: List[List[int]]
        :rtype: List[List[int]]
        """
        def ccw(A, B, C):
            return (B[0]-A[0])*(C[1]-A[1]) - (B[1]-A[1])*(C[0]-A[0])

        hull = []
        points.sort()
        for i in itertools.chain(xrange(len(points)), reversed(xrange(len(points)))):
            while len(hull) >= 2 and \
                  ccw(hull[-2], hull[-1], points[i]) < 0:
                hull.pop()
            hull.append(points[i])
        return list(set(map(tuple, hull)))
