# Time:  O(klogn)
# Space: O(n)

import heapq


# heap
class Solution(object):
    def pickGifts(self, gifts, k):
        """
        :type gifts: List[int]
        :type k: int
        :rtype: int
        """
        max_heap = [-x for x in gifts]
        heapq.heapify(max_heap)
        for _ in xrange(k):
            x = heapq.heappop(max_heap)
            heapq.heappush(max_heap, -int((-x)**0.5))
        return -sum(max_heap)
