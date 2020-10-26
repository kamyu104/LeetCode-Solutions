# Time:  O(m * n)
# Space: O(1)

# dp solution
class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[i])):
                if not matrix[i][j]:
                    continue
                matrix[i][j] = float("inf")
                if i > 0:
                    matrix[i][j] = min(matrix[i][j], matrix[i-1][j]+1)
                if j > 0:
                    matrix[i][j] = min(matrix[i][j], matrix[i][j-1]+1)
        for i in reversed(xrange(len(matrix))):
            for j in reversed(xrange(len(matrix[i]))):
                if not matrix[i][j]:
                    continue
                if i < len(matrix)-1:
                    matrix[i][j] = min(matrix[i][j], matrix[i+1][j]+1)
                if j < len(matrix[i])-1:
                    matrix[i][j] = min(matrix[i][j], matrix[i][j+1]+1)
        return matrix


# Time:  O(m * n)
# Space: O(m * n)
# dp solution
class Solution2(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        dp = [[float("inf")]*len(matrix[0]) for _ in xrange(len(matrix))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[i])):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                else:
                    if i > 0:
                        dp[i][j] = min(dp[i][j], dp[i-1][j]+1)
                    if j > 0:
                        dp[i][j] = min(dp[i][j], dp[i][j-1]+1)
        for i in reversed(xrange(len(matrix))):
            for j in reversed(xrange(len(matrix[i]))):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                else:
                    if i < len(matrix)-1:
                        dp[i][j] = min(dp[i][j], dp[i+1][j]+1)
                    if j < len(matrix[i])-1:
                        dp[i][j] = min(dp[i][j], dp[i][j+1]+1)
        return dp


# Time:  O(m * n)
# Space: O(m * n)
import collections


class Solution3(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        queue = collections.deque()
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
                if not (0 <= i < len(matrix) and
                        0 <= j < len(matrix[0]) and
                        matrix[i][j] > matrix[cell[0]][cell[1]]+1):
                    continue
                queue.append((i, j))
                matrix[i][j] = matrix[cell[0]][cell[1]]+1

        return matrix
