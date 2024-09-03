# Time:  O(qlogk)
# Space: O(k)

import heapq


# heap
class Solution(object):
    def resultsArray(self, queries, k):
        """
        :type queries: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        result = []
        max_heap = []
        for x, y in queries:
            heapq.heappush(max_heap, -(abs(x)+abs(y)))
            if len(max_heap) == k+1:
                heapq.heappop(max_heap)
            result.append(-max_heap[0] if len(max_heap) == k else -1)
        return result
