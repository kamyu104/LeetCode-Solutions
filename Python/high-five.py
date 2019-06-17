# Time:  O(nlogn)
# Space: O(n)

import collections
import heapq


class Solution(object):
    def highFive(self, items):
        """
        :type items: List[List[int]]
        :rtype: List[List[int]]
        """
        min_heaps = collections.defaultdict(list)
        for i, val in items:
            heapq.heappush(min_heaps[i], val)
            if len(min_heaps[i]) > 5:
                heapq.heappop(min_heaps[i])
        return [[i, sum(min_heaps[i]) // len(min_heaps[i])] for i in sorted(min_heaps)]
