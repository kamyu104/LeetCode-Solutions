# Time:  O(m * n)
# Space: O(m * n)

import collections


class Solution(object):
    def maxEqualRowsAfterFlips(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        count = collections.Counter(tuple(x^row[0] for x in row)
                                          for row in matrix)
        return max(count.itervalues())
