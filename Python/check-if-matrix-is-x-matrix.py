# Time:  O(n^2)
# Space: O(1)

# array
class Solution(object):
    def checkXMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        return all((i-j == 0 or i+j == len(grid)-1) == (grid[i][j] != 0) for i in xrange(len(grid)) for j in xrange(len(grid[0])))
