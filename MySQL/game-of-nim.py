# Time:  O(n)
# Space: O(1)

import operator


class Solution(object):
    def nimGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        return reduce(operator.xor, piles, 0)
