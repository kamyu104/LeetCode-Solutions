# Time:  O(m * n)
# Space: O(m + n)

import collections


class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        q = collections.deque()

        for i in xrange(len(board)):
            if board[i][0] == 'O':
                board[i][0] = 'V'
                q.append((i, 0))
            if board[i][len(board[0]) - 1] == 'O':
                board[i][len(board[0]) - 1] = 'V'
                q.append((i, len(board[0]) - 1))

        for i in xrange(1, len(board[0])-1):
            if board[0][i] == 'O':
                board[0][i] = 'V'
                q.append((0, i))
            if board[len(board) - 1][i] == 'O':
                board[len(board) - 1][i] = 'V'
                q.append((len(board) - 1, i))

        while q:
            i, j = q.popleft()
            for x, y in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                if 0 <= x < len(board) and 0 <= y < len(board[0]) and \
                   board[x][y] == 'O':
                    board[x][y] = 'V'
                    q.append((x, y))

        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if board[i][j] != 'V':
                    board[i][j] = 'X'
                else:
                    board[i][j] = 'O'
