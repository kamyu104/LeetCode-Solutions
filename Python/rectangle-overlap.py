# Time:  O(1)
# Space: O(1)

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

