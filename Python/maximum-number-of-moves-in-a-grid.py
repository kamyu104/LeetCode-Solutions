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
                break
        else:
            c = len(grid[0])-1
        return c


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


# Time:  O(m * n)
# Space: O(m)
# bfs
class Solution3(object):
    def maxMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        q = set(xrange(len(grid)))
        for c in xrange(len(grid[0])-1):
            new_q = set()
            for r in q:
                if grid[r][c] < grid[r][c+1]:
                    new_q.add(r)
                if r-1 >= 0 and grid[r][c] < grid[r-1][c+1]:
                    new_q.add(r-1)
                if r+1 < len(grid) and grid[r][c] < grid[r+1][c+1]:
                    new_q.add(r+1)
            q = new_q
            if not q:
                break
        else:
            c = len(grid[0])-1
        return c
