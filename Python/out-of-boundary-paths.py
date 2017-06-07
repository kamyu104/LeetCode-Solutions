# Time:  O(N * m * n)
# Space: O(m * n)

# There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball,
# you can move the ball to adjacent cell or cross the grid boundary in
# four directions (up, down, left, right). However, you can at most move N times.
# Find out the number of paths to move the ball out of grid boundary.
# The answer may be very large, return it after mod 109 + 7.
#
# Example 1:
# Input:m = 2, n = 2, N = 2, i = 0, j = 0
# Output: 6
#
# Example 2:
# Input:m = 1, n = 3, N = 3, i = 0, j = 1
# Output: 12
#
# Note:
# Once you move the ball out of boundary, you cannot move it back.
# The length and height of the grid is in range [1,50].
# N is in range [0,50].

class Solution(object):
    def findPaths(self, m, n, N, x, y):
        """
        :type m: int
        :type n: int
        :type N: int
        :type x: int
        :type y: int
        :rtype: int
        """
        M = 1000000000 + 7
        dp = [[[0 for _ in xrange(n)] for _ in xrange(m)] for _ in xrange(2)]
        for moves in xrange(N):
            for i in xrange(m):
                for j in xrange(n):
                    dp[(moves + 1) % 2][i][j] = (((1 if (i == 0) else dp[moves % 2][i - 1][j]) + \
                                                  (1 if (i == m - 1) else dp[moves % 2][i + 1][j])) % M + \
                                                 ((1 if (j == 0) else dp[moves % 2][i][j - 1]) + \
                                                  (1 if (j == n - 1) else dp[moves % 2][i][j + 1])) % M) % M
        return dp[N % 2][x][y]
