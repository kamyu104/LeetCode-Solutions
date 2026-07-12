# Time:  O((logk)^2)
# Space: O(1)

# constructive algorithms
class Solution(object):
    def createGrid(self, k):
        """
        :type k: int
        :rtype: List[str]
        """
        l = k.bit_length()
        m, n = 2*l, l+3
        result = [['#']*n for _ in xrange(m)]
        for i in xrange(l):
            r = 2*i
            result[r][i] = result[r][i+1] = result[r+1][i] = result[r+1][i+1] = '.'
            if not (k&(1<<i)):
                continue
            for c in xrange(i+2, n):
                result[r][c] = '.'
        for r in xrange(m):
            result[r][n-1] = '.'
        return ["".join(row) for row in result]
