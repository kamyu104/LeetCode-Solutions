# Time:  O(n^2)
# Space: O(n)

import itertools


class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row_maxes = [max(row) for row in grid]
        col_maxes = [max(col) for col in itertools.izip(*grid)]

        return sum(min(row_maxes[r], col_maxes[c])-val \
                   for r, row in enumerate(grid) \
                   for c, val in enumerate(row))

