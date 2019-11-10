# Time:  O(n + m)
# Space: O(n + m)

class Solution(object):
    def oddCells(self, n, m, indices):
        """
        :type n: int
        :type m: int
        :type indices: List[List[int]]
        :rtype: int
        """
        row, col = [0]*n, [0]*m
        for r, c in indices:
            row[r] ^= 1
            col[c] ^= 1
        row_sum, col_sum = sum(row), sum(col)
        return row_sum*m+col_sum*n-2*row_sum*col_sum


# Time:  O(n + m)
# Space: O(n + m)
import collections
import itertools


class Solution2(object):
    def oddCells(self, n, m, indices):
        """
        :type n: int
        :type m: int
        :type indices: List[List[int]]
        :rtype: int
        """
        fn = lambda x: sum(count&1 for count in collections.Counter(x).itervalues())
        row_sum, col_sum = map(fn, itertools.izip(*indices))
        return row_sum*m+col_sum*n-2*row_sum*col_sum
