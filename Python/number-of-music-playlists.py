# Time:  O(n * l)
# Space: O(l)

# Another better solution (generating function), you could refer to 
# https://leetcode.com/problems/number-of-music-playlists/solution/

# Your music player contains N different songs and she wants to listen to
# L (not necessarily different) songs during your trip.
# You create a playlist so that:
#
# Every song is played at least once
# A song can only be played again only if K other songs have been played
# Return the number of possible playlists.
# As the answer can be very large, return it modulo 10^9 + 7.
#
# Example 1:
#
# Input: N = 3, L = 3, K = 1
# Output: 6
# Explanation: There are 6 possible playlists.
#              [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
# Example 2:
#
# Input: N = 2, L = 3, K = 0
# Output: 6
# Explanation: There are 6 possible playlists.
#              [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
# Example 3:
#
# Input: N = 2, L = 3, K = 1
# Output: 2
# Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
#
# Note:
# - 0 <= K < N <= L <= 100

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
