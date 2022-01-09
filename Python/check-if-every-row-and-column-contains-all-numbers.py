# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def checkValid(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        return all(reduce(lambda x, y: x^y, (matrix[i][j]^(j+1) for j in xrange(len(matrix[0])))) == 0 for i in xrange(len(matrix))) and \
               all(reduce(lambda x, y: x^y, (matrix[i][j]^(i+1) for i in xrange(len(matrix)))) == 0 for j in xrange(len(matrix[0])))
