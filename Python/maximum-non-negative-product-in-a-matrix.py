# Time:  O(m * n)
# Space: O(n)

# dp with rolling window
class Solution(object):
    def maxProductPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        max_dp = [[0]*len(grid[0]) for _ in xrange(2)]
        min_dp = [[0]*len(grid[0]) for _ in xrange(2)]
        for i in xrange(len(grid)):
            for j in xrange(len(grid[i])):
                if i == 0 and j == 0:
                    max_dp[i%2][j] = min_dp[i%2][j] = grid[i][j]
                    continue
                curr_max = max(max_dp[(i-1)%2][j] if i > 0 else max_dp[i%2][j-1],
                               max_dp[i%2][j-1] if j > 0 else max_dp[(i-1)%2][j])
                curr_min = min(min_dp[(i-1)%2][j] if i > 0 else min_dp[i%2][j-1],
                               min_dp[i%2][j-1] if j > 0 else min_dp[(i-1)%2][j])
                if grid[i][j] < 0:
                    curr_max, curr_min = curr_min, curr_max
                max_dp[i%2][j] = curr_max*grid[i][j]
                min_dp[i%2][j] = curr_min*grid[i][j]
        return max_dp[(len(grid)-1)%2][-1]%MOD if max_dp[(len(grid)-1)%2][-1] >= 0 else -1
