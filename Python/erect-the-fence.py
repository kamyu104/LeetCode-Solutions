# Time:  O(nlogn)
# Space: O(n)

# There are some trees, where each tree is represented by
# (x,y) coordinate in a two-dimensional garden.
# Your job is to fence the entire garden using the minimum length of rope
# as it is expensive. The garden is well fenced only if all the trees are enclosed.
# Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.
#
# Example 1:
# Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
# Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
#
# Example 2:
# Input: [[1,2],[2,2],[4,2]]
# Output: [[1,2],[2,2],[4,2]]
#
# Even you only have trees in a line, you need to use rope to enclose them.
# Note:
#
# All trees should be enclosed together.
# You cannot cut the rope to enclose trees that will separate them in more than one group.
# All input integers will range from 0 to 100.
# The garden has at least one tree.
# All coordinates are distinct.
# Input points have NO order. No order required for output.

# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

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
