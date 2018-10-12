# Time:  O(1)
# Space: O(1)

import math


class Solution(object):
    def bulbSwitch(self, n):
        """
        type n: int
        rtype: int
        """
        # The number of full squares.
        return int(math.sqrt(n))

