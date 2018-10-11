# Time:  O(log(max(m, n)))
# Space: O(1)

class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: bool
        """
        while tx >= sx and ty >= sy:
            if tx < ty:
                sx, sy = sy, sx
                tx, ty = ty, tx
            if ty > sy:
                tx %= ty
            else:
                return (tx - sx) % ty == 0

        return False

