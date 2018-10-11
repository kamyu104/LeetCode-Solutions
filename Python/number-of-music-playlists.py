# Time:  O(n * l)
# Space: O(l)

class Solution(object):
    def numMusicPlaylists(self, N, L, K):
        """
        :type N: int
        :type L: int
        :type K: int
        :rtype: int
        """
        M = 10**9+7
        dp = [[0 for _ in xrange(1+L)] for _ in xrange(2)]
        dp[0][0] = dp[1][1] = 1
        for n in xrange(1, N+1):
            dp[n % 2][n] = (dp[(n-1) % 2][n-1] * n) % M
            for l in xrange(n+1, L+1):
                dp[n % 2][l] = ((dp[n % 2][l-1] * max(n-K, 0)) % M + \
                                (dp[(n-1) % 2][l-1] * n) % M) % M
        return dp[N % 2][L]

