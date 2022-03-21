# Time:  O(m * n)
# Space: O(m * n)

# dp
class Solution(object):
    def minimumWhiteTiles(self, floor, numCarpets, carpetLen):
        """
        :type floor: str
        :type numCarpets: int
        :type carpetLen: int
        :rtype: int
        """
        dp = [[0]*(numCarpets+1) for _ in xrange(len(floor)+1)]  # dp[i][j] : min number of white tiles in the first i floors with j carpets
        for i in xrange(1, len(dp)):
            dp[i][0] = dp[i-1][0] + int(floor[i-1])
            for j in xrange(1, numCarpets+1):
                dp[i][j] = min(dp[i-1][j] + int(floor[i-1]), dp[max(i-carpetLen, 0)][j-1])
        return dp[-1][-1]
