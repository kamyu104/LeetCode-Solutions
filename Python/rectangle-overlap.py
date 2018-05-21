# Time:  O(1)
# Space: O(1)

# A rectangle is represented as a list [x1, y1, x2, y2],
# where (x1, y1) are the coordinates of its bottom-left corner,
# and (x2, y2) are the coordinates of its top-right corner.
#
# Two rectangles overlap if
# the area of their intersection is positive.
# To be clear, two rectangles that only
# touch at the corner or edges do not overlap.
#
# Given two rectangles, return whether they overlap.
#
# Example 1:
#
# Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
# Output: true
# Example 2:
#
# Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
# Output: false
# Notes:
#
# Both rectangles rec1 and rec2 are lists of 4 integers.
# All coordinates in rectangles will be between -10^9 and 10^9.


class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        def intersect(p_left, p_right, q_left, q_right):
            return max(p_left, q_left) < min(p_right, q_right)

        return (intersect(rec1[0], rec1[2], rec2[0], rec2[2]) and
                intersect(rec1[1], rec1[3], rec2[1], rec2[3]))
