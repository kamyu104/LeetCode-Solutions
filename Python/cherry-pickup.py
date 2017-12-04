# Time:  O(n^3)
# Space: O(n^2)

# In a N x N grid representing a field of cherries, each cell is one of three possible integers.
#
# 0 means the cell is empty, so you can pass through;
# 1 means the cell contains a cherry, that you can pick up and pass through;
# -1 means the cell contains a thorn that blocks your way.
# Your task is to collect maximum number of cherries possible by following the rules below:
#
# Starting at the position (0, 0) and reaching (N-1, N-1) by moving right
# or down through valid path cells (cells with value 0 or 1);
#
# After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
# When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
# If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
# Example 1:
# Input: grid =
# [[0, 1, -1],
#  [1, 0, -1],
#  [1, 1,  1]]
# Output: 5
# Explanation: 
# The player started at (0, 0) and went down, down, right right to reach (2, 2).
# 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
# Then, the player went left, up, up, left to return home, picking up one more cherry.
# The total number of cherries picked up is 5, and this is the maximum possible.
#
# Note:
# - grid is an N by N 2D array, with 1 <= N <= 50.
# - Each grid[i][j] is an integer in the set {-1, 0, 1}.
# - It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # dp holds the max # of cherries two k-length paths can pickup.
        # The two k-length paths arrive at (i, k - i) and (j, k - j), 
        # respectively.
        n = len(grid)
        dp = [[-1 for _ in xrange(n)] for _ in xrange(n)]
        dp[0][0] = grid[0][0]
        max_len = 2 * (n-1)
        directions = [(0, 0), (-1, 0), (0, -1), (-1, -1)]
        for k in xrange(1, max_len+1):
            for i in reversed(xrange(max(0, k-n+1), min(k+1, n))):  # 0 <= i < n, 0 <= k-i < n
                for j in reversed(xrange(i, min(k+1, n))):          # i <= j < n, 0 <= k-j < n
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
