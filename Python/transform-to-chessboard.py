# Time:  O(n^2)
# Space: O(n^2), used by Counter, this could be reduced to O(n) by skipping invalid input

import collections
import itertools


class Solution(object):
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        N = len(board)
        result = 0
        for count in (collections.Counter(map(tuple, board)), \
                      collections.Counter(itertools.izip(*board))):
            if len(count) != 2 or \
               sorted(count.values()) != [N/2, (N+1)/2]:
                return -1

            seq1, seq2 = count
            if any(x == y for x, y in itertools.izip(seq1, seq2)):
                return -1
            begins = [int(seq1.count(1) * 2 > N)] if N%2 else [0, 1]
            result += min(sum(int(i%2 != v) for i, v in enumerate(seq1, begin)) \
                          for begin in begins) / 2
        return result

