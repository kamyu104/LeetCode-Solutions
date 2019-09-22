# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        def dp(x, y, lookup):
            x, y = abs(x), abs(y)
            if x < y:
                x, y = y, x
            if x == 0 and y == 0:
                return 0
            if (x, y) == (1, 1):
                return 2  # (0, 0) => (-1, 2) => (1, 1)
            if (x, y) == (1, 0):
                return 3  # (0, 0) => (-2, 1) => (0, 2) => (1, 0)
            if (x, y) not in lookup:
                lookup[(x, y)] = min(dp(x-1, y-2, lookup),
                                     dp(x-2, y-1, lookup)) + 1
            return lookup[(x, y)]
        return dp(x, y, {})
