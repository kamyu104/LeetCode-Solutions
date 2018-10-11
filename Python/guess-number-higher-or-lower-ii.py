# Time:  O(n^2)
# Space: O(n^2)

class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        pay = [[0] * n for _ in xrange(n+1)]
        for i in reversed(xrange(n)):
            for j in xrange(i+1, n):
                pay[i][j] = min(k+1 + max(pay[i][k-1], pay[k+1][j]) \
                                for k in xrange(i, j+1))
        return pay[0][n-1]

