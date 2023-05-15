# Time:  O(m * n)
# Space: O(m)

# dp
class Solution(object):
    def maxMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [True]*len(grid)
        result = 0
        for c in xrange(len(grid[0])-1):
            new_dp = [False]*len(grid)
            for r in xrange(len(grid)):
                if not dp[r]:
                    continue
                if grid[r][c] < grid[r][c+1]:
                    new_dp[r] = True
                if r-1 >= 0 and grid[r][c] < grid[r-1][c+1]:
                    new_dp[r-1] = True
                if r+1 < len(grid) and grid[r][c] < grid[r+1][c+1]:
                    new_dp[r+1] = True
            dp = new_dp
            if not sum(dp):
                return c
        return len(grid[0])-1


# Time:  O(m * n)
# Space: O(m)
# dp
class Solution2(object):
    def maxMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [0]*len(grid)
        for c in reversed(xrange(len(grid[0])-1)):
            new_dp = [0]*len(grid)
            for r in xrange(len(grid)):
                if grid[r][c] < grid[r][c+1]:
                    new_dp[r] = max(new_dp[r], dp[r]+1)
                if r-1 >= 0 and grid[r][c] < grid[r-1][c+1]:
                    new_dp[r] = max(new_dp[r], dp[r-1]+1)
                if r+1 < len(grid) and grid[r][c] < grid[r+1][c+1]:
                    new_dp[r] = max(new_dp[r], dp[r+1]+1)
            dp = new_dp
        return max(dp)
