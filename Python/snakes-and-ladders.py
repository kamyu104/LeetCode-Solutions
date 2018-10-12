# Time:  O(n^2)
# Space: O(n^2)

import collections


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

