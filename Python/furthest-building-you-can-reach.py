# Time:  O(nlogk)
# Space: O(k)

import heapq


class Solution(object):
    def furthestBuilding(self, heights, bricks, ladders):
        """
        :type heights: List[int]
        :type bricks: int
        :type ladders: int
        :rtype: int
        """
        min_heap = []
        for i in xrange(len(heights)-1):
            diff = heights[i+1]-heights[i]
            if diff > 0:
                heapq.heappush(min_heap, diff)
            if len(min_heap) <= ladders:  # ladders are reserved for largest diffs
                continue
            bricks -= heapq.heappop(min_heap)  # use bricks if ladders are not enough
            if bricks < 0:  # not enough bricks
                return i
        return len(heights)-1
