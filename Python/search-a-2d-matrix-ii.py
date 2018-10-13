# Time:  O(m + n)
# Space: O(1)

class Solution(object):
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        if m == 0:
            return False

        n = len(matrix[0])
        if n == 0:
            return False

        i, j = 0, n - 1
        while i < m and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1

        return False

