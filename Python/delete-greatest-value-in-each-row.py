# Time:  O(m * nlogn)
# Space: O(1)

# array
class Solution(object):
    def deleteGreatestValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for row in grid:
            row.sort()
        return sum(max(grid[i][j] for i in xrange(len(grid))) for j in xrange(len(grid[0])))
