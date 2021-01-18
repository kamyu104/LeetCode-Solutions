# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countGoodRectangles(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        result = mx = 0
        for l, w in rectangles:
            side = min(l, w)
            if side > mx:
                result, mx = 1, side
            elif side == mx:
                result += 1
        return result
