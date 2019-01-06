# Time:  O((logn)^2), n is the bound
# Space: O(r), r is the size of the result

import math


class Solution(object):
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        result = set()
        log_x = int(math.floor(math.log(bound) / math.log(x)))+1 if x != 1 else 1
        log_y = int(math.floor(math.log(bound) / math.log(y)))+1 if y != 1 else 1
        pow_x = 1
        for i in xrange(log_x):
            pow_y = 1
            for j in xrange(log_y):
                val = pow_x + pow_y
                if val <= bound:
                    result.add(val)
                pow_y *= y
            pow_x *= x
        return list(result)
