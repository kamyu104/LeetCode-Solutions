# Time:  O(m + n)
# Space: O(1)

class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        result, c = 0, len(grid[0])-1
        for row in grid:
            while c >= 0 and row[c] < 0:
                c -= 1
            result += len(grid[0])-1-c
        return result
