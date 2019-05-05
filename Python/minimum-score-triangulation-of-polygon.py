# Time:  O(n^3)
# Space: O(n^2)

class Solution(object):
    def minScoreTriangulation(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        dp = [[0 for _ in xrange(len(A))] for _ in xrange(len(A))]
        for p in xrange(3, len(A)+1):
            for i in xrange(len(A)-p+1):
                j = i+p-1;
                dp[i][j] = float("inf")
                for k in xrange(i+1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j] + A[i]*A[j]*A[k])
        return dp[0][-1]
