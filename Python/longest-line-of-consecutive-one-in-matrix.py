# Time:  O(m * n)
# Space: O(n)

class Solution(object):
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        if not M: return 0
        result = 0
        dp = [[[0] * 4 for _ in xrange(len(M[0]))] for _ in xrange(2)]
        for i in xrange(len(M)):
            for j in xrange(len(M[0])):
                dp[i % 2][j][:] = [0] * 4
                if M[i][j] == 1:
                    dp[i % 2][j][0] = dp[i % 2][j - 1][0]+1 if j > 0 else 1
                    dp[i % 2][j][1] = dp[(i-1) % 2][j][1]+1 if i > 0 else 1
                    dp[i % 2][j][2] = dp[(i-1) % 2][j-1][2]+1 if (i > 0 and j > 0) else 1
                    dp[i % 2][j][3] = dp[(i-1) % 2][j+1][3]+1 if (i > 0 and j < len(M[0])-1) else 1
                    result = max(result, max(dp[i % 2][j]))
        return result

