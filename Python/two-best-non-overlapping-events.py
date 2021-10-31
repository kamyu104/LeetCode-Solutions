# Time:  O(nlogn)
# Space: O(n)

import heapq


class Solution(object):
    def maxTwoEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events.sort()
        result = best = 0
        min_heap = []
        for left, right, v in events:
            heapq.heappush(min_heap, (right, v))
            while min_heap and min_heap[0][0] < left:
                best = max(best, heapq.heappop(min_heap)[1])
            result = max(result, best+v)
        return result
