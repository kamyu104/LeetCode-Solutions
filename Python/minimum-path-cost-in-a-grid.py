# Time:  O(m * n^2)
# Space: O(n)

# dp
class Solution(object):
    def minPathCost(self, grid, moveCost):
        """
        :type grid: List[List[int]]
        :type moveCost: List[List[int]]
        :rtype: int
        """
        dp = [[0]*len(grid[0]) for _ in xrange(2)]
        dp[0] = [grid[0][j] for j in xrange(len(grid[0]))]
        for i in xrange(len(grid)-1):
            for j in xrange(len(grid[0])):
                dp[(i+1)%2][j] = min(dp[i%2][k]+moveCost[x][j] for k, x in enumerate(grid[i]))+grid[i+1][j]
        return min(dp[(len(grid)-1)%2])
