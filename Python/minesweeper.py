# Time:  O(m * n)
# Space: O(m + n)

import collections


class Solution(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        q = collections.deque([click])
        while q:
            row, col = q.popleft()
            if board[row][col] == 'M':
                board[row][col] = 'X'
            else:
                count = 0
                for i in xrange(-1, 2):
                    for j in xrange(-1, 2):
                        if i == 0 and j == 0:
                            continue
                        r, c = row + i, col + j
                        if not (0 <= r < len(board)) or not (0 <= c < len(board[r])):
                            continue
                        if board[r][c] == 'M' or board[r][c] == 'X':
                            count += 1

                if count:
                    board[row][col] = chr(count + ord('0'))
                else:
                    board[row][col] = 'B'
                    for i in xrange(-1, 2):
                        for j in xrange(-1, 2):
                            if i == 0 and j == 0:
                                continue
                            r, c = row + i, col + j
                            if not (0 <= r < len(board)) or not (0 <= c < len(board[r])):
                                continue
                            if board[r][c] == 'E':
                                q.append((r, c))
                                board[r][c] = ' '

        return board


# Time:  O(m * n)
# Space: O(m * n)
class Solution2(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        row, col = click[0], click[1]
        if board[row][col] == 'M':
            board[row][col] = 'X'
        else:
            count = 0
            for i in xrange(-1, 2):
                for j in xrange(-1, 2):
                    if i == 0 and j == 0:
                        continue
                    r, c = row + i, col + j
                    if not (0 <= r < len(board)) or not (0 <= c < len(board[r])):
                        continue
                    if board[r][c] == 'M' or board[r][c] == 'X':
                        count += 1

            if count:
                board[row][col] = chr(count + ord('0'))
            else:
                board[row][col] = 'B'
                for i in xrange(-1, 2):
                    for j in xrange(-1, 2):
                        if i == 0 and j == 0:
                            continue
                        r, c = row + i, col + j
                        if not (0 <= r < len(board)) or not (0 <= c < len(board[r])):
                            continue
                        if board[r][c] == 'E':
                            self.updateBoard(board, (r, c))

        return board

