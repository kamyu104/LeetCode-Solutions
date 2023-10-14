# Time:  O(m * n)
# Space: O(m + n)

# dfs
class Solution(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board
        stk = [click]
        while stk:
            r, c = stk.pop()
            cnt = 0
            adj = []
            for dr in xrange(-1, 2):
                for dc in xrange(-1, 2):
                    if dr == dc == 0:
                        continue
                    nr, nc = r+dr, c+dc
                    if not (0 <= nr < len(board) and 0 <= nc < len(board[r])):
                        continue
                    if board[nr][nc] == 'M':
                        cnt += 1
                    elif board[nr][nc] == 'E':
                        adj.append((nr, nc))
            if cnt:
                board[r][c] = chr(cnt + ord('0'))
                continue
            board[r][c] = 'B'
            for nr, nc in adj:
                board[nr][nc] = ' '
                stk.append((nr, nc))
        return board


# Time:  O(m * n)
# Space: O(m + n)
# dfs
class Solution2(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board
        q = [click]
        while q:
            new_q = []
            for r, c in q:
                cnt = 0
                adj = []
                for dr in xrange(-1, 2):
                    for dc in xrange(-1, 2):
                        if dr == dc == 0:
                            continue
                        nr, nc = r+dr, c+dc
                        if not (0 <= nr < len(board) and 0 <= nc < len(board[r])):
                            continue
                        if board[nr][nc] == 'M':
                            cnt += 1
                        elif board[nr][nc] == 'E':
                            adj.append((nr, nc))
                if cnt:
                    board[r][c] = chr(cnt + ord('0'))
                    continue
                board[r][c] = 'B'
                for nr, nc in adj:
                    board[nr][nc] = ' '
                    new_q.append((nr, nc))
            q = new_q
        return board
