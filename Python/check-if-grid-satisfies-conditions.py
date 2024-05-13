# Time:  O(m * n)
# Space: O(1)

# array
class Solution(object):
    def satisfiesConditions(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        return (all(grid[i][j] == grid[i+1][j] for j in xrange(len(grid[0])) for i in xrange(len(grid)-1)) and 
                all(grid[0][j] != grid[0][j+1] for j in xrange(len(grid[0])-1)))
