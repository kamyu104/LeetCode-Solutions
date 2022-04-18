# Time:  O(m * n)
# Space: O(m * n)

import itertools


# prefix sum
class Solution(object):
    def maxTrailingZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def factor(x):
            cnt = [0]*2
            for i, p in enumerate([2, 5]):
                while x and x%p == 0:
                    x //= p
                    cnt[i] += 1
            return cnt

        def add(a, b):
            return [x+y for x, y in itertools.izip(a, b)]

        def sub(a, b):
            return [x-y for x, y in itertools.izip(a, b)]

        left = [[None for _ in xrange(len(grid[0]))] for _ in xrange(len(grid))]
        for i in xrange(len(grid)):
            left[i][0] = factor(grid[i][0])
            for j in xrange(1, len(grid[0])):
                left[i][j] = add(left[i][j-1], factor(grid[i][j]))
        result = 0
        for j in xrange(len(grid[0])):
            total = [0]*2
            for i in xrange(len(grid)):
                total = add(total, factor(grid[i][j]))
            up = [0]*2
            for i in xrange(len(grid)):
                right = sub(left[i][-1], left[i][j-1] if j else [0]*2)
                result = max(result, min(add(left[i][j], up)), min(add(right, up)))
                up = add(up, factor(grid[i][j]))
                down = sub(total, up)
                result = max(result, min(add(left[i][j], down)), min(add(right, down)))
        return result
