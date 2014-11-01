# Time:  ((9!)^9)
# Space: (1)
#
# Write a program to solve a Sudoku puzzle by filling the empty cells.
# 
# Empty cells are indicated by the character '.'.
# 
# You may assume that there will be only one unique solution.
#

class Solution:
    # @param board, a 9x9 2D array
    # Solve the Sudoku by modifying the input board in-place.
    # Do not return any value.
    def solveSudoku(self, board):
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if(board[i][j] == '.'):
                    for k in xrange(9):
                        board[i][j] = chr(ord('1') + k)
                        if self.isValid(board, i, j) and self.solveSudoku(board):
                            return True
                        board[i][j] = '.'
                    return False
        return True
    
    def isValid(self, board, x, y):
        for i in xrange(9):
            if i != x and board[i][y] == board[x][y]:
                return False
            
        for j in xrange(9):
            if j != y and board[x][j] == board[x][y]:
                return False
            
        i = 3 * (x / 3)
        while i < 3 * (x / 3 + 1):
            j = 3 * (y / 3)
            while j < 3 * (y / 3 + 1):
                if (i != x or j != y) and board[i][j] == board[x][y]:
                    return False
                j += 1
            i += 1
            
        return True


if __name__ == "__main__":
    board = [['5', '3', '.', '.', '7', '.', '.', '.', '.'],
             ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
             ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
             ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
             ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
             ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
             ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
             ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
             ['.', '.', '.', '.', '8', '.', '.', '7', '9']]
    print Solution().solveSudoku(board)
