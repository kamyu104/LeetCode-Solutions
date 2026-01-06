# Time:  O(n * m)
# Space: O(m)

# dp, two pointers
class Solution(object):
    def numberOfRoutes(self, grid, d):
        """
        :type grid: List[str]
        :type d: int
        :rtype: int
        """
        MOD = 10**9+7
        def update(dp, d, arr):
            new_dp = [0]*len(arr)
            curr = reduce(lambda accu, x: (accu+x)%MOD, (dp[i] for i in xrange(min(d, len(dp)))), 0)
            for i in xrange(len(arr)):
                if i-d-1 >= 0:
                    curr = (curr-dp[i-d-1])%MOD
                if i+d < len(arr):
                    curr = (curr+dp[i+d])%MOD
                new_dp[i] = curr if arr[i] == '.' else 0
            return new_dp
    
        dp = [1]*len(grid[0])
        for i in reversed(xrange(len(grid))):
            dp = update(dp, d-1 if i != len(grid)-1 else 0, grid[i])
            dp = update(dp, d, grid[i])
        return reduce(lambda accu, x: (accu+x)%MOD, dp, 0)
