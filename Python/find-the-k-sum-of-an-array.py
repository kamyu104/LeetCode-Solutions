# Time:  O(nlogn + klogk)
# Space: O(n + k)

import heapq


# bfs, heap
class Solution(object):
    def kSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        total = sum(x for x in nums if x > 0)
        sorted_vals = sorted(abs(x) for x in nums)
        max_heap = [(-total, 0)]
        for _ in xrange(k):
            result, i = heapq.heappop(max_heap)
            result = -result
            if i == len(sorted_vals):
                continue
            heapq.heappush(max_heap, (-(result-sorted_vals[i]), i+1))
            if i-1 >= 0:
                heapq.heappush(max_heap, (-(result+sorted_vals[i-1]-sorted_vals[i]), i+1))
        return result
