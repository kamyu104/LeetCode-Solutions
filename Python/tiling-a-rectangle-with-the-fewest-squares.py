# Time:  O(n^2 * m^2 * m^(n * m)), given m < n
# Space: O(n * m)

class Solution(object):
    def tilingRectangle(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        def find_next(board):
            for i in xrange(len(board)):
                for j in xrange(len(board[0])):
                    if not board[i][j]:
                        return i, j
            return -1, -1

        def find_max_length(board, i, j):
            max_length = 1
            while i+max_length-1 < len(board) and \
                  j+max_length-1 < len(board[0]):
                for r in xrange(i, i+max_length-1):
                    if board[r][j+max_length-1]:
                        return max_length-1
                for c in xrange(j, j+max_length):
                    if board[i+max_length-1][c]:
                        return max_length-1
                max_length += 1
            return max_length-1

        def fill(board, i, j, length, val):
            for r in xrange(i, i+length):
                for c in xrange(j, j+length):
                    board[r][c] = val

        def backtracking(board, count, result):
            if count >= result[0]:  # pruning
                return
            i, j = find_next(board)
            if (i, j) == (-1, -1):  # finished
                result[0] = min(result[0], count)
                return
            max_length = find_max_length(board, i, j)
            for k in reversed(xrange(1, max_length+1)):
                fill(board, i, j, k, 1)
                backtracking(board, count+1, result)
                fill(board, i, j, k, 0)

        if m > n:
            return self.tilingRectangle(m, n)
        board = [[0]*m for _ in xrange(n)]
        result = [float("inf")]
        backtracking(board, 0, result)
        return result[0]
