# Time:  O(nlogn)
# Space: O(n)

import heapq


class Solution(object):
    def minBuildTime(self, blocks, split):
        """
        :type blocks: List[int]
        :type split: int
        :rtype: int
        """
        heapq.heapify(blocks)
        while len(blocks) != 1:
            x, y = heapq.heappop(blocks), heapq.heappop(blocks)
            heapq.heappush(blocks, y+split)
        return heapq.heappop(blocks)
