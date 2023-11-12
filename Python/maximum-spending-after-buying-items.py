# Time:  O(m * n * logm)
# Space: O(m)

import heapq


# greedy, heap
class Solution(object):
    def maxSpending(self, values):
        """
        :type values: List[List[int]]
        :rtype: int
        """
        m, n = len(values), len(values[0])
        min_heap = [(values[i].pop(), i) for i in xrange(m)]
        heapq.heapify(min_heap)
        result = 0
        for d in xrange(1, m*n+1):
            x, i = heapq.heappop(min_heap)
            result += x*d
            if values[i]:
                heapq.heappush(min_heap, (values[i].pop(), i))
        return result
