# Time:  O(m * n)
# Space: O(n)

class Solution(object):
    def countPyramids(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def count(grid, reverse):
            def get_grid(i, j):
                return grid[~i][j] if reverse else grid[i][j]

            result = 0
            dp = [0]*len(grid[0])
            for i in xrange(1, len(grid)):
                new_dp = [0]*len(grid[0])
                for j in xrange(1, len(grid[0])-1):
                    if get_grid(i, j) == get_grid(i-1, j-1) == get_grid(i-1, j) == get_grid(i-1, j+1) == 1:
                        new_dp[j] = min(dp[j-1], dp[j+1])+1
                dp = new_dp
                result += sum(dp)
            return result
        
        return count(grid, False) + count(grid, True)


# Time:  O(m * n)
# Space: O(m * n)
class Solution2(object):
    def countPyramids(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def count(grid):
            dp = [[0 for _ in xrange(len(grid[0]))] for _ in xrange(len(grid))]
            for i in xrange(1, len(grid)):
                for j in xrange(1, len(grid[0])-1):
                    if grid[i][j] == grid[i-1][j-1] == grid[i-1][j] == grid[i-1][j+1] == 1:
                        dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])+1
            return sum(sum(row) for row in dp)
        
        return count(grid) + count(grid[::-1])
