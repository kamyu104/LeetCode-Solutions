# Time:  O(m * n)
# Space: O(m * n)

class Solution(object):
    def matrixBlockSum(self, mat, K):
        """
        :type mat: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        m, n = len(mat), len(mat[0])
        accu = [[0 for _ in xrange(n+1)] for _ in xrange(m+1)]
        for i in xrange(m):
            for j in xrange(n):
                accu[i+1][j+1] = accu[i+1][j]+accu[i][j+1]-accu[i][j]+mat[i][j]
        result = [[0 for _ in xrange(n)] for _ in xrange(m)]        
        for i in xrange(m):
            for j in xrange(n):
                r1, c1, r2, c2 = max(i-K, 0), max(j-K, 0), min(i+K+1, m), min(j+K+1, n)
                result[i][j] = accu[r2][c2]-accu[r1][c2]-accu[r2][c1]+accu[r1][c1]
        return result
