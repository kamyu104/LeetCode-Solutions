# Time:  O(m * n)
# Space: O(1)

# array
class Solution(object):
    def modifiedMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        for j in xrange(len(matrix[0])):
            mx = max(matrix[i][j] for i in xrange(len(matrix)))
            for i in xrange(len(matrix)):
                if matrix[i][j] == -1:
                    matrix[i][j] = mx
        return matrix
