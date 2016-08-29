# Time:  O(n)
# Space: O(n)

# Given N axis-aligned rectangles where N > 0, 
# determine if they all together form an exact cover of a rectangular region.
#
# Each rectangle is represented as a bottom-left point and a top-right point. 
# For example, a unit square is represented as [1,1,2,2]. 
# (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
#
# Example 1:
#
# rectangles = [
#   [1,1,3,3],
#   [3,1,4,2],
#   [3,2,4,4],
#   [1,3,2,4],
#   [2,3,3,4]
# ]
#
# Return true. All 5 rectangles together form an exact cover of a rectangular region.
#
# Example 2:
#
# rectangles = [
#   [1,1,2,3],
#   [1,3,2,4],
#   [3,1,4,2],
#   [3,2,4,4]
# ]
#
# Return false. Because there is a gap between the two rectangular regions.
#
# Example 3:
#
# rectangles = [
#   [1,1,3,3],
#   [3,1,4,2],
#   [1,3,2,4],
#   [3,2,4,4]
# ]
#
# Return false. Because there is a gap in the top center.
#
# Example 4:
#
# rectangles = [
#   [1,1,3,3],
#   [3,1,4,2],
#   [1,3,2,4],
#   [2,2,4,4]
# ]
#
# Return false. Because two of the rectangles overlap with each other.

from collections import defaultdict

class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        left = min(rec[0] for rec in rectangles)
        bottom = min(rec[1] for rec in rectangles)
        right = max(rec[2] for rec in rectangles)
        top = max(rec[3] for rec in rectangles)

        points = defaultdict(int)
        for l, b, r, t in rectangles:
            for p, q in zip(((l, b), (r, b), (l, t), (r, t)), (1, 2, 4, 8)):
                if points[p] & q:
                    return False
                points[p] |= q

        for px, py in points:
            if left < px < right or bottom < py < top:
                if points[(px, py)] not in (3, 5, 10, 12, 15):
                    return False

        return True
