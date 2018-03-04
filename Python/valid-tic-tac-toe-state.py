# Time:  O(1)
# Space: O(1)

# A Tic-Tac-Toe board is given as a string array board. Return True
# if and only if it is possible to reach this board position
# during the course of a valid tic-tac-toe game.
#
# The board is a 3 x 3 array, and consists of characters " ", "X", 
# and "O".  The " " character represents an empty square.
#
# Here are the rules of Tic-Tac-Toe:
# - Players take turns placing characters into empty squares (" ").
# - The first player always places "X" characters, while the second player always places "O" characters.
# - "X" and "O" characters are always placed into empty squares, never filled ones.
# - The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
# - The game also ends if all squares are non-empty.
# - No more moves can be played if the game is over.
#
# Example 1:
# Input: board = ["O  ", "   ", "   "]
# Output: false
# Explanation: The first player always plays "X".
#
# Example 2:
# Input: board = ["XOX", " X ", "   "]
# Output: false
# Explanation: Players take turns making moves.
#
# Example 3:
# Input: board = ["XXX", "   ", "OOO"]
# Output: false
#
# Example 4:
# Input: board = ["XOX", "O O", "XOX"]
# Output: true
#
# Note:
# - board is a length-3 array of strings, where each string board[i] has length 3.
# - Each board[i][j] is a character in the set {" ", "X", "O"}.

class Solution(object):
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        def win(board, player):
            for i in xrange(3):
                if all(board[i][j] == player for j in xrange(3)):
                    return True
                if all(board[j][i] == player for j in xrange(3)):
                    return True

            return (player == board[1][1] == board[0][0] == board[2][2] or \
                    player == board[1][1] == board[0][2] == board[2][0])
        
        FIRST, SECOND = ('X', 'O')
        x_count = sum(row.count(FIRST) for row in board)
        o_count = sum(row.count(SECOND) for row in board)
        if o_count not in {x_count-1, x_count}: return False
        if win(board, FIRST) and x_count-1 != o_count: return False
        if win(board, SECOND) and x_count != o_count: return False

        return True
