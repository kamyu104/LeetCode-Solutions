# Time:  O(m * n)
# Space: O(n)

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m, n = len(word1), len(word2)
        dp = [[0] * (n+1) for _ in xrange(2)]
        for i in xrange(m):
            for j in xrange(n):
                dp[(i+1)%2][j+1] = max(dp[i%2][j+1], \
                                       dp[(i+1)%2][j], \
                                       dp[i%2][j] + (word1[i] == word2[j]))
        return m + n - 2*dp[m%2][n]

