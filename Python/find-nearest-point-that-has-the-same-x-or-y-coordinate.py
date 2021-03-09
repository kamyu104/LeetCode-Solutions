# Time:  O(n)
# Space: O(1)

class Solution(object):
    def nearestValidPoint(self, x, y, points):
        """
        :type x: int
        :type y: int
        :type points: List[List[int]]
        :rtype: int
        """
        smallest, idx = float("inf"), -1
        for i, (r, c) in enumerate(points):
            dx, dy = x-r, y-c
            if dx*dy == 0 and abs(dx)+abs(dy) < smallest:
                smallest = abs(dx)+abs(dy)
                idx = i
        return idx
