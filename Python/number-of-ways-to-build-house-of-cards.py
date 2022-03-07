# Time:  O(n^2)
# Space: O(n)

# dp
class Solution(object):
    def houseOfCards(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0]*(n+1)  # dp[i]: number of ways with i cards and at most t triangles in the first row
        dp[0] = 1
        for t in xrange(1, (n+1)//3+1):
            for i in reversed(xrange(3*t-1, n+1)):
                dp[i] += dp[i-(3*t-1)]
        return dp[n]


# Time:  O(n^3)
# Space: O(n^2)
# dp
class Solution_TLE(object):
    def houseOfCards(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0]*(n+1) for _ in xrange((n+1)//3+1)]  # dp[t][i]: number of ways with i cards and t triangles in the first row
        dp[0][0] = 1
        for t in xrange(1, (n+1)//3+1):
            for i in xrange(3*t-1, n+1):
                dp[t][i] = sum(dp[j][i-(3*t-1)] for j in xrange(t))
        return sum(dp[t][n] for t in xrange((n+1)//3+1))
