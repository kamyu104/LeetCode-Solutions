# Time:  O(n * m)
# Space: O(n * m)

# dp
class Solution(object):
    def lenOfVDiagonal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m = len(grid), len(grid[0])
        result = 0
        down_right = [[1]*m for _ in xrange(n)]
        down_left = [[1]*m for _ in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
                x = grid[i][j]
                if x == 1:
                    result = 1
                    continue
                if i-1 >= 0 and j-1 >= 0 and grid[i-1][j-1] == 2-x:
                    down_right[i][j] = down_right[i-1][j-1]+1
                if i-1 >= 0 and j+1 < m and grid[i-1][j+1] == 2-x:
                    down_left[i][j] = down_left[i-1][j+1]+1
        up_right = [[1]*m for _ in xrange(n)]
        up_left = [[1]*m for _ in xrange(n)]
        for i in reversed(xrange(n)):
            for j in xrange(m):
                x = grid[i][j]
                if x == 1:
                    continue
                if i+1 < n and j-1 >= 0 and grid[i+1][j-1] == 2-x:
                    up_right[i][j] = up_right[i+1][j-1]+1
                if i+1 < n and j+1 < m and grid[i+1][j+1] == 2-x:
                    up_left[i][j] = up_left[i+1][j+1]+1
        for i in xrange(n):
            for j in xrange(m):
                x = grid[i][j]
                if x == 1:
                    continue
                if (down_right[i][j]%2*2 == 0 and x == 0) or (down_right[i][j]%2 == 1 and x == 2):
                    ni = i-down_right[i][j]
                    nj = j-down_right[i][j]
                    if 0 <= ni < n and 0 <= nj < m and grid[ni][nj] == 1:
                        result = max(result, down_right[i][j]+up_right[i][j])  # >
                if (down_left[i][j]%2 == 0 and x == 0) or (down_left[i][j]%2 == 1 and x == 2):
                    ni = i-down_left[i][j]
                    nj = j+down_left[i][j]
                    if 0 <= ni< n and 0 <= nj < m and grid[ni][nj] == 1:
                        result = max(result, down_left[i][j]+down_right[i][j])  # v
                if (up_left[i][j]%2 == 0 and x == 0) or (up_left[i][j]%2 == 1 and x == 2):
                    ni = i+up_left[i][j]
                    nj = j+up_left[i][j]
                    if 0 <= ni < n and 0 <= nj < m and grid[ni][nj] == 1:
                        result = max(result, up_left[i][j]+down_left[i][j])  # <
                if (up_right[i][j]%2 == 0 and x == 0) or (up_right[i][j]%2 == 1 and x == 2):
                    ni = i+up_right[i][j]
                    nj = j-up_right[i][j]
                    if 0 <= ni < n and 0 <= nj < m and grid[ni][nj] == 1:
                        result = max(result, up_right[i][j]+up_left[i][j])  # ^
        return result
