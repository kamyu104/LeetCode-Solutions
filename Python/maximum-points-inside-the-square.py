# Time:  O(n + 26)
# Space: O(26)

import itertools


# hash table
class Solution(object):
    def maxPointsInsideSquare(self, points, s):
        """
        :type points: List[List[int]]
        :type s: str
        :rtype: int
        """
        INF = float("inf")
        lookup = [INF for _ in xrange(26)]
        d = INF
        for c, (x, y) in itertools.izip(s, points):
            k = ord(c)-ord('a')
            mn2 = max(abs(x), abs(y))
            if mn2 < lookup[k]:
                mn2, lookup[k] = lookup[k], mn2
            d = min(d, mn2)
        return sum(mn1 < d for mn1 in lookup)
