# Time:  O(m * n)
# Space: O(1)

# Given an 2D board, count how many different battleships are in it.
# The battleships are represented with 'X's, empty slots are represented with '.'s.
# You may assume the following rules:
#
# You receive a valid board, made of only battleships or empty slots.
# Battleships can only be placed horizontally or vertically. In other words,
# they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column),
# where N can be of any size.
# At least one horizontal or vertical cell separates between two battleships - 
# there are no adjacent battleships.
#
# Example:
# X..X
# ...X
# ...X
# In the above board there are 2 battleships.
# Invalid Example:
# ...X
# XXXX
# ...X
# This is not a valid board - as battleships will always have a cell separating between them.
# Your algorithm should not modify the value of the board.

class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        if not board or not board[0]:
            return 0

        cnt = 0
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                cnt += int(board[i][j] == 'X' and \
                       (i == 0 or board[i - 1][j] != 'X') and \
                       (j == 0 or board[i][j - 1] != 'X'))
        return cnt
