# Time:  O(n^2)
# Space: O(n^2)

# On an N x N board, the numbers from 1 to N*N are
# written boustrophedonically starting from the bottom left of the board,
# and alternating direction each row.  For example, for a 6 x 6 board,
# the numbers are written as follows:
#
# 36 35 34 33 32 31
# 25 26 27 28 29 30
# 24 23 22 21 20 19
# 13 14 15 16 17 18
# 12 11 10 09 08 07
# 01 02 03 04 05 06
#
# You start on square 1 of the board (which is always in the last row and first column).
# Each move, starting from square x, consists of the following:
#
# You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6,
# provided this number is <= N*N.
# If S has a snake or ladder, you move to the destination of that snake or ladder.
# Otherwise, you move to S.
# A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.
# The destination of that snake or ladder is board[r][c].
#
# Note that you only take a snake or ladder at most once per move:
# if the destination to a snake or ladder is the start of another snake or ladder,
# you do not continue moving.
#
# Return the least number of moves required to reach square N*N.  If it is not possible, return -1.
#
# Example 1:
#
# Input: [
# [-1,-1,-1,-1,-1,-1],
# [-1,-1,-1,-1,-1,-1],
# [-1,-1,-1,-1,-1,-1],
# [-1,35,-1,-1,13,-1],
# [-1,-1,-1,-1,-1,-1],
# [-1,15,-1,-1,-1,-1]]
# Output: 4
# Explanation: 
# At the beginning, you start at square 1 [at row 5, column 0].
# You decide to move to square 2, and must take the ladder to square 15.
# You then decide to move to square 17 (row 3, column 5), and must take the snake to square 13.
# You then decide to move to square 14, and must take the ladder to square 35.
# You then decide to move to square 36, ending the game.
# It can be shown that you need at least 4 moves to reach the N*N-th square, so the answer is 4.
#
# Note:
# - 2 <= board.length = board[0].length <= 20
# - board[i][j] is between 1 and N*N or is equal to -1.
# - The board square with number 1 has no snake or ladder.
# - The board square with number N*N has no snake or ladder.

class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        def coordinate(n, s):
            a, b = divmod(s-1, n)
            r = n-1-a
            c = b if r%2 != n%2 else n-1-b
            return r, c

        n = len(board)
        lookup = {1: 0}
        q = collections.deque([1])
        while q:
            s = q.popleft()
            if s == n*n:
                return lookup[s]
            for s2 in xrange(s+1, min(s+6, n*n)+1):
                r, c = coordinate(n, s2)
                if board[r][c] != -1:
                    s2 = board[r][c]
                if s2 not in lookup:
                    lookup[s2] = lookup[s]+1
                    q.append(s2)
        return -1
