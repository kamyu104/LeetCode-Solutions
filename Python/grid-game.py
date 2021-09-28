# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def gridGame(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        result = float("inf")
        left, right = 0, sum(grid[0])
        for a, b in itertools.izip(grid[0], grid[1]):
            right -= a
            result = min(result, max(left, right))
            left += b
        return result
