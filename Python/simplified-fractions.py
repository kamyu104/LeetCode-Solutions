# Time:  O(n^2 * logn)
# Space: O(n^2)

import fractions

class Solution(object):
    def simplifiedFractions(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        lookup = set()
        for b in xrange(1, n+1):
            for a in xrange(1, b):
                g = fractions.gcd(a, b)
                lookup.add((a//g, b//g))
        return map(lambda x: "{}/{}".format(*x), lookup)
