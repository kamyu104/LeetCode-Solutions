# Time:  O(m * n * r), r = max(x for row in grid for x in row)
# Space: O(n * r)

# dp
class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        mx = max(x for row in grid for x in row)
        l = 1<<mx.bit_length()
        dp = [[False]*l for _ in xrange(len(grid[0]))]
        dp[0][0] = True
        for i in xrange(len(grid)):
            new_dp = [[False]*l for _ in xrange(len(grid[0]))]
            for j in xrange(len(grid[0])):
                for k in xrange(l):
                    if dp[j][k] or (j-1 >= 0 and new_dp[j-1][k]):
                        new_dp[j][k^grid[i][j]] = True
            dp = new_dp
        return next(i for i in xrange(l) if dp[-1][i])


# Time:  O(m * n * r), r = max(x for row in grid for x in row)
# Space: O(n * r)
# dp
class Solution2(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dp = [set() for _ in xrange(len(grid[0]))]
        dp[0].add(0)
        for i in xrange(len(grid)):
            new_dp = [set() for _ in xrange(len(grid[0]))]
            for j in xrange(len(grid[0])):
                for k in dp[j]|(new_dp[j-1] if j-1 >= 0 else set()):
                    new_dp[j].add(k^grid[i][j])
            dp = new_dp
        return min(dp[-1])
