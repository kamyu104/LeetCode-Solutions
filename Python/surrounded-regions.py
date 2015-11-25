# Time:  O(m * n)
# Space: O(m + n)
#
# Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
# 
# A region is captured by flipping all 'O's into 'X's in that surrounded region.
# 
# For example,
# X X X X
# X O O X
# X X O X
# X O X X
# After running your function, the board should be:
# 
# X X X X
# X X X X
# X X X X
# X O X X
#

class Solution:
    # @param board, a 2D array
    # Capture all regions by modifying the input board in-place.
    # Do not return any value.
    def solve(self, board):
        if not board:
            return
        q = collections.deque([])
        
        for i in xrange(len(board)):
            q.append((i, 0))
            q.append((i, len(board[0]) - 1))
            
        for i in xrange(len(board[0])):
            q.append((0, i))
            q.append((len(board) - 1, i))
            
        while q:
            i, j = q.popleft()
            if board[i][j] in ['O', 'V']:
                board[i][j] = 'V'
                for x, y in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                    if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == 'O':
                        board[x][y] = 'V'
                        q.append((x, y))
                        
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if board[i][j] != 'V':
                    board[i][j] = 'X'
                else:
                    board[i][j] = 'O'

if __name__ == "__main__":
    board = [['X', 'X', 'X', 'X'],
             ['X', 'O', 'O', 'X'],
             ['X', 'X', 'O', 'X'],
             ['X', 'O', 'X', 'X']]
    Solution().solve(board)
    print board
