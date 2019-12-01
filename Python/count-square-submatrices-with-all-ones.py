# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if not matrix[i][j]:
                    continue
                l = min(matrix[i-1][j], matrix[i][j-1])
                matrix[i][j] = l+1 if matrix[i-l][j-l] else l
        return sum(x for row in matrix for x in row)
