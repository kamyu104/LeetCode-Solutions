# Time:  O(nlogn)
# Space: O(n)

import itertools
import heapq


# greedy, heap
class Solution(object):
    def maxScore(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        result = curr = 0
        min_heap = []
        for a, b in sorted(itertools.izip(nums1, nums2), key=lambda x: x[1],  reverse=True):
            curr += a
            heapq.heappush(min_heap, a)
            if len(min_heap) > k:
                curr -= heapq.heappop(min_heap)
            if len(min_heap) == k:
                result = max(result, curr*b)
        return result
