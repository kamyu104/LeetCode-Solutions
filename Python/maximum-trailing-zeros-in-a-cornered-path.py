# Time:  O(m * n)
# Spac:  O(m * n)

import itertools


# prefix sum
class Solution(object):
    def maxTrailingZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def factor(x, lookup):
            if x not in lookup:
                cnt = [0]*2
                y = x
                for i, p in enumerate([2, 5]):
                    while y and y%p == 0:
                        y //= p
                        cnt[i] += 1
                lookup[x] = cnt
            return lookup[x]

        def add(a, b):
            return [x+y for x, y in itertools.izip(a, b)]

        def sub(a, b):
            return [x-y for x, y in itertools.izip(a, b)]

        lookup = {}
        left = [[None for _ in xrange(len(grid[0]))] for _ in xrange(len(grid))]
        for i in xrange(len(grid)):
            left[i][0] = factor(grid[i][0], lookup)
            for j in xrange(1, len(grid[0])):
                left[i][j] = add(left[i][j-1], factor(grid[i][j], lookup))
        result = 0
        for j in xrange(len(grid[0])):
            total = [0]*2
            for i in xrange(len(grid)):
                total = add(total, factor(grid[i][j], lookup))
            up = [0]*2
            for i in xrange(len(grid)):
                right = sub(left[i][-1], left[i][j-1] if j else [0]*2)
                result = max(result, min(add(left[i][j], up)), min(add(right, up)))
                up = add(up, factor(grid[i][j], lookup))
                down = sub(total, up)
                result = max(result, min(add(left[i][j], down)), min(add(right, down)))
        return result
