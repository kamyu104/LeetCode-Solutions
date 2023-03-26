# Time:  O(nlogn)
# Space: O(n)

import heapq


# prefix sum, greedy, heap
class Solution(object):
    def makePrefSumNonNegative(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = prefix = 0
        min_heap = []
        for x in nums:
            heapq.heappush(min_heap, x)
            prefix += x
            if prefix < 0:
                prefix -= heapq.heappop(min_heap)
                result += 1
        return result
