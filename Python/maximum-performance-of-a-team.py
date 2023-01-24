# Time:  O(nlogn)
# Space: O(n)

import itertools
import heapq


class Solution(object):
    def maxPerformance(self, n, speed, efficiency, k):
        """
        :type n: int
        :type speed: List[int]
        :type efficiency: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        result, s_sum = 0, 0
        min_heap = []
        for e, s in sorted(itertools.izip(efficiency, speed), reverse=True):
            s_sum += s
            heapq.heappush(min_heap, s)
            if len(min_heap) > k:
                s_sum -= heapq.heappop(min_heap)
            result = max(result, s_sum*e)
        return result % MOD
