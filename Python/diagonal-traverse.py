# Time:  O(m * n)
# Space: O(1)

# Given a matrix of M x N elements (M rows, N columns),
# return all elements of the matrix in diagonal order as shown in the below image.
#
# Example:
# Input:
# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
# Output:  [1,2,4,7,5,3,6,8,9]
# Explanation:
#
# Note:
# The total number of elements of the given matrix will not exceed 10,000.
# Show Company Tags

class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        
        result = []
        row, col, d = 0, 0, 0
        dirs = [(-1, 1), (1, -1)]
        
        for i in xrange(len(matrix) * len(matrix[0])):
            result.append(matrix[row][col])
            row += dirs[d][0]
            col += dirs[d][1]

            if row >= len(matrix):
                row = len(matrix) - 1
                col += 2
                d = 1 - d
            elif col >= len(matrix[0]):
                col = len(matrix[0]) - 1
                row += 2
                d = 1 - d
            elif row < 0:
                row = 0
                d = 1 - d
            elif col < 0:
                col = 0
                d = 1 - d
        
        return result
 
