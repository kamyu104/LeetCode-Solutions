# Time:  O(logn * log(logn))
# Space: O(1)

import math


class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        num = int(n)
        max_len = int(math.log(num,2))
        for l in xrange(max_len, 1, -1):
            b = int(num ** (l**-1))
            if (b**(l+1)-1) // (b-1) == num:
                return str(b)
        return str(num-1)

