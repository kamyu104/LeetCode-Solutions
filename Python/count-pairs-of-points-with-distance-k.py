# Time:  O(n * k)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def countPairs(self, coordinates, k):
        """
        :type coordinates: List[List[int]]
        :type k: int
        :rtype: int
        """
        result = 0
        cnt = collections.Counter()
        for x, y in coordinates:
            for i in xrange(k+1):
                result += cnt.get((x^i, y^(k-i)), 0)
            cnt[(x, y)] += 1
        return result
