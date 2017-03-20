# Time:  O(n)
# Space: O(n)

# Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
# The distance between two adjacent cells is 1.
#
# Example 1: 
#
# Input:
# 0 0 0
# 0 1 0
# 0 0 0
#
# Output:
# 0 0 0
# 0 1 0
# 0 0 0
#
# Example 2: 
#
# Input:
# 0 0 0
# 0 1 0
# 1 1 1
#
# Output:
# 0 0 0
# 0 1 0
# 1 2 1
#
# Note:
# The number of elements of the given matrix will not exceed 10,000.
# There are at least one 0 in the given matrix.
# The cells are adjacent in only four directions: up, down, left and right.

class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        queue = collections.deque([])
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if matrix[i][j] == 0:
                    queue.append((i, j))
                else:
                    matrix[i][j] = float("inf")

        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while queue:
            cell = queue.popleft()
            for dir in dirs:
                i, j = cell[0]+dir[0], cell[1]+dir[1]
                if not (0 <= i < len(matrix)) or not (0 <= j < len(matrix[0])) or \
                   matrix[i][j] <= matrix[cell[0]][cell[1]]+1:
                        continue
                queue.append((i, j))
                matrix[i][j] = matrix[cell[0]][cell[1]]+1
        
        return matrix
