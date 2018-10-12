# Time:  O(nlogn)
# Space: O(n)

import heapq


class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        curr = []
        future = sorted(zip(Capital, Profits), reverse=True)
        for _ in xrange(k):
            while future and future[-1][0] <= W:
                heapq.heappush(curr, -future.pop()[1])
            if curr:
                W -= heapq.heappop(curr)
        return W

