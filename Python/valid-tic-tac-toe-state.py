# Time:  O(1)
# Space: O(1)

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

