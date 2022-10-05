# Time:  O(m * n)
# Space: O(1)

# brute force
class Solution(object):
    def maxSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def total(i, j):
            return (grid[i][j]+grid[i][j+1]+grid[i][j+2]+
                               grid[i+1][j+1]+
                    grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2])

        return max(total(i, j) for i in xrange(len(grid)-2) for j in xrange(len(grid[0])-2))
