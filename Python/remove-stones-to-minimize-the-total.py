# Time:  O(n + klogn)
# Space: O(1)

import heapq


class Solution(object):
    def minStoneSum(self, piles, k):
        """
        :type piles: List[int]
        :type k: int
        :rtype: int
        """
        for i, x in enumerate(piles):
            piles[i] = -x
        heapq.heapify(piles)
        for i in xrange(k):
            heapq.heappush(piles, heapq.heappop(piles)//2)
        return -sum(piles)
