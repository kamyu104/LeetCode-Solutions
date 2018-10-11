# Time:  O((R * C)^2)
# Space: O(1)

class Solution(object):
    def candyCrush(self, board):
        """
        :type board: List[List[int]]
        :rtype: List[List[int]]
        """
        R, C = len(board), len(board[0])
        changed = True

        while changed:
            changed = False

            for r in xrange(R):
                for c in xrange(C-2):
                    if abs(board[r][c]) == abs(board[r][c+1]) == abs(board[r][c+2]) != 0:
                        board[r][c] = board[r][c+1] = board[r][c+2] = -abs(board[r][c])
                        changed = True

            for r in xrange(R-2):
                for c in xrange(C):
                    if abs(board[r][c]) == abs(board[r+1][c]) == abs(board[r+2][c]) != 0:
                        board[r][c] = board[r+1][c] = board[r+2][c] = -abs(board[r][c])
                        changed = True

            for c in xrange(C):
                i = R-1
                for r in reversed(xrange(R)):
                    if board[r][c] > 0:
                        board[i][c] = board[r][c]
                        i -= 1
                for r in reversed(xrange(i+1)):
                    board[r][c] = 0

        return board

