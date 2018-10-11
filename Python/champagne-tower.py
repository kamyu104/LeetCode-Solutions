# Time:  O(n^2) = O(1), since n is at most 99
# Space: O(n) = O(1)

class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        """
        :type poured: int
        :type query_row: int
        :type query_glass: int
        :rtype: float
        """
        result = [poured] + [0] * query_row
        for i in xrange(1, query_row+1):
            for j in reversed(xrange(i+1)):
                result[j] = max(result[j]-1, 0)/2.0 + \
                            max(result[j-1]-1, 0)/2.0
        return min(result[query_glass], 1)

