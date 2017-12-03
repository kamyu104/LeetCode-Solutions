# Time:  O(n^3)
# Space: O(n^2)

class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # dp holds the max # of cherries two k-length paths can pickup.
        # The two k-length paths arrive at (i, k - i) and (j, k - j), 
        # respectively.
        n = len(grid);
        dp = [[-1 for _ in xrange(n)] for _ in xrange(n)]
        dp[0][0] = grid[0][0]
        max_len = 2 * (n-1)
        directions = [(0, 0), (-1, 0), (0, -1), (-1, -1)]
        for k in xrange(1, max_len+1):
            for i in reversed(xrange(min(k+1, n))):
                for j in reversed(xrange(i, min(k+1, n))):
                    if not (0 <= k-i < n and 0 <= k-j < n):
                        continue
                    if grid[i][k-i] == -1 or grid[j][k-j] == -1:
                        dp[i][j] = -1
                        continue
                    cnt = grid[i][k-i]
                    if i != j:
                        cnt += grid[j][k-j]
                    max_cnt = -1
                    for direction in directions:
                        ii, jj = i+direction[0], j+direction[1]
                        if ii >= 0 and jj >= 0 and dp[ii][jj] >= 0:
                            max_cnt = max(max_cnt, dp[ii][jj]+cnt)
                    dp[i][j] = max_cnt
        return max(dp[n-1][n-1], 0)
