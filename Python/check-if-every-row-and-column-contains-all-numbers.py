# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def checkValid(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        return all(len(set(row)) == len(matrix) for row in matrix) and all(len(set(matrix[i][j] for i in xrange(len(matrix)))) == len(matrix) for j in xrange(len(matrix[0])))


# Time:  O(n^2)
# Space: O(1)
# [[1,3,3,4,4],[4,1,3,3,4],[4,4,1,3,3],[3,4,4,1,3],[3,3,4,4,1]]
class Solution_Wrong(object):
    def checkValid(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        return all(reduce(lambda x, y: x^y, (matrix[i][j]^(j+1) for j in xrange(len(matrix[0])))) == 0 for i in xrange(len(matrix))) and \
               all(reduce(lambda x, y: x^y, (matrix[i][j]^(i+1) for i in xrange(len(matrix)))) == 0 for j in xrange(len(matrix[0])))
