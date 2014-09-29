# Time:  O(m * n)
# Space: O(1)
#
# Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
# 
# Follow up:
# Did you use extra space?
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?
#

class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        first_col = reduce(lambda acc, i: acc or matrix[i][0] == 0, xrange(len(matrix)), False)
        first_row = reduce(lambda acc, j: acc or matrix[0][j] == 0, xrange(len(matrix[0])), False)
        
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0], matrix[0][j] = 0, 0
        
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        if first_col:
            for i in xrange(len(matrix)):
                matrix[i][0] = 0
                
        if first_row:
            for j in xrange(len(matrix[0])):
                matrix[0][j] = 0

if __name__ == "__main__":
    matrix = [ [1, 0, 1, 1]
             , [1, 1, 0, 1]
             , [1, 1, 1, 0]
             , [1, 1, 1, 1]]
    Solution().setZeroes(matrix)
    print matrix