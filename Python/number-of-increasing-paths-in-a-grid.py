# Time:  O(m * n)
# Space: O(m * n)

# top-down dp, memoization
class Solution(object):
    def countPaths(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def memoization(grid, i, j, lookup):
            if not lookup[i][j]:
                lookup[i][j] = 1
                for di, dj in directions:
                    ni, nj = i+di, j+dj
                    if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]) and grid[i][j] < grid[ni][nj]:
                        lookup[i][j] = (lookup[i][j]+memoization(grid, ni, nj, lookup)) % MOD
            return lookup[i][j]

        lookup = [[0]*len(grid[0]) for _ in xrange(len(grid))]
        return sum(memoization(grid, i, j, lookup) for i in xrange(len(grid)) for j in xrange(len(grid[0]))) % MOD
