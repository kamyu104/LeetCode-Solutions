# Time:  O(m * n)
# Space: O(m + n)

import itertools


class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        rows = map(min, matrix)
        cols = map(max, itertools.izip(*matrix))
        return [cell for i, row in enumerate(matrix)
                     for j, cell in enumerate(row) if rows[i] == cols[j]]

    
# Time:  O(m * n)
# Space: O(m + n)
import itertools


class Solution2(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        return list(set(map(min, matrix)) &
                    set(map(max, itertools.izip(*matrix))))
 
