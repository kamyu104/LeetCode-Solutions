# Time:  O(m * n)
# Space: O(m + n)

# array
class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        rows = [sum(grid[i][j] for j in xrange(len(grid[0]))) for i in xrange(len(grid))]
        cols = [sum(grid[i][j] for i in xrange(len(grid))) for j in xrange(len(grid[0]))]
        return [[rows[i]+cols[j]-(len(grid)-rows[i])-(len(grid[0])-cols[j]) for j in xrange(len(grid[0]))] for i in xrange(len(grid))]
