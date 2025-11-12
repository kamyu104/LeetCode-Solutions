# Time:  O(m * n * k)
# Space: O(m * n * k)

# dp
class Solution(object):
    def maxPathScore(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        DIRECTIONS = ((1, 0), (0, 1))
        dp = [[[-1]*(k+1) for _ in xrange(len(grid[0]))] for _ in xrange(len(grid))]
        dp[0][0][0] = 0
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                for c in xrange(k+1):
                    if dp[i][j][c] == -1:
                        continue
                    for di, dj in DIRECTIONS:
                        ni, nj = i+di, j+dj
                        if not (0 <= ni < len(grid) and 0 <= nj < len(grid[0]) and c+(1 if grid[ni][nj] else 0) <= k):
                            continue
                        nc = c+(1 if grid[ni][nj] else 0)
                        dp[ni][nj][nc] = max(dp[ni][nj][nc] , dp[i][j][c]+grid[ni][nj])
        return max(dp[-1][-1])
