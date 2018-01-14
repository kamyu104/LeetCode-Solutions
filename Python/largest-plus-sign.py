# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        """
        :type N: int
        :type mines: List[List[int]]
        :rtype: int
        """
        lookup = {tuple(mine) for mine in mines}
        dp = [[0] * N for _ in xrange(N)]
        result = 0
        for i in xrange(N):
            l = 0
            for j in xrange(N):
                l = 0 if (i, j) in lookup else l+1
                dp[i][j] = l
            l = 0
            for j in reversed(xrange(N)):
                l = 0 if (i, j) in lookup else l+1
                dp[i][j] = min(dp[i][j], l)
        
        for j in xrange(N):
            l = 0
            for i in xrange(N):
                l = 0 if (i, j) in lookup else l+1
                dp[i][j] = min(dp[i][j], l)
            l = 0
            for i in reversed(xrange(N)):
                l = 0 if (i, j) in lookup else l+1
                dp[i][j] = min(dp[i][j], l)
                result = max(result, dp[i][j])
        return result
