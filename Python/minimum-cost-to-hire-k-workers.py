# Time:   O(nlogn)
# Space : O(n)

import itertools
import heapq


class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type K: int
        :rtype: float
        """
        workers = [[float(w)/q, q] for w, q in itertools.izip(wage, quality)]
        workers.sort()
        result = float("inf")
        qsum = 0
        max_heap = []
        for r, q in workers:
            qsum += q
            heapq.heappush(max_heap, -q)
            if len(max_heap) > K:
                qsum -= -heapq.heappop(max_heap)
            if len(max_heap) == K:
                result = min(result, qsum*r)
        return result

