# Time:  O(nlogn)
# Space: O(n)

import heapq


class Solution(object):
    def connectSticks(self, sticks):
        """
        :type sticks: List[int]
        :rtype: int
        """
        heapq.heapify(sticks)
        result = 0
        while len(sticks) > 1:
            x, y = heapq.heappop(sticks), heapq.heappop(sticks)
            result += x+y
            heapq.heappush(sticks, x+y)
        return result
