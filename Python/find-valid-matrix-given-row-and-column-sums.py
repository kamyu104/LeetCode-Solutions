# Time:  O(m + n), excluding ctor of result
# Space: O(1)

# optimized from Solution2 since we can find next i, j pair without nested loops
class Solution(object):
    def restoreMatrix(self, rowSum, colSum):
        """
        :type rowSum: List[int]
        :type colSum: List[int]
        :rtype: List[List[int]]
        """
        matrix = [[0]*len(colSum) for _ in xrange(len(rowSum))]
        i = j = 0
        while i < len(matrix) and j < len(matrix[0]):
            matrix[i][j] = min(rowSum[i], colSum[j])  # greedily used
            rowSum[i] -= matrix[i][j]
            colSum[j] -= matrix[i][j]
            if not rowSum[i]:  # won't be used in row i, ++i
                i += 1
            if not colSum[j]:  # won't be used in col j, ++j
                j += 1
        return matrix


# Time:  O(m * n)
# Space: O(1)
class Solution2(object):
    def restoreMatrix(self, rowSum, colSum):
        """
        :type rowSum: List[int]
        :type colSum: List[int]
        :rtype: List[List[int]]
        """
        matrix = [[0]*len(colSum) for _ in xrange(len(rowSum))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[i])):
                matrix[i][j] = min(rowSum[i], colSum[j])  # greedily used
                rowSum[i] -= matrix[i][j]
                colSum[j] -= matrix[i][j]
        return matrix
