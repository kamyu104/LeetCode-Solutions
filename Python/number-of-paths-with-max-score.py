# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def pathsWithMaxScore(self, board):
        """
        :type board: List[str]
        :rtype: List[int]
        """
        MOD = 10**9+7
        directions = [[1, 0], [0, 1], [1, 1]]
        dp = [[[0, 0] for r in xrange(len(board[0])+1)]
              for r in xrange(2)]
        dp[(len(board)-1)%2][len(board[0])-1] = [0, 1]
        for r in reversed(xrange(len(board))):
            for c in reversed(xrange(len(board[0]))):
                if board[r][c] in "XS":
                    continue
                dp[r%2][c] = [0, 0]
                for dr, dc in directions:
                    if dp[r%2][c][0] < dp[(r+dr)%2][c+dc][0]:
                        dp[r%2][c] = dp[(r+dr)%2][c+dc][:]
                    elif dp[r%2][c][0] == dp[(r+dr)%2][c+dc][0]:
                        dp[r%2][c][1] = (dp[r%2][c][1]+dp[(r+dr)%2][c+dc][1]) % MOD
                if dp[r%2][c][1] and board[r][c] != 'E':
                    dp[r%2][c][0] += int(board[r][c])
        return dp[0][0]
