# Time:  O(logr * mlogn), r = O(right-left+1) = O(10^6), O(logr) = O(20)
# Space: O(1)

import bisect


# binary search
class Solution(object):
    def matrixMedian(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def check(x):
            return sum(bisect_right(row, x) for row in grid) > (len(grid)*len(grid[0]))//2

        left, right = min(row[0] for row in grid), max(row[-1] for row in grid)
        while left <= right:
            mid = left + (right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return left
