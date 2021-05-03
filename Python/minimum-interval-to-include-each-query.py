# Time:  O(nlogn + klogk + klogn)
# space: O(n + k)

import heapq


class Solution(object):
    def minInterval(self, intervals, queries):
        """
        :type intervals: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        intervals.sort()
        sorted_queries = [(q, i) for i, q in enumerate(queries)]
        sorted_queries.sort()
        min_heap = []
        i = 0
        result =[-1]*len(queries)
        for q, idx in sorted_queries:
            while i != len(intervals) and intervals[i][0] <= q:
                if intervals[i][1] >= q:
                    heapq.heappush(min_heap, [intervals[i][1]-intervals[i][0]+1, intervals[i][1]])
                i += 1
            while min_heap and min_heap[0][1] < q:
                heapq.heappop(min_heap)
            result[idx] = min_heap[0][0] if min_heap else -1
        return result
