# Time:  O(n^2)
# Space: O(1)
#
# Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
# 
# For example,
# Given n = 3,
# 
# You should return the following matrix:
# [
#  [ 1, 2, 3 ],
#  [ 8, 9, 4 ],
#  [ 7, 6, 5 ]
# ]
#

class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        matrix = [[0 for i in range(n)] for i in range(n)]
        
        left, right, top, bottom, num = 0, n - 1, 0, n - 1, 1
        
        while left <= right and top <= bottom:
            for j in xrange(left, right + 1):
                matrix[top][j] = num
                num += 1
            for i in xrange(top + 1, bottom):
                matrix[i][right] = num
                num += 1
            for j in reversed(xrange(left, right + 1)):
                if top < bottom:
                    matrix[bottom][j] = num
                    num += 1
            for i in reversed(xrange(top + 1, bottom)):
                if left < right:
                    matrix[i][left] = num
                    num += 1
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1
            
        return matrix


if __name__ == "__main__":
    print Solution().generateMatrix(3)
    print Solution().generateMatrix(8)