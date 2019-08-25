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

        if len(points) <= 1:
           return points

        hull = []
        points.sort()
        for i in itertools.chain(xrange(len(points)), reversed(xrange(len(points)-1))):
            while len(hull) >= 2 and ccw(hull[-2], hull[-1], points[i]) < 0:
                hull.pop()
            hull.append(points[i])
        hull.pop()

        for i in xrange(1, (len(hull)+1)//2):
            if hull[i] != hull[-1]:
                break
            hull.pop()
        return hull
