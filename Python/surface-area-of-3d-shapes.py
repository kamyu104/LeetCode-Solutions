# Time:  O(n^2)
# Space: O(1)

class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        result = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid)):
                if grid[i][j]:
                    result += 2 + grid[i][j]*4
                if i:
                    result -= min(grid[i][j], grid[i-1][j])*2
                if j:
                    result -= min(grid[i][j], grid[i][j-1])*2
        return result

