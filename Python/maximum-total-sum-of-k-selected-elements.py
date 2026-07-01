# Time:  O(nlogk)
# Space: O(k)

import heapq


# heap, greedy
class Solution(object):
    def maxSum(self, nums, k, mul):
        """
        :type nums: List[int]
        :type k: int
        :type mul: int
        :rtype: int
        """
        min_heap = []
        for x in nums:
            heapq.heappush(min_heap, x)
            if len(min_heap) == k + 1:
                heapq.heappop(min_heap)
        result = 0
        while min_heap:
            x = heapq.heappop(min_heap)
            result += x*max(mul-len(min_heap), 1)
        return result


# Time:  O(nlogk)
# Space: O(k)
import heapq


# heap, greedy
class Solution2(object):
    def maxSum(self, nums, k, mul):
        """
        :type nums: List[int]
        :type k: int
        :type mul: int
        :rtype: int
        """
        return sum(x*max(mul-i, 1)for i, x in enumerate(heapq.nlargest(k, nums)))


# Time:  O(nlogn)
# Space: O(1)
# sort, greedy
class Solution3(object):
    def maxSum(self, nums, k, mul):
        """
        :type nums: List[int]
        :type k: int
        :type mul: int
        :rtype: int
        """
        nums.sort(reverse=True)
        return sum(nums[i]*max(mul-i, 1)for i in xrange(k))
