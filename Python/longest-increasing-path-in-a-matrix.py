# Time:  O(m * n)
# Space: O(m * n)

class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix:
            return 0

        def longestpath(matrix, i, j, max_lengths):
            if max_lengths[i][j]:
                return max_lengths[i][j]

            max_depth = 0
            directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
            for d in directions:
                x, y = i + d[0], j + d[1]
                if 0 <= x < len(matrix) and 0 <= y < len(matrix[0]) and \
                   matrix[x][y] < matrix[i][j]:
                    max_depth = max(max_depth, longestpath(matrix, x, y, max_lengths))
            max_lengths[i][j] = max_depth + 1
            return max_lengths[i][j]

        res = 0
        max_lengths = [[0 for _ in xrange(len(matrix[0]))] for _ in xrange(len(matrix))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                res = max(res, longestpath(matrix, i, j, max_lengths))

        return res

