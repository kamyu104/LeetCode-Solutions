# Time:  O(nlogn)
# Space: O(n)

import heapq


class Solution(object):
    def eatenApples(self, apples, days):
        """
        :type apples: List[int]
        :type days: List[int]
        :rtype: int
        """
        min_heap = []
        result = i = 0
        while i < len(apples) or min_heap:
            if i < len(apples) and apples[i] > 0:
                heapq.heappush(min_heap, [i+days[i], i])
            while min_heap and (min_heap[0][0] <= i or apples[min_heap[0][1]] == 0):
                heapq.heappop(min_heap)
            if min_heap:
                apples[min_heap[0][1]] -= 1
                result += 1
            i += 1
        return result
