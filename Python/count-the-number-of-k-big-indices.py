# Time:  O(nlogn)
# Space: O(n)

import heapq


# heap
class Solution(object):
    def kBigIndices(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        right = [False]*len(nums)
        min_heap1 = []
        for i in reversed(xrange(len(nums))):
            if len(min_heap1) == k and nums[i] > -min_heap1[0]:
                right[i] = True
            heapq.heappush(min_heap1, -nums[i])
            if len(min_heap1) == k+1:
                heapq.heappop(min_heap1)
        result = 0
        min_heap2 = []
        for i in xrange(len(nums)):
            if len(min_heap2) == k and nums[i] > -min_heap2[0] and right[i]:
                result += 1
            heapq.heappush(min_heap2, -nums[i])
            if len(min_heap2) == k+1:
                heapq.heappop(min_heap2)
        return result


# Time:  O(nlogn)
# Space: O(n)
from sortedcontainers import SortedList


# sorted list
class Solution2(object):
    def kBigIndices(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sl1, sl2 = SortedList(), SortedList(nums)
        result = 0
        for x in nums:
            sl2.remove(x)
            if sl1.bisect_left(x) >= k and sl2.bisect_left(x) >= k:
                result += 1
            sl1.add(x)
        return result
