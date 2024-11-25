# Time:  O(n + qlogq)
# Space: O(q)

import heapq


# sort, heap, greedy
class Solution(object):
    def maxRemoval(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        queries.sort(reverse=True)
        max_heap, min_heap = [], []
        for i in xrange(len(nums)):
            while queries and queries[-1][0] <= i:
                heapq.heappush(max_heap, -queries.pop()[1])
            while min_heap and min_heap[0] < i:
                heapq.heappop(min_heap)
            while len(min_heap) < nums[i]:
                if not max_heap or -max_heap[0] < i:
                    return -1
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
        return len(max_heap)
