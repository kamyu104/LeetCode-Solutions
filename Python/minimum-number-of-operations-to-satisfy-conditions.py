# Time:  O(n * (m + 10))
# Space: O(10)

# dp
class Solution(object):
    def minimumOperations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        MAX_VALUE = 9
        dp = [0]*(MAX_VALUE+1)
        for j in xrange(len(grid[0])):
            new_dp = [INF]*(MAX_VALUE+1)
            cnt = [0]*(MAX_VALUE+1)
            for i in xrange(len(grid)):
                cnt[grid[i][j]] += 1
            k1 = min(xrange(MAX_VALUE+1), key=lambda x: dp[x])
            k2 = min((i for i in xrange(MAX_VALUE+1) if i != k1), key=lambda x: dp[x])
            for i in xrange(MAX_VALUE+1):
                new_dp[i] = min(new_dp[i], (dp[k1] if i != k1 else dp[k2])+(len(grid)-cnt[i]))
            dp = new_dp
        return min(dp)


# Time:  O(n * (m + 100))
# Space: O(10)
# dp
class Solution2(object):
    def minimumOperations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        MAX_VALUE = 9
        dp = [0]*(MAX_VALUE+1)
        for j in xrange(len(grid[0])):
            new_dp = [INF]*(MAX_VALUE+1)
            cnt = [0]*(MAX_VALUE+1)
            for i in xrange(len(grid)):
                cnt[grid[i][j]] += 1
            for i in xrange(MAX_VALUE+1):
                new_dp[i] = min(new_dp[i], min(dp[k] for k in xrange(MAX_VALUE+1) if k != i)+(len(grid)-cnt[i]))
            dp = new_dp
        return min(dp)
