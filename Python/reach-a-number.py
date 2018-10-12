# Time:  O(logn)
# Space: O(1)

import math


class Solution(object):
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        target = abs(target)
        k = int(math.ceil((-1+math.sqrt(1+8*target))/2))
        target -= k*(k+1)/2
        return k if target%2 == 0 else k+1+k%2


# Time:  O(sqrt(n))
# Space: O(1)
class Solution2(object):
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        target = abs(target)
        k = 0
        while target > 0:
            k += 1
            target -= k
        return k if target%2 == 0 else k+1+k%2

