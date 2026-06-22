# Time:  O(m * n)
# Space: O(1)

# array
class Solution(object):
    def createGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: List[str]
        """
        result = [['#']*n for _ in xrange(m)]
        for j in xrange(n):
            result[0][j] = '.'
        for i in xrange(m):
            result[i][-1] = '.'
        return ["".join(row) for row in result]
