# Time:  O(nlogn)
# Space: O(1)

import itertools


class Solution(object):
    def maxCoins(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        piles.sort()
        return sum(itertools.islice(piles, len(piles)//3, len(piles), 2))
