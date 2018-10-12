# Time:  O((logn)^2) = O(1) due to n is a 32-bit number
# Space: O(logn) = O(1)

import collections


class Solution(object):
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        count = collections.Counter(str(N))
        return any(count == collections.Counter(str(1 << i))
                   for i in xrange(31))

