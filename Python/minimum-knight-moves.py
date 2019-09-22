# Time:  O(1)
# Space: O(1)

class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        # we can observe from:
        # [0]
        # [3, 2]
        # [2, 1, 4]
        # [3, 2, 3, 2]
        # [2, 3, 2, 3, 4]
        # [3, 4, 3, 4, 3, 4]
        # [4, 3, 4, 3, 4, 5, 4]
        # [5, 4, 5, 4, 5, 4, 5, 6]
        # [4, 5, 4, 5, 4, 5, 6, 5, 6]
        # [5, 6, 5, 6, 5, 6, 5, 6, 7, 6]
        # [6, 5, 6, 5, 6, 5, 6, 7, 6, 7, 8]
        # [7, 6, 7, 6, 7, 6, 7, 6, 7, 8, 7, 8]
        # [6, 7, 6, 7, 6, 7, 6, 7, 8, 7, 8, 9, 8]
        # [7, 8, 7, 8, 7, 8, 7, 8, 7, 8, 9, 8, 9, 10]
        # [8, 7, 8, 7, 8, 7, 8, 7, 8, 9, 8, 9, 10, 9, 10]
        # [9, 8, 9, 8, 9, 8, 9, 8, 9, 8, 9, 10, 9, 10, 11, 10]

        x, y = abs(x), abs(y)
        if x < y:
            x, y = y, x
        lookup = {(0, 0):0, (1, 0):3, (2, 2):4}  # special cases
        if (x, y) in lookup:
            return lookup[(x, y)]
        delta = x-y
        if y > delta:  # if 2y > x, every period 3 of y with same delta is increased by 2
            return delta - 2*((delta-y)//3)
        # if 2y <= x, every period 4 of y with same delta is increased by 2
        return delta - 2*((delta-y)//4)


# Time:  O(n^2)
# Space: O(n^2)
class Solution2(object):
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
            if (x, y) not in lookup:
                lookup[(x, y)] = min(dp(x-1, y-2, lookup),
                                     dp(x-2, y-1, lookup)) + 1
            return lookup[(x, y)]
        return dp(x, y, {(0, 0):0, (1, 1):2, (1, 0):3})  # special cases
