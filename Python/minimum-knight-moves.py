# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        COST = {(0, 0):0, (1, 1):2, (1, 0):3}  # special cases
        def dp(x, y, lookup):
            x, y = abs(x), abs(y)
            if x < y:
                x, y = y, x
            if (x, y) in COST:
                return COST[(x, y)]
            if (x, y) not in lookup:
                lookup[(x, y)] = min(dp(x-1, y-2, lookup),
                                     dp(x-2, y-1, lookup)) + 1
            return lookup[(x, y)]
        return dp(x, y, {})
